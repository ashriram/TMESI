/** \file Directory_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef Directory_Event_H
#define Directory_Event_H

#include "Global.h"

/** \enum Directory_Event
  * \brief Directory events
  */
enum Directory_Event {
  Directory_Event_FIRST,
  Directory_Event_GETX = Directory_Event_FIRST,  /**< A GETX arrives */
  Directory_Event_GETS,  /**< A GETS arrives */
  Directory_Event_PUTX,  /**< A PUTX arrives */
  Directory_Event_PUTX_NotOwner,  /**< A PUTX arrives */
  Directory_Event_PUTO,  /**< A PUTO arrives */
  Directory_Event_Unblock,  /**< An unblock message arrives */
  Directory_Event_NUM
};
Directory_Event string_to_Directory_Event(const string& str);
string Directory_Event_to_string(const Directory_Event& obj);
Directory_Event &operator++( Directory_Event &e);
ostream& operator<<(ostream& out, const Directory_Event& obj);

#endif // Directory_Event_H
