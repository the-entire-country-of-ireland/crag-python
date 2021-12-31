// make -j && clear && ./BraidGroup/bin/test_deh_form

#include "BKLLeftNormalForm.h"
#include "braid_group.h"
#include "Word.h"

#include "list"
#include <vector>

#include "iostream"
using namespace std;


//---------------------------------------------------------------------------//
//------------------------- Examples: Word ----------------------------------//
//---------------------------------------------------------------------------//

void test_normal_form() {
  int N = 14;
  crag::braidgroup::BraidGroup B( N );

  vector<int> braid_list {8, 7, 9, 8, 10, 9, 11, 10, 12, 13, 13, 12, -10, -11, -9, -10, -8, -9, -7, -8, 10, 9, 11, 10, 12, 13, 13, 12, -10, -11, -9, -10, 2, 1, 3, 2, 4, 3, 5, 4, 6, 5, 7, 6, 8, 7, 9, 8, 10, 9, 11, 10, 12, 13, 13, 12, -10, -11, -9, -10, -8, -9, -7, -8, -6, -7, -5, -6, -4, -5, -3, -4, -2, -3, -1, -2, 12, 13, 13, 12, 6, 5, 7, 6, 8, 7, 9, 8, 10, 9, 11, 10, 12, 13, 13, 12, -10, -11, -9, -10, -8, -9, -7, -8, -6, -7, -5, -6, 10, 9, 11, 10, -12, -13, -13, -12, -10, -11, -9, -10, 4, 3, 5, 4, 6, 5, 7, 6, 8, 7, 9, 8, 10, 9, 11, 10, 12, 13, 13, 12, -10, -11, -9, -10, -8, -9, -7, -8, -6, -7, -5, -6, -4, -5, -3, -4, -12, -13, -13, -12, 4, 3, 5, 4, 6, 5, 7, 6, 8, 7, 9, 8, 10, 9, 11, 10, 12, 13, 13, 12, -10, -11, -9, -10, -8, -9, -7, -8, -6, -7, -5, -6, -4, -5, -3, -4};

  Word w = Word(1) * Word(-1);
  for (auto& i : braid_list) {
    w = w * Word(i);
  }

  cout << "w = " << w << endl;

  cout << "ireland done" << endl ;

  // BKLLeftNormalForm BLK(B, w);


}

int main( )
{
  test_normal_form();

  // Fix the number of strands and the length of a braid word
  int N = 5;
  int L = 20;
  
  
  //& Braid word : How do I generate a random freely reduced braid word from B_N of length L?
  Word w1 = Word::randomWord( N-1 , L );
  Word w2 = Word::randomWord( N-1 , L );
  
  Word w = Word(2) * Word(-1);
  cout << "w1 = " << w1 << endl;

  cout << endl << "w = " << w << endl;


  //& Braid word : How do I invert a braid word?
  Word u1 = -w1;
  

  //& Braid word : How do I multiply braid words?
  Word p = w1 * w2 * u1 * -w2;    // here p = [w1,w2]; the result of the product is reduced whenever each factor is
  
  
  return 0;
}

