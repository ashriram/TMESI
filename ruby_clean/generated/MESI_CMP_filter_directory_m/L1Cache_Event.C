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
  case L1Cache_Event_Ifetch:
    return "Ifetch";
  case L1Cache_Event_Store:
    return "Store";
  case L1Cache_Event_TLoadHit:
    return "TLoadHit";
  case L1Cache_Event_Replace:
    return "Replace";
  case L1Cache_Event_Inv:
    return "Inv";
  case L1Cache_Event_Inv_X:
    return "Inv_X";
  case L1Cache_Event_L1_Replacement:
    return "L1_Replacement";
  case L1Cache_Event_L1_Replacement_XACT:
    return "L1_Replacement_XACT";
  case L1Cache_Event_Fwd_GETX:
    return "Fwd_GETX";
  case L1Cache_Event_Fwd_GETS:
    return "Fwd_GETS";
  case L1Cache_Event_Fwd_GET_INSTR:
    return "Fwd_GET_INSTR";
  case L1Cache_Event_L2_Data:
    return "L2_Data";
  case L1Cache_Event_L2_Data_all_Acks:
    return "L2_Data_all_Acks";
  case L1Cache_Event_L2_Exclusive_Data:
    return "L2_Exclusive_Data";
  case L1Cache_Event_L2_Exclusive_Data_all_Acks:
    return "L2_Exclusive_Data_all_Acks";
  case L1Cache_Event_DataS_fromL1:
    return "DataS_fromL1";
  case L1Cache_Event_Data_all_Acks:
    return "Data_all_Acks";
  case L1Cache_Event_Ack:
    return "Ack";
  case L1Cache_Event_Ack_all:
    return "Ack_all";
  case L1Cache_Event_WB_Ack:
    return "WB_Ack";
  case L1Cache_Event_Nack:
    return "Nack";
  case L1Cache_Event_Nack_all:
    return "Nack_all";
  case L1Cache_Event_Check_Write_Filter:
    return "Check_Write_Filter";
  case L1Cache_Event_Check_Read_Write_Filter:
    return "Check_Read_Write_Filter";
  case L1Cache_Event_Fwd_GETS_X:
    return "Fwd_GETS_X";
  case L1Cache_Event_Fwd_GETX_X:
    return "Fwd_GETX_X";
  case L1Cache_Event_Fwd_GET_INSTR_X:
    return "Fwd_GET_INSTR_X";
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
  } else if (str == "Ifetch") {
    return L1Cache_Event_Ifetch;
  } else if (str == "Store") {
    return L1Cache_Event_Store;
  } else if (str == "TLoadHit") {
    return L1Cache_Event_TLoadHit;
  } else if (str == "Replace") {
    return L1Cache_Event_Replace;
  } else if (str == "Inv") {
    return L1Cache_Event_Inv;
  } else if (str == "Inv_X") {
    return L1Cache_Event_Inv_X;
  } else if (str == "L1_Replacement") {
    return L1Cache_Event_L1_Replacement;
  } else if (str == "L1_Replacement_XACT") {
    return L1Cache_Event_L1_Replacement_XACT;
  } else if (str == "Fwd_GETX") {
    return L1Cache_Event_Fwd_GETX;
  } else if (str == "Fwd_GETS") {
    return L1Cache_Event_Fwd_GETS;
  } else if (str == "Fwd_GET_INSTR") {
    return L1Cache_Event_Fwd_GET_INSTR;
  } else if (str == "L2_Data") {
    return L1Cache_Event_L2_Data;
  } else if (str == "L2_Data_all_Acks") {
    return L1Cache_Event_L2_Data_all_Acks;
  } else if (str == "L2_Exclusive_Data") {
    return L1Cache_Event_L2_Exclusive_Data;
  } else if (str == "L2_Exclusive_Data_all_Acks") {
    return L1Cache_Event_L2_Exclusive_Data_all_Acks;
  } else if (str == "DataS_fromL1") {
    return L1Cache_Event_DataS_fromL1;
  } else if (str == "Data_all_Acks") {
    return L1Cache_Event_Data_all_Acks;
  } else if (str == "Ack") {
    return L1Cache_Event_Ack;
  } else if (str == "Ack_all") {
    return L1Cache_Event_Ack_all;
  } else if (str == "WB_Ack") {
    return L1Cache_Event_WB_Ack;
  } else if (str == "Nack") {
    return L1Cache_Event_Nack;
  } else if (str == "Nack_all") {
    return L1Cache_Event_Nack_all;
  } else if (str == "Check_Write_Filter") {
    return L1Cache_Event_Check_Write_Filter;
  } else if (str == "Check_Read_Write_Filter") {
    return L1Cache_Event_Check_Read_Write_Filter;
  } else if (str == "Fwd_GETS_X") {
    return L1Cache_Event_Fwd_GETS_X;
  } else if (str == "Fwd_GETX_X") {
    return L1Cache_Event_Fwd_GETX_X;
  } else if (str == "Fwd_GET_INSTR_X") {
    return L1Cache_Event_Fwd_GET_INSTR_X;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type L1Cache_Event");
  }
}

L1Cache_Event& operator++( L1Cache_Event& e) {
  assert(e < L1Cache_Event_NUM);
  return e = L1Cache_Event(e+1);
}
