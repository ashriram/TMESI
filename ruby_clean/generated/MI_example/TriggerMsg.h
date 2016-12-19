/** \file TriggerMsg.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef TriggerMsg_H
#define TriggerMsg_H

#include "Global.h"
#include "Allocator.h"
#include "Address.h"
#include "TriggerType.h"
#include "Message.h"
class TriggerMsg :  public Message {
public:
  TriggerMsg() 
  : Message()
  {
    // m_Address has no default
    m_Type = TriggerType_NUM; // default value of TriggerType
  }
  ~TriggerMsg() { };
  TriggerMsg(const Address& local_Address, const TriggerType& local_Type)
  : Message()
  {
    m_Address = local_Address;
    m_Type = local_Type;
  }
  Message* clone() const { checkAllocator(); return s_allocator_ptr->allocate(*this); }
  void destroy() { checkAllocator(); s_allocator_ptr->deallocate(this); }
  static Allocator<TriggerMsg>* s_allocator_ptr;
  static void checkAllocator() { if (s_allocator_ptr == NULL) { s_allocator_ptr = new Allocator<TriggerMsg>; }}
  // Const accessors methods for each field
/** \brief Const accessor method for Address field.
  * \return Address field
  */
  const Address& getAddress() const { return m_Address; }
/** \brief Const accessor method for Type field.
  * \return Type field
  */
  const TriggerType& getType() const { return m_Type; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for Address field.
  * \return Address field
  */
  Address& getAddress() { return m_Address; }
/** \brief Non-const accessor method for Type field.
  * \return Type field
  */
  TriggerType& getType() { return m_Type; }

  // Mutator methods for each field
/** \brief Mutator method for Address field */
  void setAddress(const Address& local_Address) { m_Address = local_Address; }
/** \brief Mutator method for Type field */
  void setType(const TriggerType& local_Type) { m_Type = local_Type; }

  void print(ostream& out) const;
//private:
  Address m_Address; /**< Physical address for this request*/
  TriggerType m_Type; /**< Type of trigger*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const TriggerMsg& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const TriggerMsg& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // TriggerMsg_H
