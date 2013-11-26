#include <iostream>
#include <cstring>
#include "Bit.h"
using namespace std;

namespace Jrona {
  //Constructor
  bits::bits(int val) {
    _val = val;
  }

  //single position set method
  void bits::set(signed int pos, bool toval) {
      toval? (_val = _val | (1<<(pos-1))) : (_val = _val & ~(1<<(pos-1)));
  }

  //multiple position set method
  void bits::set(signed int pos, char* newVal) {
    //Checks to see if the values will fit an integer
    if((pos + strlen(newVal) - 1) < sizeof(int)*8) {
      //Loop that sets every single bits
      for(int i = 0, n = strlen(newVal)-1; i++, n--; i <= strlen(newVal)) {
        set(n + pos, (newVal[i] - '0'));
      }
    }
    else {
      cout << "Value too big" << endl;
    }
  }
  //A copy of the isOn method provided but edited for the class
  bool bits::operator[](int bitNo) {
    return (_val & (1 << (bitNo))) != 0; 
  }

  //A copy of the prntBits method but updated to add spaces
  //with every 4th number. Can only handle up to the size of an Int
  ostream& operator<<(ostream& os, bits src) {
    for(int i = sizeof(int)*8; i--; i > 0) {
      os << src[i];
      //Condition to add the spaces
      if(!(i % 4)) {
        os << ' ';
      }
    }
    return os;
  }
}

using namespace Jrona;
int main(){
  //Creates bits
  bits B(0xf0f0f0f0);
  cout<<"Testing operator[]"<<endl;
  cout<<B[6]<<endl;
  cout<<"Testing operator<< with the bits class"<<endl;
  cout<<B<<endl;
  cout<<"Testing multiple value set function"<<endl;
  B.set(5, "01010100000101011010101010101010100100101");
  cout<<B<<endl;
  return 0;
}