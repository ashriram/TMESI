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
  CoherenceResponseType_MEMORY_ACK = CoherenceResponseType_FIRST,  /**< Ack from memory controller */
  CoherenceResponseType_DATA,  /**< Data */
  CoherenceResponseType_DATA_EXCLUSIVE,  /**< Data */
  CoherenceResponseType_MEMORY_DATA,  /**< Data */
  CoherenceResponseType_THREAT,  /**< Threatening msg sent to L2 */
  CoherenceResponseType_ACK,  /**< Generic invalidate ack */
  CoherenceResponseType_WB_ACK,  /**< writeback ack */
  CoherenceResponseType_UNBLOCK,  /**< unblock */
  CoherenceResponseType_EXCLUSIVE_UNBLOCK,  /**< exclusive unblock */
  CoherenceResponseType_EXCLUSIVE_UNBLOCK_THREAT,  /**< exclusive unblock */
  CoherenceResponseType_EXCLUSIVE_UNBLOCK_THREAT_DATA,  /**< exclusive unblock */
  CoherenceResponseType_UNBLOCK_THREAT,  /**< Threatened unblock */
  CoherenceResponseType_UNBLOCK_DATA,  /**< UNBLOCK that also include DATA */
  CoherenceResponseType_UNBLOCK_DATA_THREAT,  /**< UNBLOCK that includes DATA and THREAT */
  CoherenceResponseType_NUM
};
CoherenceResponseType string_to_CoherenceResponseType(const string& str);
string CoherenceResponseType_to_string(const CoherenceResponseType& obj);
CoherenceResponseType &operator++( CoherenceResponseType &e);
ostream& operator<<(ostream& out, const CoherenceResponseType& obj);

#endif // CoherenceResponseType_H
