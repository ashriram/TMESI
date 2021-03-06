/** \file L2Cache_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef L2Cache_Event_H
#define L2Cache_Event_H

#include "Global.h"

/** \enum L2Cache_Event
  * \brief L2 Cache events
  */
enum L2Cache_Event {
  L2Cache_Event_FIRST,
  L2Cache_Event_L1_GET_INSTR = L2Cache_Event_FIRST,  /**< a L1I GET INSTR request for a block maped to us */
  L2Cache_Event_L1_GET_INSTR_ESCAPE,  /**< a L1I GET INSTR in an escape action request for a block mapped to us */
  L2Cache_Event_L1_GETS,  /**< a L1D GETS request for a block maped to us */
  L2Cache_Event_L1_GETS_ESCAPE,  /**< a L1D GETS in an escape action request for a block mapped to us */
  L2Cache_Event_L1_GETX,  /**< a L1D GETX request for a block maped to us */
  L2Cache_Event_L1_GETX_ESCAPE,  /**< a L1D GETX in an escape action request for a block mapped to us */
  L2Cache_Event_L1_UPGRADE,  /**< a L1D GETX request for a block maped to us */
  L2Cache_Event_L1_PUTX,  /**< L1 replacing data */
  L2Cache_Event_L1_PUTX_old,  /**< L1 replacing data, but no longer sharer */
  L2Cache_Event_L1_PUTS,  /**< L1 replacing clean data */
  L2Cache_Event_L1_PUTS_old,  /**< L1 replacing clean data, but no longer sharer */
  L2Cache_Event_L1_PUT_PENDING,  /**< L1 PUT msg pending (recycled) */
  L2Cache_Event_Fwd_L1_GETX,  /**< L1 did not have data, so we supply */
  L2Cache_Event_Fwd_L1_GETS,  /**< L1 did not have data, so we supply */
  L2Cache_Event_Fwd_L1_GET_INSTR,  /**< L1 did not have data, so we supply */
  L2Cache_Event_L2_Replacement,  /**< L2 Replacement */
  L2Cache_Event_L2_Replacement_XACT,  /**< L2 Replacement of trans. data */
  L2Cache_Event_L2_Replacement_clean,  /**< L2 Replacement, but data is clean */
  L2Cache_Event_L2_Replacement_clean_XACT,  /**< L2 Replacement of trans. data, but data is clean */
  L2Cache_Event_Mem_Data,  /**< data from memory */
  L2Cache_Event_Mem_Ack,  /**< ack from memory */
  L2Cache_Event_WB_Data,  /**< data from L1 */
  L2Cache_Event_WB_Data_clean,  /**< clean data from L1 */
  L2Cache_Event_Ack,  /**< writeback ack */
  L2Cache_Event_Ack_all,  /**< writeback ack */
  L2Cache_Event_Nack,  /**< filter indicates conflict */
  L2Cache_Event_Nack_all,  /**< all filters have responded, at least one conflict */
  L2Cache_Event_Unblock,  /**< Unblock from L1 requestor */
  L2Cache_Event_Unblock_Cancel,  /**< Unblock from L1 requestor (FOR XACT MEMORY) */
  L2Cache_Event_Exclusive_Unblock,  /**< Unblock from L1 requestor */
  L2Cache_Event_Unblock_WaitPUTold,  /**< Unblock from L1 requestor, last requestor was replacing so wait for PUT msg */
  L2Cache_Event_Exclusive_Unblock_WaitPUTold,  /**< Unblock from L1 requestor, last requestor was replacing so wait for PUT msg */
  L2Cache_Event_NUM
};
L2Cache_Event string_to_L2Cache_Event(const string& str);
string L2Cache_Event_to_string(const L2Cache_Event& obj);
L2Cache_Event &operator++( L2Cache_Event &e);
ostream& operator<<(ostream& out, const L2Cache_Event& obj);

#endif // L2Cache_Event_H
