/** \file L2Cache_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "L2Cache_Event.h"

ostream& operator<<(ostream& out, const L2Cache_Event& obj)
{
  out << L2Cache_Event_to_string(obj);
  out << flush;
  return out;
}

string L2Cache_Event_to_string(const L2Cache_Event& obj)
{
  switch(obj) {
  case L2Cache_Event_L1_GET_INSTR:
    return "L1_GET_INSTR";
  case L2Cache_Event_L1_GET_INSTR_ESCAPE:
    return "L1_GET_INSTR_ESCAPE";
  case L2Cache_Event_L1_GETS:
    return "L1_GETS";
  case L2Cache_Event_L1_GETS_ESCAPE:
    return "L1_GETS_ESCAPE";
  case L2Cache_Event_L1_GETX:
    return "L1_GETX";
  case L2Cache_Event_L1_GETX_ESCAPE:
    return "L1_GETX_ESCAPE";
  case L2Cache_Event_L1_UPGRADE:
    return "L1_UPGRADE";
  case L2Cache_Event_L1_PUTX:
    return "L1_PUTX";
  case L2Cache_Event_L1_PUTX_old:
    return "L1_PUTX_old";
  case L2Cache_Event_L1_PUTS:
    return "L1_PUTS";
  case L2Cache_Event_L1_PUTS_old:
    return "L1_PUTS_old";
  case L2Cache_Event_L1_PUT_PENDING:
    return "L1_PUT_PENDING";
  case L2Cache_Event_Fwd_L1_GETX:
    return "Fwd_L1_GETX";
  case L2Cache_Event_Fwd_L1_GETS:
    return "Fwd_L1_GETS";
  case L2Cache_Event_Fwd_L1_GET_INSTR:
    return "Fwd_L1_GET_INSTR";
  case L2Cache_Event_L2_Replacement:
    return "L2_Replacement";
  case L2Cache_Event_L2_Replacement_XACT:
    return "L2_Replacement_XACT";
  case L2Cache_Event_L2_Replacement_clean:
    return "L2_Replacement_clean";
  case L2Cache_Event_L2_Replacement_clean_XACT:
    return "L2_Replacement_clean_XACT";
  case L2Cache_Event_Mem_Data:
    return "Mem_Data";
  case L2Cache_Event_Mem_Ack:
    return "Mem_Ack";
  case L2Cache_Event_WB_Data:
    return "WB_Data";
  case L2Cache_Event_WB_Data_clean:
    return "WB_Data_clean";
  case L2Cache_Event_Ack:
    return "Ack";
  case L2Cache_Event_Ack_all:
    return "Ack_all";
  case L2Cache_Event_Nack:
    return "Nack";
  case L2Cache_Event_Nack_all:
    return "Nack_all";
  case L2Cache_Event_Unblock:
    return "Unblock";
  case L2Cache_Event_Unblock_Cancel:
    return "Unblock_Cancel";
  case L2Cache_Event_Exclusive_Unblock:
    return "Exclusive_Unblock";
  case L2Cache_Event_Unblock_WaitPUTold:
    return "Unblock_WaitPUTold";
  case L2Cache_Event_Exclusive_Unblock_WaitPUTold:
    return "Exclusive_Unblock_WaitPUTold";
  default:
    ERROR_MSG("Invalid range for type L2Cache_Event");
    return "";
  }
}

L2Cache_Event string_to_L2Cache_Event(const string& str)
{
  if (false) {
  } else if (str == "L1_GET_INSTR") {
    return L2Cache_Event_L1_GET_INSTR;
  } else if (str == "L1_GET_INSTR_ESCAPE") {
    return L2Cache_Event_L1_GET_INSTR_ESCAPE;
  } else if (str == "L1_GETS") {
    return L2Cache_Event_L1_GETS;
  } else if (str == "L1_GETS_ESCAPE") {
    return L2Cache_Event_L1_GETS_ESCAPE;
  } else if (str == "L1_GETX") {
    return L2Cache_Event_L1_GETX;
  } else if (str == "L1_GETX_ESCAPE") {
    return L2Cache_Event_L1_GETX_ESCAPE;
  } else if (str == "L1_UPGRADE") {
    return L2Cache_Event_L1_UPGRADE;
  } else if (str == "L1_PUTX") {
    return L2Cache_Event_L1_PUTX;
  } else if (str == "L1_PUTX_old") {
    return L2Cache_Event_L1_PUTX_old;
  } else if (str == "L1_PUTS") {
    return L2Cache_Event_L1_PUTS;
  } else if (str == "L1_PUTS_old") {
    return L2Cache_Event_L1_PUTS_old;
  } else if (str == "L1_PUT_PENDING") {
    return L2Cache_Event_L1_PUT_PENDING;
  } else if (str == "Fwd_L1_GETX") {
    return L2Cache_Event_Fwd_L1_GETX;
  } else if (str == "Fwd_L1_GETS") {
    return L2Cache_Event_Fwd_L1_GETS;
  } else if (str == "Fwd_L1_GET_INSTR") {
    return L2Cache_Event_Fwd_L1_GET_INSTR;
  } else if (str == "L2_Replacement") {
    return L2Cache_Event_L2_Replacement;
  } else if (str == "L2_Replacement_XACT") {
    return L2Cache_Event_L2_Replacement_XACT;
  } else if (str == "L2_Replacement_clean") {
    return L2Cache_Event_L2_Replacement_clean;
  } else if (str == "L2_Replacement_clean_XACT") {
    return L2Cache_Event_L2_Replacement_clean_XACT;
  } else if (str == "Mem_Data") {
    return L2Cache_Event_Mem_Data;
  } else if (str == "Mem_Ack") {
    return L2Cache_Event_Mem_Ack;
  } else if (str == "WB_Data") {
    return L2Cache_Event_WB_Data;
  } else if (str == "WB_Data_clean") {
    return L2Cache_Event_WB_Data_clean;
  } else if (str == "Ack") {
    return L2Cache_Event_Ack;
  } else if (str == "Ack_all") {
    return L2Cache_Event_Ack_all;
  } else if (str == "Nack") {
    return L2Cache_Event_Nack;
  } else if (str == "Nack_all") {
    return L2Cache_Event_Nack_all;
  } else if (str == "Unblock") {
    return L2Cache_Event_Unblock;
  } else if (str == "Unblock_Cancel") {
    return L2Cache_Event_Unblock_Cancel;
  } else if (str == "Exclusive_Unblock") {
    return L2Cache_Event_Exclusive_Unblock;
  } else if (str == "Unblock_WaitPUTold") {
    return L2Cache_Event_Unblock_WaitPUTold;
  } else if (str == "Exclusive_Unblock_WaitPUTold") {
    return L2Cache_Event_Exclusive_Unblock_WaitPUTold;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type L2Cache_Event");
  }
}

L2Cache_Event& operator++( L2Cache_Event& e) {
  assert(e < L2Cache_Event_NUM);
  return e = L2Cache_Event(e+1);
}
