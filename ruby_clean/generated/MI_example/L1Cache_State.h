/** \file L1Cache_State.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef L1Cache_State_H
#define L1Cache_State_H

#include "Global.h"

/** \enum L1Cache_State
  * \brief Cache states
  */
enum L1Cache_State {
  L1Cache_State_FIRST,
  L1Cache_State_I = L1Cache_State_FIRST,  /**< Not Present/Invalid */
  L1Cache_State_II,  /**< Not Present/Invalid, issued PUT */
  L1Cache_State_M,  /**< Modified */
  L1Cache_State_MI,  /**< Modified, issued PUT */
  L1Cache_State_IS,  /**< Issued request for IFETCH/GETX */
  L1Cache_State_IM,  /**< Issued request for STORE/ATOMIC */
  L1Cache_State_NUM
};
L1Cache_State string_to_L1Cache_State(const string& str);
string L1Cache_State_to_string(const L1Cache_State& obj);
L1Cache_State &operator++( L1Cache_State &e);
ostream& operator<<(ostream& out, const L1Cache_State& obj);

#endif // L1Cache_State_H
