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
  case CoherenceResponseType_MEMORY_DATA:
    return "MEMORY_DATA";
  case CoherenceResponseType_THREAT:
    return "THREAT";
  case CoherenceResponseType_ACK:
    return "ACK";
  case CoherenceResponseType_WB_ACK:
    return "WB_ACK";
  case CoherenceResponseType_UNBLOCK:
    return "UNBLOCK";
  case CoherenceResponseType_EXCLUSIVE_UNBLOCK:
    return "EXCLUSIVE_UNBLOCK";
  case CoherenceResponseType_EXCLUSIVE_UNBLOCK_THREAT:
    return "EXCLUSIVE_UNBLOCK_THREAT";
  case CoherenceResponseType_EXCLUSIVE_UNBLOCK_THREAT_DATA:
    return "EXCLUSIVE_UNBLOCK_THREAT_DATA";
  case CoherenceResponseType_UNBLOCK_THREAT:
    return "UNBLOCK_THREAT";
  case CoherenceResponseType_UNBLOCK_DATA:
    return "UNBLOCK_DATA";
  case CoherenceResponseType_UNBLOCK_DATA_THREAT:
    return "UNBLOCK_DATA_THREAT";
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
  } else if (str == "MEMORY_DATA") {
    return CoherenceResponseType_MEMORY_DATA;
  } else if (str == "THREAT") {
    return CoherenceResponseType_THREAT;
  } else if (str == "ACK") {
    return CoherenceResponseType_ACK;
  } else if (str == "WB_ACK") {
    return CoherenceResponseType_WB_ACK;
  } else if (str == "UNBLOCK") {
    return CoherenceResponseType_UNBLOCK;
  } else if (str == "EXCLUSIVE_UNBLOCK") {
    return CoherenceResponseType_EXCLUSIVE_UNBLOCK;
  } else if (str == "EXCLUSIVE_UNBLOCK_THREAT") {
    return CoherenceResponseType_EXCLUSIVE_UNBLOCK_THREAT;
  } else if (str == "EXCLUSIVE_UNBLOCK_THREAT_DATA") {
    return CoherenceResponseType_EXCLUSIVE_UNBLOCK_THREAT_DATA;
  } else if (str == "UNBLOCK_THREAT") {
    return CoherenceResponseType_UNBLOCK_THREAT;
  } else if (str == "UNBLOCK_DATA") {
    return CoherenceResponseType_UNBLOCK_DATA;
  } else if (str == "UNBLOCK_DATA_THREAT") {
    return CoherenceResponseType_UNBLOCK_DATA_THREAT;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type CoherenceResponseType");
  }
}

CoherenceResponseType& operator++( CoherenceResponseType& e) {
  assert(e < CoherenceResponseType_NUM);
  return e = CoherenceResponseType(e+1);
}
