#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>

#include "ThLeftNormalForm.h"
#include "braid_group.h"


int main() {
  typedef ThLeftNormalForm NF;

  string filename = "raw_braid.txt";
  std::ifstream is(filename);
  std::istream_iterator<int> start(is), end;
  std::vector<int> braid_list(start, end);

  int N = 0;
  for (auto& i : braid_list) {
    if(N < i) {N = i;}
  }
  N += 1;

  Word w(braid_list);

  crag::braidgroup::BraidGroup B( N );

  cout << "braid loaded" << endl;

  NF nf = NF( B , w );

  cout << "normal form computed" << endl;

  {
  string ofilename = "obfuscated_LNF.txt";
  std::ofstream os(ofilename);
  os << nf;
  }


  Word w2 = nf.getWord();

  cout << "normal form braid computed" << endl;

  {
  string ofilename = "obfuscated_braid.txt";
  std::ofstream os(ofilename);

  auto v = w2.toVector();
  for (int i: v){
      os << i << ' ';
  }
  }


}
