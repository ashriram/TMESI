/** \file CoherenceResponseType.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "CoherenceResponseType.h"

ostream& operator<<(ostream& out, const CoherenceResponseType& obj)
{
  out << CoherenceResponseType_to_string(obj);
  out << flush;
  return out;
}

string CoherenceResponseType_to_string(const CoherenceResponseType& obj)
{
  switch(obj) {
  case CoherenceResponseType_MEMORY_ACK:
    return "MEMORY_ACK";
  case CoherenceResponseType_DATA:
    return "DATA";
  case CoherenceResponseType_DATA_EXCLUSIVE:
    return "DATA_EXCLUSIVE";
  case CoherenceResponseType_L2_DATA:
    return "L2_DATA";
  case CoherenceResponseType_L2_DATA_EXCLUSIVE:
    return "L2_DATA_EXCLUSIVE";
  case CoherenceResponseType_MEMORY_DATA:
    return "MEMORY_DATA";
  case CoherenceResponseType_ACK:
    return "ACK";
  case CoherenceResponseType_NACK:
    return "NACK";
  case CoherenceResponseType_WB_ACK:
    return "WB_ACK";
  case CoherenceResponseType_UNBLOCK:
    return "UNBLOCK";
  case CoherenceResponseType_EXCLUSIVE_UNBLOCK:
    return "EXCLUSIVE_UNBLOCK";
  case CoherenceResponseType_UNBLOCK_CANCEL:
    return "UNBLOCK_CANCEL";
  default:
    ERROR_MSG("Invalid range for type CoherenceResponseType");
    return "";
  }
}

CoherenceResponseType string_to_CoherenceResponseType(const string& str)
{
  if (false) {
  } else if (str == "MEMORY_ACK") {
    return CoherenceResponseType_MEMORY_ACK;
  } else if (str == "DATA") {
    return CoherenceResponseType_DATA;
  } else if (str == "DATA_EXCLUSIVE") {
    return CoherenceResponseType_DATA_EXCLUSIVE;
  } else if (str == "L2_DATA") {
    return CoherenceResponseType_L2_DATA;
  } else if (str == "L2_DATA_EXCLUSIVE") {
    return CoherenceResponseType_L2_DATA_EXCLUSIVE;
  } else if (str == "MEMORY_DATA") {
    return CoherenceResponseType_MEMORY_DATA;
  } else if (str == "ACK") {
    return CoherenceResponseType_ACK;
  } else if (str == "NACK") {
    return CoherenceResponseType_NACK;
  } else if (str == "WB_ACK") {
    return CoherenceResponseType_WB_ACK;
  } else if (str == "UNBLOCK") {
    return CoherenceResponseType_UNBLOCK;
  } else if (str == "EXCLUSIVE_UNBLOCK") {
    return CoherenceResponseType_EXCLUSIVE_UNBLOCK;
  } else if (str == "UNBLOCK_CANCEL") {
    return CoherenceResponseType_UNBLOCK_CANCEL;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type CoherenceResponseType");
  }
}

CoherenceResponseType& operator++( CoherenceResponseType& e) {
  assert(e < CoherenceResponseType_NUM);
  return e = CoherenceResponseType(e+1);
}
