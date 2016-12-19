/** \file L1Cache_Entry.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef L1Cache_Entry_H
#define L1Cache_Entry_H

#include "Global.h"
#include "Allocator.h"
#include "L1Cache_State.h"
#include "DataBlock.h"
#include "AbstractCacheEntry.h"
class L1Cache_Entry :  public AbstractCacheEntry {
public:
  L1Cache_Entry() 
  : AbstractCacheEntry()
  {
    m_CacheState = L1Cache_State_NUM; // default value of L1Cache_State
    m_Dirty = false; // default value of bool
    // m_DataBlk has no default
  }
  ~L1Cache_Entry() { };
  L1Cache_Entry(const L1Cache_State& local_CacheState, const bool& local_Dirty, const DataBlock& local_DataBlk)
  : AbstractCacheEntry()
  {
    m_CacheState = local_CacheState;
    m_Dirty = local_Dirty;
    m_DataBlk = local_DataBlk;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for CacheState field.
  * \return CacheState field
  */
  const L1Cache_State& getCacheState() const { return m_CacheState; }
/** \brief Const accessor method for Dirty field.
  * \return Dirty field
  */
  const bool& getDirty() const { return m_Dirty; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for CacheState field.
  * \return CacheState field
  */
  L1Cache_State& getCacheState() { return m_CacheState; }
/** \brief Non-const accessor method for Dirty field.
  * \return Dirty field
  */
  bool& getDirty() { return m_Dirty; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }

  // Mutator methods for each field
/** \brief Mutator method for CacheState field */
  void setCacheState(const L1Cache_State& local_CacheState) { m_CacheState = local_CacheState; }
/** \brief Mutator method for Dirty field */
  void setDirty(const bool& local_Dirty) { m_Dirty = local_Dirty; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }

  void print(ostream& out) const;
//private:
  L1Cache_State m_CacheState; /**< cache state*/
  bool m_Dirty; /**< Is the data dirty (different than memory)?*/
  DataBlock m_DataBlk; /**< data for the block*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const L1Cache_Entry& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const L1Cache_Entry& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // L1Cache_Entry_H
