/** \file L1Cache_TBE.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef L1Cache_TBE_H
#define L1Cache_TBE_H

#include "Global.h"
#include "Allocator.h"
#include "L1Cache_State.h"
#include "DataBlock.h"
class L1Cache_TBE {
public:
  L1Cache_TBE() 
  {
    m_TBEState = L1Cache_State_NUM; // default value of L1Cache_State
    // m_DataBlk has no default
    m_Trans = false; // default value of bool
    m_Logged = false; // default value of bool
  }
  ~L1Cache_TBE() { };
  L1Cache_TBE(const L1Cache_State& local_TBEState, const DataBlock& local_DataBlk, const bool& local_Trans, const bool& local_Logged)
  {
    m_TBEState = local_TBEState;
    m_DataBlk = local_DataBlk;
    m_Trans = local_Trans;
    m_Logged = local_Logged;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for TBEState field.
  * \return TBEState field
  */
  const L1Cache_State& getTBEState() const { return m_TBEState; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for Trans field.
  * \return Trans field
  */
  const bool& getTrans() const { return m_Trans; }
/** \brief Const accessor method for Logged field.
  * \return Logged field
  */
  const bool& getLogged() const { return m_Logged; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for TBEState field.
  * \return TBEState field
  */
  L1Cache_State& getTBEState() { return m_TBEState; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for Trans field.
  * \return Trans field
  */
  bool& getTrans() { return m_Trans; }
/** \brief Non-const accessor method for Logged field.
  * \return Logged field
  */
  bool& getLogged() { return m_Logged; }

  // Mutator methods for each field
/** \brief Mutator method for TBEState field */
  void setTBEState(const L1Cache_State& local_TBEState) { m_TBEState = local_TBEState; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Trans field */
  void setTrans(const bool& local_Trans) { m_Trans = local_Trans; }
/** \brief Mutator method for Logged field */
  void setLogged(const bool& local_Logged) { m_Logged = local_Logged; }

  void print(ostream& out) const;
//private:
  L1Cache_State m_TBEState; /**< Transient state*/
  DataBlock m_DataBlk; /**< data for the block, required for concurrent writebacks*/
  bool m_Trans; /**< Is this block part of a the current transaction?*/
  bool m_Logged; /**< Has this block been logged in the current transaction?*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const L1Cache_TBE& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const L1Cache_TBE& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // L1Cache_TBE_H
