/** \file CoherenceRequestType.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "CoherenceRequestType.h"

ostream& operator<<(ostream& out, const CoherenceRequestType& obj)
{
  out << CoherenceRequestType_to_string(obj);
  out << flush;
  return out;
}

string CoherenceRequestType_to_string(const CoherenceRequestType& obj)
{
  switch(obj) {
  case CoherenceRequestType_GETX:
    return "GETX";
  case CoherenceRequestType_GETS:
    return "GETS";
  case CoherenceRequestType_PUTX:
    return "PUTX";
  case CoherenceRequestType_PUTO:
    return "PUTO";
  case CoherenceRequestType_WB_ACK:
    return "WB_ACK";
  case CoherenceRequestType_WB_NACK:
    return "WB_NACK";
  case CoherenceRequestType_INV:
    return "INV";
  case CoherenceRequestType_FWD:
    return "FWD";
  default:
    ERROR_MSG("Invalid range for type CoherenceRequestType");
    return "";
  }
}

CoherenceRequestType string_to_CoherenceRequestType(const string& str)
{
  if (false) {
  } else if (str == "GETX") {
    return CoherenceRequestType_GETX;
  } else if (str == "GETS") {
    return CoherenceRequestType_GETS;
  } else if (str == "PUTX") {
    return CoherenceRequestType_PUTX;
  } else if (str == "PUTO") {
    return CoherenceRequestType_PUTO;
  } else if (str == "WB_ACK") {
    return CoherenceRequestType_WB_ACK;
  } else if (str == "WB_NACK") {
    return CoherenceRequestType_WB_NACK;
  } else if (str == "INV") {
    return CoherenceRequestType_INV;
  } else if (str == "FWD") {
    return CoherenceRequestType_FWD;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type CoherenceRequestType");
  }
}

CoherenceRequestType& operator++( CoherenceRequestType& e) {
  assert(e < CoherenceRequestType_NUM);
  return e = CoherenceRequestType(e+1);
}
