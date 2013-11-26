#ifndef __JO_BIT_H__
#define __JO_BIT_H__

namespace Jrona {
  class bits {
    signed int _val;
  public:
    bits(int val);
    void set(signed int pos, bool toval);
    void set(signed int pos, char* newVal);
    int getVal();
    bool operator[](int bitNo);
  };
}

#endif