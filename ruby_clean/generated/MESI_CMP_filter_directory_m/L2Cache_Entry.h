/** \file L2Cache_Entry.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef L2Cache_Entry_H
#define L2Cache_Entry_H

#include "Global.h"
#include "Allocator.h"
#include "L2Cache_State.h"
#include "NetDest.h"
#include "MachineID.h"
#include "DataBlock.h"
#include "AbstractCacheEntry.h"
class L2Cache_Entry :  public AbstractCacheEntry {
public:
  L2Cache_Entry() 
  : AbstractCacheEntry()
  {
    m_CacheState = L2Cache_State_NP; // default value of L2Cache_State
    // m_Sharers has no default
    // m_Exclusive has no default
    // m_DataBlk has no default
    m_Dirty = false; // default for this field 
    m_Trans = false; // default value of bool
    m_Read = false; // default value of bool
    m_Write = false; // default value of bool
    m_L2Miss = false; // default value of bool
    m_L1PutsPending = 0; // default for this field 
  }
  ~L2Cache_Entry() { };
  L2Cache_Entry(const L2Cache_State& local_CacheState, const NetDest& local_Sharers, const MachineID& local_Exclusive, const DataBlock& local_DataBlk, const bool& local_Dirty, const bool& local_Trans, const bool& local_Read, const bool& local_Write, const bool& local_L2Miss, const int& local_L1PutsPending)
  : AbstractCacheEntry()
  {
    m_CacheState = local_CacheState;
    m_Sharers = local_Sharers;
    m_Exclusive = local_Exclusive;
    m_DataBlk = local_DataBlk;
    m_Dirty = local_Dirty;
    m_Trans = local_Trans;
    m_Read = local_Read;
    m_Write = local_Write;
    m_L2Miss = local_L2Miss;
    m_L1PutsPending = local_L1PutsPending;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for CacheState field.
  * \return CacheState field
  */
  const L2Cache_State& getCacheState() const { return m_CacheState; }
/** \brief Const accessor method for Sharers field.
  * \return Sharers field
  */
  const NetDest& getSharers() const { return m_Sharers; }
/** \brief Const accessor method for Exclusive field.
  * \return Exclusive field
  */
  const MachineID& getExclusive() const { return m_Exclusive; }
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
/** \brief Const accessor method for Read field.
  * \return Read field
  */
  const bool& getRead() const { return m_Read; }
/** \brief Const accessor method for Write field.
  * \return Write field
  */
  const bool& getWrite() const { return m_Write; }
/** \brief Const accessor method for L2Miss field.
  * \return L2Miss field
  */
  const bool& getL2Miss() const { return m_L2Miss; }
/** \brief Const accessor method for L1PutsPending field.
  * \return L1PutsPending field
  */
  const int& getL1PutsPending() const { return m_L1PutsPending; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for CacheState field.
  * \return CacheState field
  */
  L2Cache_State& getCacheState() { return m_CacheState; }
/** \brief Non-const accessor method for Sharers field.
  * \return Sharers field
  */
  NetDest& getSharers() { return m_Sharers; }
/** \brief Non-const accessor method for Exclusive field.
  * \return Exclusive field
  */
  MachineID& getExclusive() { return m_Exclusive; }
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
/** \brief Non-const accessor method for Read field.
  * \return Read field
  */
  bool& getRead() { return m_Read; }
/** \brief Non-const accessor method for Write field.
  * \return Write field
  */
  bool& getWrite() { return m_Write; }
/** \brief Non-const accessor method for L2Miss field.
  * \return L2Miss field
  */
  bool& getL2Miss() { return m_L2Miss; }
/** \brief Non-const accessor method for L1PutsPending field.
  * \return L1PutsPending field
  */
  int& getL1PutsPending() { return m_L1PutsPending; }

  // Mutator methods for each field
/** \brief Mutator method for CacheState field */
  void setCacheState(const L2Cache_State& local_CacheState) { m_CacheState = local_CacheState; }
/** \brief Mutator method for Sharers field */
  void setSharers(const NetDest& local_Sharers) { m_Sharers = local_Sharers; }
/** \brief Mutator method for Exclusive field */
  void setExclusive(const MachineID& local_Exclusive) { m_Exclusive = local_Exclusive; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Dirty field */
  void setDirty(const bool& local_Dirty) { m_Dirty = local_Dirty; }
/** \brief Mutator method for Trans field */
  void setTrans(const bool& local_Trans) { m_Trans = local_Trans; }
/** \brief Mutator method for Read field */
  void setRead(const bool& local_Read) { m_Read = local_Read; }
/** \brief Mutator method for Write field */
  void setWrite(const bool& local_Write) { m_Write = local_Write; }
/** \brief Mutator method for L2Miss field */
  void setL2Miss(const bool& local_L2Miss) { m_L2Miss = local_L2Miss; }
/** \brief Mutator method for L1PutsPending field */
  void setL1PutsPending(const int& local_L1PutsPending) { m_L1PutsPending = local_L1PutsPending; }

  void print(ostream& out) const;
//private:
  L2Cache_State m_CacheState; /**< cache state*/
  NetDest m_Sharers; /**< tracks the L1 shares on-chip*/
  MachineID m_Exclusive; /**< Exclusive holder of block*/
  DataBlock m_DataBlk; /**< data for the block*/
  bool m_Dirty; /**< data is dirty*/
  bool m_Trans; /**< dummy bit for debugging*/
  bool m_Read; /**< LogTM R bit*/
  bool m_Write; /**< LogTM W bit*/
  bool m_L2Miss; /**< Was this block sourced from memory*/
  int m_L1PutsPending; /**< how many  PUT_ are pending for this entry (being recyled)*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const L2Cache_Entry& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const L2Cache_Entry& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // L2Cache_Entry_H
