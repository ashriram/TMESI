/** \file CoherenceResponseType.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef CoherenceResponseType_H
#define CoherenceResponseType_H

#include "Global.h"

/** \enum CoherenceResponseType
  * \brief ...
  */
enum CoherenceResponseType {
  CoherenceResponseType_FIRST,
  CoherenceResponseType_ACK = CoherenceResponseType_FIRST,  /**< ACKnowledgment, responder doesn't have a copy */
  CoherenceResponseType_DATA,  /**< Data */
  CoherenceResponseType_DATA_EXCLUSIVE_CLEAN,  /**< Data, no other processor has a copy, data is clean */
  CoherenceResponseType_DATA_EXCLUSIVE_DIRTY,  /**< Data, no other processor has a copy, data is dirty */
  CoherenceResponseType_UNBLOCK,  /**< Unblock */
  CoherenceResponseType_UNBLOCK_EXCLUSIVE,  /**< Unblock, we're in E/M */
  CoherenceResponseType_WRITEBACK_CLEAN,  /**< Clean writeback (no data) */
  CoherenceResponseType_WRITEBACK_DIRTY,  /**< Dirty writeback (contains data) */
  CoherenceResponseType_WRITEBACK,  /**< Generic writeback (contains data) */
  CoherenceResponseType_NUM
};
CoherenceResponseType string_to_CoherenceResponseType(const string& str);
string CoherenceResponseType_to_string(const CoherenceResponseType& obj);
CoherenceResponseType &operator++( CoherenceResponseType &e);
ostream& operator<<(ostream& out, const CoherenceResponseType& obj);

#endif // CoherenceResponseType_H
