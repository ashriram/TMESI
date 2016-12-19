/** \file Directory_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "Directory_Event.h"

ostream& operator<<(ostream& out, const Directory_Event& obj)
{
  out << Directory_Event_to_string(obj);
  out << flush;
  return out;
}

string Directory_Event_to_string(const Directory_Event& obj)
{
  switch(obj) {
  case Directory_Event_GETX:
    return "GETX";
  case Directory_Event_GETS:
    return "GETS";
  case Directory_Event_PUTX:
    return "PUTX";
  case Directory_Event_PUTX_NotOwner:
    return "PUTX_NotOwner";
  case Directory_Event_PUTO:
    return "PUTO";
  case Directory_Event_Unblock:
    return "Unblock";
  default:
    ERROR_MSG("Invalid range for type Directory_Event");
    return "";
  }
}

Directory_Event string_to_Directory_Event(const string& str)
{
  if (false) {
  } else if (str == "GETX") {
    return Directory_Event_GETX;
  } else if (str == "GETS") {
    return Directory_Event_GETS;
  } else if (str == "PUTX") {
    return Directory_Event_PUTX;
  } else if (str == "PUTX_NotOwner") {
    return Directory_Event_PUTX_NotOwner;
  } else if (str == "PUTO") {
    return Directory_Event_PUTO;
  } else if (str == "Unblock") {
    return Directory_Event_Unblock;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type Directory_Event");
  }
}

Directory_Event& operator++( Directory_Event& e) {
  assert(e < Directory_Event_NUM);
  return e = Directory_Event(e+1);
}
