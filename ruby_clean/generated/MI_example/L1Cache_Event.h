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
  L1Cache_Event_Load = L1Cache_Event_FIRST,  /**< Load request from processor */
  L1Cache_Event_Ifetch,  /**< Ifetch request from processor */
  L1Cache_Event_Store,  /**< Store request from processor */
  L1Cache_Event_Data,  /**< Data from network */
  L1Cache_Event_Fwd_GETX,  /**< Forward from network */
  L1Cache_Event_Replacement,  /**< Replace a block */
  L1Cache_Event_Writeback_Ack,  /**< Ack from the directory for a writeback */
  L1Cache_Event_Writeback_Nack,  /**< Nack from the directory for a writeback */
  L1Cache_Event_NUM
};
L1Cache_Event string_to_L1Cache_Event(const string& str);
string L1Cache_Event_to_string(const L1Cache_Event& obj);
L1Cache_Event &operator++( L1Cache_Event &e);
ostream& operator<<(ostream& out, const L1Cache_Event& obj);

#endif // L1Cache_Event_H
