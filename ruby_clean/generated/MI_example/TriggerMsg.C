/** \file TriggerMsg.C
  * 
  * Auto generated C++ code started by symbols/Type.C:479
  */

#include "TriggerMsg.h"

Allocator<TriggerMsg>* TriggerMsg::s_allocator_ptr = NULL;
/** \brief Print the state of this object */
void TriggerMsg::print(ostream& out) const
{
  out << "[TriggerMsg: ";
  out << "Address=" << m_Address << " ";
  out << "Type=" << m_Type << " ";
  out << "Time=" << getTime() << " ";
  out << "]";
}
