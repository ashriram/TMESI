/** \file TriggerType.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "TriggerType.h"

ostream& operator<<(ostream& out, const TriggerType& obj)
{
  out << TriggerType_to_string(obj);
  out << flush;
  return out;
}

string TriggerType_to_string(const TriggerType& obj)
{
  switch(obj) {
  case TriggerType_ALL_ACKS:
    return "ALL_ACKS";
  default:
    ERROR_MSG("Invalid range for type TriggerType");
    return "";
  }
}

TriggerType string_to_TriggerType(const string& str)
{
  if (false) {
  } else if (str == "ALL_ACKS") {
    return TriggerType_ALL_ACKS;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type TriggerType");
  }
}

TriggerType& operator++( TriggerType& e) {
  assert(e < TriggerType_NUM);
  return e = TriggerType(e+1);
}
