/** \file CoherenceRequestType.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef CoherenceRequestType_H
#define CoherenceRequestType_H

#include "Global.h"

/** \enum CoherenceRequestType
  * \brief ...
  */
enum CoherenceRequestType {
  CoherenceRequestType_FIRST,
  CoherenceRequestType_GETX = CoherenceRequestType_FIRST,  /**< Get eXclusive */
  CoherenceRequestType_GETX_ESCAPE,  /**< Get eXclusive, while in escape action */
  CoherenceRequestType_UPGRADE,  /**< UPGRADE to exclusive */
  CoherenceRequestType_GETS,  /**< Get Shared */
  CoherenceRequestType_GETS_ESCAPE,  /**< Get Shared, while in escape action */
  CoherenceRequestType_GET_INSTR,  /**< Get Instruction */
  CoherenceRequestType_GET_INSTR_ESCAPE,  /**< Get Instruction, while in escape action */
  CoherenceRequestType_INV,  /**< INValidate, could be NACKed */
  CoherenceRequestType_INV_ESCAPE,  /**< INValidate, cannot be NACKed */
  CoherenceRequestType_PUTX,  /**< replacement message, for writeback to lower caches */
  CoherenceRequestType_PUTS,  /**< clean replacement message, for writeback to lower caches */
  CoherenceRequestType_REPLACE,  /**< replacement message, from lowest cache */
  CoherenceRequestType_CHECK_WRITE_FILTER,  /**< check write filter message */
  CoherenceRequestType_CHECK_READ_WRITE_FILTER,  /**< check both read and write filters message */
  CoherenceRequestType_NUM
};
CoherenceRequestType string_to_CoherenceRequestType(const string& str);
string CoherenceRequestType_to_string(const CoherenceRequestType& obj);
CoherenceRequestType &operator++( CoherenceRequestType &e);
ostream& operator<<(ostream& out, const CoherenceRequestType& obj);

#endif // CoherenceRequestType_H
