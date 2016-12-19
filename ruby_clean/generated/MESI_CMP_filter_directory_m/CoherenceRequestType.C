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
  case CoherenceRequestType_GETX_ESCAPE:
    return "GETX_ESCAPE";
  case CoherenceRequestType_UPGRADE:
    return "UPGRADE";
  case CoherenceRequestType_GETS:
    return "GETS";
  case CoherenceRequestType_GETS_ESCAPE:
    return "GETS_ESCAPE";
  case CoherenceRequestType_GET_INSTR:
    return "GET_INSTR";
  case CoherenceRequestType_GET_INSTR_ESCAPE:
    return "GET_INSTR_ESCAPE";
  case CoherenceRequestType_INV:
    return "INV";
  case CoherenceRequestType_INV_ESCAPE:
    return "INV_ESCAPE";
  case CoherenceRequestType_PUTX:
    return "PUTX";
  case CoherenceRequestType_PUTS:
    return "PUTS";
  case CoherenceRequestType_REPLACE:
    return "REPLACE";
  case CoherenceRequestType_CHECK_WRITE_FILTER:
    return "CHECK_WRITE_FILTER";
  case CoherenceRequestType_CHECK_READ_WRITE_FILTER:
    return "CHECK_READ_WRITE_FILTER";
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
  } else if (str == "GETX_ESCAPE") {
    return CoherenceRequestType_GETX_ESCAPE;
  } else if (str == "UPGRADE") {
    return CoherenceRequestType_UPGRADE;
  } else if (str == "GETS") {
    return CoherenceRequestType_GETS;
  } else if (str == "GETS_ESCAPE") {
    return CoherenceRequestType_GETS_ESCAPE;
  } else if (str == "GET_INSTR") {
    return CoherenceRequestType_GET_INSTR;
  } else if (str == "GET_INSTR_ESCAPE") {
    return CoherenceRequestType_GET_INSTR_ESCAPE;
  } else if (str == "INV") {
    return CoherenceRequestType_INV;
  } else if (str == "INV_ESCAPE") {
    return CoherenceRequestType_INV_ESCAPE;
  } else if (str == "PUTX") {
    return CoherenceRequestType_PUTX;
  } else if (str == "PUTS") {
    return CoherenceRequestType_PUTS;
  } else if (str == "REPLACE") {
    return CoherenceRequestType_REPLACE;
  } else if (str == "CHECK_WRITE_FILTER") {
    return CoherenceRequestType_CHECK_WRITE_FILTER;
  } else if (str == "CHECK_READ_WRITE_FILTER") {
    return CoherenceRequestType_CHECK_READ_WRITE_FILTER;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type CoherenceRequestType");
  }
}

CoherenceRequestType& operator++( CoherenceRequestType& e) {
  assert(e < CoherenceRequestType_NUM);
  return e = CoherenceRequestType(e+1);
}
