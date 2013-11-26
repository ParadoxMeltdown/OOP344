#include <iostream>

//Header
using namespace std;
class bits {
  signed int _val;
public:
  bits(int val);
  void setA(unsigned int& val, signed int pos, bool toval);
  int getVal();
  bool operator[](int toval);
};

//Source
bits::bits(int val) {
  _val = val;
}
void bits::setA(unsigned int& val, signed int pos, bool toval) {
    toval? (val = val | (1<<(pos-1))) : (val = val & ~(1<<(pos-1)));
}
bool bits::operator[](int bitNo) {
  return (_val & (1 << (bitNo))) != 0; 
}
ostream& operator<<(ostream& os, bits src) {
  for(int i = sizeof(int)*8; i--; i > 0) {
    os << src[i];
    if((i % 4) == 0) {
      os << ' ';
    }
  }
  return os;
}
int main(){
  bits B(0xf0f0f0f0);
  cout<<B[6]<<endl;
  cout<<B<<endl;
  return 0;
}