/** \file L1Cache_State.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "L1Cache_State.h"

ostream& operator<<(ostream& out, const L1Cache_State& obj)
{
  out << L1Cache_State_to_string(obj);
  out << flush;
  return out;
}

string L1Cache_State_to_string(const L1Cache_State& obj)
{
  switch(obj) {
  case L1Cache_State_I:
    return "I";
  case L1Cache_State_II:
    return "II";
  case L1Cache_State_M:
    return "M";
  case L1Cache_State_MI:
    return "MI";
  case L1Cache_State_IS:
    return "IS";
  case L1Cache_State_IM:
    return "IM";
  default:
    ERROR_MSG("Invalid range for type L1Cache_State");
    return "";
  }
}

L1Cache_State string_to_L1Cache_State(const string& str)
{
  if (false) {
  } else if (str == "I") {
    return L1Cache_State_I;
  } else if (str == "II") {
    return L1Cache_State_II;
  } else if (str == "M") {
    return L1Cache_State_M;
  } else if (str == "MI") {
    return L1Cache_State_MI;
  } else if (str == "IS") {
    return L1Cache_State_IS;
  } else if (str == "IM") {
    return L1Cache_State_IM;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type L1Cache_State");
  }
}

L1Cache_State& operator++( L1Cache_State& e) {
  assert(e < L1Cache_State_NUM);
  return e = L1Cache_State(e+1);
}
