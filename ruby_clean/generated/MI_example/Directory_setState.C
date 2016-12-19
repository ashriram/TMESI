/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "Directory_Controller.h"

void Directory_Controller::Directory_setState(Address param_addr, Directory_State param_state)
{
  if ((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).isPresent(param_addr))) {
    if ((param_state == Directory_State_I)) {
            if (ASSERT_FLAG && !((((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(param_addr))).m_Owner).count()) == (0)))) {
        cerr << "Runtime Error at ../protocols/MI_example-dir.sm:57, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

      }
;
            if (ASSERT_FLAG && !((((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(param_addr))).m_Sharers).count()) == (0)))) {
        cerr << "Runtime Error at ../protocols/MI_example-dir.sm:58, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

      }
;
    }
    if ((param_state == Directory_State_M)) {
            if (ASSERT_FLAG && !((((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(param_addr))).m_Owner).count()) == (1)))) {
        cerr << "Runtime Error at ../protocols/MI_example-dir.sm:62, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

      }
;
            if (ASSERT_FLAG && !((((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(param_addr))).m_Sharers).count()) == (0)))) {
        cerr << "Runtime Error at ../protocols/MI_example-dir.sm:63, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

      }
;
    }
    ((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(param_addr))).m_DirectoryState = param_state;
  }
}

