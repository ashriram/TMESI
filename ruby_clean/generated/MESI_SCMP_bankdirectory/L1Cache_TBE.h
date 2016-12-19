/** \file L1Cache_TBE.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef L1Cache_TBE_H
#define L1Cache_TBE_H

#include "Global.h"
#include "Allocator.h"
#include "Address.h"
#include "L1Cache_State.h"
#include "DataBlock.h"
class L1Cache_TBE {
public:
  L1Cache_TBE() 
  {
    // m_Address has no default
    m_TBEState = L1Cache_State_I; // default value of L1Cache_State
    // m_DataBlk has no default
    m_Dirty = false; // default for this field 
    m_Trans = false; // default for this field 
    m_Threat = false; // default for this field 
    m_TStore = false; // default for this field 
    m_FWD = false; // default for this field 
    m_isPrefetch = false; // default value of bool
    m_pendingAcks = 0; // default for this field 
  }
  ~L1Cache_TBE() { };
  L1Cache_TBE(const Address& local_Address, const L1Cache_State& local_TBEState, const DataBlock& local_DataBlk, const bool& local_Dirty, const bool& local_Trans, const bool& local_Threat, const bool& local_TStore, const bool& local_FWD, const bool& local_isPrefetch, const int& local_pendingAcks)
  {
    m_Address = local_Address;
    m_TBEState = local_TBEState;
    m_DataBlk = local_DataBlk;
    m_Dirty = local_Dirty;
    m_Trans = local_Trans;
    m_Threat = local_Threat;
    m_TStore = local_TStore;
    m_FWD = local_FWD;
    m_isPrefetch = local_isPrefetch;
    m_pendingAcks = local_pendingAcks;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for Address field.
  * \return Address field
  */
  const Address& getAddress() const { return m_Address; }
/** \brief Const accessor method for TBEState field.
  * \return TBEState field
  */
  const L1Cache_State& getTBEState() const { return m_TBEState; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for Dirty field.
  * \return Dirty field
  */
  const bool& getDirty() const { return m_Dirty; }
/** \brief Const accessor method for Trans field.
  * \return Trans field
  */
  const bool& getTrans() const { return m_Trans; }
/** \brief Const accessor method for Threat field.
  * \return Threat field
  */
  const bool& getThreat() const { return m_Threat; }
/** \brief Const accessor method for TStore field.
  * \return TStore field
  */
  const bool& getTStore() const { return m_TStore; }
/** \brief Const accessor method for FWD field.
  * \return FWD field
  */
  const bool& getFWD() const { return m_FWD; }
/** \brief Const accessor method for isPrefetch field.
  * \return isPrefetch field
  */
  const bool& getisPrefetch() const { return m_isPrefetch; }
/** \brief Const accessor method for pendingAcks field.
  * \return pendingAcks field
  */
  const int& getpendingAcks() const { return m_pendingAcks; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for Address field.
  * \return Address field
  */
  Address& getAddress() { return m_Address; }
/** \brief Non-const accessor method for TBEState field.
  * \return TBEState field
  */
  L1Cache_State& getTBEState() { return m_TBEState; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for Dirty field.
  * \return Dirty field
  */
  bool& getDirty() { return m_Dirty; }
/** \brief Non-const accessor method for Trans field.
  * \return Trans field
  */
  bool& getTrans() { return m_Trans; }
/** \brief Non-const accessor method for Threat field.
  * \return Threat field
  */
  bool& getThreat() { return m_Threat; }
/** \brief Non-const accessor method for TStore field.
  * \return TStore field
  */
  bool& getTStore() { return m_TStore; }
/** \brief Non-const accessor method for FWD field.
  * \return FWD field
  */
  bool& getFWD() { return m_FWD; }
/** \brief Non-const accessor method for isPrefetch field.
  * \return isPrefetch field
  */
  bool& getisPrefetch() { return m_isPrefetch; }
/** \brief Non-const accessor method for pendingAcks field.
  * \return pendingAcks field
  */
  int& getpendingAcks() { return m_pendingAcks; }

  // Mutator methods for each field
/** \brief Mutator method for Address field */
  void setAddress(const Address& local_Address) { m_Address = local_Address; }
/** \brief Mutator method for TBEState field */
  void setTBEState(const L1Cache_State& local_TBEState) { m_TBEState = local_TBEState; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Dirty field */
  void setDirty(const bool& local_Dirty) { m_Dirty = local_Dirty; }
/** \brief Mutator method for Trans field */
  void setTrans(const bool& local_Trans) { m_Trans = local_Trans; }
/** \brief Mutator method for Threat field */
  void setThreat(const bool& local_Threat) { m_Threat = local_Threat; }
/** \brief Mutator method for TStore field */
  void setTStore(const bool& local_TStore) { m_TStore = local_TStore; }
/** \brief Mutator method for FWD field */
  void setFWD(const bool& local_FWD) { m_FWD = local_FWD; }
/** \brief Mutator method for isPrefetch field */
  void setisPrefetch(const bool& local_isPrefetch) { m_isPrefetch = local_isPrefetch; }
/** \brief Mutator method for pendingAcks field */
  void setpendingAcks(const int& local_pendingAcks) { m_pendingAcks = local_pendingAcks; }

  void print(ostream& out) const;
//private:
  Address m_Address; /**< Physical address for this TBE*/
  L1Cache_State m_TBEState; /**< Transient state*/
  DataBlock m_DataBlk; /**< Buffer for the data block*/
  bool m_Dirty; /**< data is dirty*/
  bool m_Trans; /**< data is Transactional*/
  bool m_Threat; /**< data is threatened*/
  bool m_TStore; /**< I am writing. Helps note down conflicts.*/
  bool m_FWD; /**< Another L1 Forwarded data; assume L2 stall so when unblocking forward data to L2*/
  bool m_isPrefetch; /**< Set if this was caused by a prefetch*/
  int m_pendingAcks; /**< number of pending acks*/
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
