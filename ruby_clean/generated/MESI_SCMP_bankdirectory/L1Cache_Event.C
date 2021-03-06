/** \file L1Cache_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "L1Cache_Event.h"

ostream& operator<<(ostream& out, const L1Cache_Event& obj)
{
  out << L1Cache_Event_to_string(obj);
  out << flush;
  return out;
}

string L1Cache_Event_to_string(const L1Cache_Event& obj)
{
  switch(obj) {
  case L1Cache_Event_Load:
    return "Load";
  case L1Cache_Event_TLoad:
    return "TLoad";
  case L1Cache_Event_Ifetch:
    return "Ifetch";
  case L1Cache_Event_Store:
    return "Store";
  case L1Cache_Event_TStore:
    return "TStore";
  case L1Cache_Event_Inv:
    return "Inv";
  case L1Cache_Event_L1_Replacement:
    return "L1_Replacement";
  case L1Cache_Event_Fwd_GETX:
    return "Fwd_GETX";
  case L1Cache_Event_Fwd_GETS:
    return "Fwd_GETS";
  case L1Cache_Event_Fwd_GET_INSTR:
    return "Fwd_GET_INSTR";
  case L1Cache_Event_Fwd_TGETS:
    return "Fwd_TGETS";
  case L1Cache_Event_Fwd_TGETX:
    return "Fwd_TGETX";
  case L1Cache_Event_Data:
    return "Data";
  case L1Cache_Event_Data_Exclusive:
    return "Data_Exclusive";
  case L1Cache_Event_Data_all_Acks:
    return "Data_all_Acks";
  case L1Cache_Event_Data_all_Acks_Threat:
    return "Data_all_Acks_Threat";
  case L1Cache_Event_Ack:
    return "Ack";
  case L1Cache_Event_Ack_all:
    return "Ack_all";
  case L1Cache_Event_Ack_all_Threat:
    return "Ack_all_Threat";
  case L1Cache_Event_WB_Ack:
    return "WB_Ack";
  default:
    ERROR_MSG("Invalid range for type L1Cache_Event");
    return "";
  }
}

L1Cache_Event string_to_L1Cache_Event(const string& str)
{
  if (false) {
  } else if (str == "Load") {
    return L1Cache_Event_Load;
  } else if (str == "TLoad") {
    return L1Cache_Event_TLoad;
  } else if (str == "Ifetch") {
    return L1Cache_Event_Ifetch;
  } else if (str == "Store") {
    return L1Cache_Event_Store;
  } else if (str == "TStore") {
    return L1Cache_Event_TStore;
  } else if (str == "Inv") {
    return L1Cache_Event_Inv;
  } else if (str == "L1_Replacement") {
    return L1Cache_Event_L1_Replacement;
  } else if (str == "Fwd_GETX") {
    return L1Cache_Event_Fwd_GETX;
  } else if (str == "Fwd_GETS") {
    return L1Cache_Event_Fwd_GETS;
  } else if (str == "Fwd_GET_INSTR") {
    return L1Cache_Event_Fwd_GET_INSTR;
  } else if (str == "Fwd_TGETS") {
    return L1Cache_Event_Fwd_TGETS;
  } else if (str == "Fwd_TGETX") {
    return L1Cache_Event_Fwd_TGETX;
  } else if (str == "Data") {
    return L1Cache_Event_Data;
  } else if (str == "Data_Exclusive") {
    return L1Cache_Event_Data_Exclusive;
  } else if (str == "Data_all_Acks") {
    return L1Cache_Event_Data_all_Acks;
  } else if (str == "Data_all_Acks_Threat") {
    return L1Cache_Event_Data_all_Acks_Threat;
  } else if (str == "Ack") {
    return L1Cache_Event_Ack;
  } else if (str == "Ack_all") {
    return L1Cache_Event_Ack_all;
  } else if (str == "Ack_all_Threat") {
    return L1Cache_Event_Ack_all_Threat;
  } else if (str == "WB_Ack") {
    return L1Cache_Event_WB_Ack;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type L1Cache_Event");
  }
}

L1Cache_Event& operator++( L1Cache_Event& e) {
  assert(e < L1Cache_Event_NUM);
  return e = L1Cache_Event(e+1);
}
