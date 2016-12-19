/** \file L1Cache_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef L1Cache_Event_H
#define L1Cache_Event_H

#include "Global.h"

/** \enum L1Cache_Event
  * \brief Cache events
  */
enum L1Cache_Event {
  L1Cache_Event_FIRST,
  L1Cache_Event_Load = L1Cache_Event_FIRST,  /**< Load request from the home processor */
  L1Cache_Event_Ifetch,  /**< I-fetch request from the home processor */
  L1Cache_Event_Store,  /**< Store request from the home processor */
  L1Cache_Event_TLoadHit,  /**< LD_XACT to TI state */
  L1Cache_Event_Replace,  /**< lower level cache replaced this line, also need to invalidate to maintain inclusion */
  L1Cache_Event_Inv,  /**< Invalidate request from L2 bank */
  L1Cache_Event_Inv_X,  /**< Invalidate request from L2 bank, trans CONFLICT */
  L1Cache_Event_L1_Replacement,  /**< L1 Replacement */
  L1Cache_Event_L1_Replacement_XACT,  /**< L1 Replacement of trans. data */
  L1Cache_Event_Fwd_GETX,  /**< GETX from other processor */
  L1Cache_Event_Fwd_GETS,  /**< GETS from other processor */
  L1Cache_Event_Fwd_GET_INSTR,  /**< GET_INSTR from other processor */
  L1Cache_Event_L2_Data,  /**< Data for processor, from L2 */
  L1Cache_Event_L2_Data_all_Acks,  /**< Data for processor, from L2, all acks */
  L1Cache_Event_L2_Exclusive_Data,  /**< Exlusive Data for processor, from L2 */
  L1Cache_Event_L2_Exclusive_Data_all_Acks,  /**< Exlusive Data for processor, from L2, all acks */
  L1Cache_Event_DataS_fromL1,  /**< data for GETS request, need to unblock directory */
  L1Cache_Event_Data_all_Acks,  /**< Data for processor, all acks */
  L1Cache_Event_Ack,  /**< Ack for processor */
  L1Cache_Event_Ack_all,  /**< Last ack for processor */
  L1Cache_Event_WB_Ack,  /**< Ack for replacement */
  L1Cache_Event_Nack,  /**< Nack for processor */
  L1Cache_Event_Nack_all,  /**< Last Nack for processor */
  L1Cache_Event_Check_Write_Filter,  /**< Check the write filter */
  L1Cache_Event_Check_Read_Write_Filter,  /**< Check the read and write filters */
  L1Cache_Event_Fwd_GETS_X,  /**< A GetS from another processor, trans CONFLICT */
  L1Cache_Event_Fwd_GETX_X,  /**< A GetS from another processor, trans CONFLICT */
  L1Cache_Event_Fwd_GET_INSTR_X,  /**< A GetInstr from another processor, trans CONFLICT */
  L1Cache_Event_NUM
};
L1Cache_Event string_to_L1Cache_Event(const string& str);
string L1Cache_Event_to_string(const L1Cache_Event& obj);
L1Cache_Event &operator++( L1Cache_Event &e);
ostream& operator<<(ostream& out, const L1Cache_Event& obj);

#endif // L1Cache_Event_H
