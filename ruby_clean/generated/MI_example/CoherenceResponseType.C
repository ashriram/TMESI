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
  case CoherenceResponseType_ACK:
    return "ACK";
  case CoherenceResponseType_DATA:
    return "DATA";
  case CoherenceResponseType_DATA_EXCLUSIVE_CLEAN:
    return "DATA_EXCLUSIVE_CLEAN";
  case CoherenceResponseType_DATA_EXCLUSIVE_DIRTY:
    return "DATA_EXCLUSIVE_DIRTY";
  case CoherenceResponseType_UNBLOCK:
    return "UNBLOCK";
  case CoherenceResponseType_UNBLOCK_EXCLUSIVE:
    return "UNBLOCK_EXCLUSIVE";
  case CoherenceResponseType_WRITEBACK_CLEAN:
    return "WRITEBACK_CLEAN";
  case CoherenceResponseType_WRITEBACK_DIRTY:
    return "WRITEBACK_DIRTY";
  case CoherenceResponseType_WRITEBACK:
    return "WRITEBACK";
  default:
    ERROR_MSG("Invalid range for type CoherenceResponseType");
    return "";
  }
}

CoherenceResponseType string_to_CoherenceResponseType(const string& str)
{
  if (false) {
  } else if (str == "ACK") {
    return CoherenceResponseType_ACK;
  } else if (str == "DATA") {
    return CoherenceResponseType_DATA;
  } else if (str == "DATA_EXCLUSIVE_CLEAN") {
    return CoherenceResponseType_DATA_EXCLUSIVE_CLEAN;
  } else if (str == "DATA_EXCLUSIVE_DIRTY") {
    return CoherenceResponseType_DATA_EXCLUSIVE_DIRTY;
  } else if (str == "UNBLOCK") {
    return CoherenceResponseType_UNBLOCK;
  } else if (str == "UNBLOCK_EXCLUSIVE") {
    return CoherenceResponseType_UNBLOCK_EXCLUSIVE;
  } else if (str == "WRITEBACK_CLEAN") {
    return CoherenceResponseType_WRITEBACK_CLEAN;
  } else if (str == "WRITEBACK_DIRTY") {
    return CoherenceResponseType_WRITEBACK_DIRTY;
  } else if (str == "WRITEBACK") {
    return CoherenceResponseType_WRITEBACK;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type CoherenceResponseType");
  }
}

CoherenceResponseType& operator++( CoherenceResponseType& e) {
  assert(e < CoherenceResponseType_NUM);
  return e = CoherenceResponseType(e+1);
}
