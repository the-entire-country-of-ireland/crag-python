#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>
#include "time.h"
#include "stdlib.h"

#include "ThLeftNormalForm.h"
#include "Permutation.h"
#include "braid_group.h"

#include <boost/python.hpp>
#include <stdexcept>


vector< int> pythonListToCppIntVector(const boost::python::list &pylist) {
  vector< int> res;
  for(unsigned int i = 0; i < len(pylist); i++){
    res.push_back(boost::python::extract<int>(pylist[i]));
  }
  return res;
}

std::list<Permutation> pythonListToCppPermutationList(const boost::python::list &pylist) {
  std::list<Permutation> res;
  for(unsigned int i = 0; i < len(pylist); i++){
    auto pylist_i = boost::python::extract<boost::python::list>(pylist[i]);
    auto v = pythonListToCppIntVector(pylist_i);
    Permutation p(v);
    res.push_back(p);
  }
  return res;
}

boost::python::list cppIntVectorToPythonList(const vector<int> &v) {
  boost::python::list vec;
  for (auto c : v){
      vec.append(c);
  }
  return vec;
}



class LNF{
typedef ThLeftNormalForm NF;
public:
  int n;
  NF nf;

  LNF(const LNF &lnf) {
    n = lnf.n;
    nf = lnf.nf;
  }

  LNF(int _n, int _e, const boost::python::list &pylist) :
    n(_n)  {
    auto d = pythonListToCppPermutationList(pylist);
    nf = NF(n, _e, d);
  }

  LNF(Word _w, int _n) : n(_n) {
    crag::braidgroup::BraidGroup B( n );
    nf = NF( B , _w );
  }

  Word getBraid() {
    return nf.getWord();
  }

  boost::python::list getPermutations() {
    boost::python::list vec;
    
    const std::list< Permutation >& decomposition = nf.getDecomposition();

    for (auto p : decomposition){
      auto x = p.getVector();
      auto y = cppIntVectorToPythonList(x);
      vec.append(y);
    }
    return vec;
  }

  int getHalfTwistExponent() {
    return nf.getPower();
  }

  // Invert a normal form.  
  LNF operator - ( ) const {
    LNF lnf(*this);
    lnf.nf = -lnf.nf;
    return lnf;
  }

  //! Multiply two normal forms
  LNF operator * ( const LNF& rep ) const {
    if(this->n != rep.n) {throw std::runtime_error("number of strands of the two braids do not match");}
    LNF lnf(*this);
    lnf.nf *= rep.nf;
    return lnf;
  }

  //! Multiply a normal form by the other on the right
  LNF& operator *= ( const LNF& rep ) {
    if(this->n != rep.n) {throw std::runtime_error("number of strands of the two braids do not match");}
    this->nf *= rep.nf;
    return *this;
  }
};


Word createBraid(const boost::python::list &pylist) {
  std::vector<int> braid_list = pythonListToCppIntVector(pylist);
  Word w(braid_list);
  return w;
}

boost::python::list WordToVector(Word w) {
  std::vector<int> v = w.toVector();
  return cppIntVectorToPythonList(v);
}


  std::string WordToString(Word w) {
  std::stringstream ss;
  ss << w;
  auto s = ss.str();
  return s;
}


BOOST_PYTHON_MODULE(fast_braids)
{
  using namespace boost::python;

  Py_Initialize();

  class_<Word>("Word")
    .def("__str__", WordToString)    
    .def("toVector", WordToVector)
    .def(-self)
    .def(self * self)
    .def(self * other<Word>())
    .def(other<Word>() * self)
    .def(self *= self)
    .def(self *= other<Word>())
    ;

  class_<LNF>("LNF", init<Word, int>())
    .def(init<int, int, boost::python::list>())
    .def("getBraid", &LNF::getBraid)
    .def("getPermutations", &LNF::getPermutations)
    .def("getHalfTwistExponent", &LNF::getHalfTwistExponent)
    .def(-self)
    .def(self * self)
    .def(self * other<LNF>())
    .def(other<LNF>() * self)
    .def(self *= self)
    .def(self *= other<LNF>())
    ;

  def("createBraid", createBraid);
}
