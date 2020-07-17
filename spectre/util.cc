#include "util.h"

namespace spectre
{
    /* 获取线程ID的两种方式:
     * 1、gettid()。glibc未实现此函数，只能通过系统调用来获取。这是真实的tid
     * 2、pthread_self()获取，类型为pthread_t。此id只能在进程中唯一标识一个线程，如果要在系统范围内使用，必须使用真实的线程id。
     */
    pid_t GetThreadId()
    {
        return syscall(SYS_gettid);
    }

    uint32_t GetFiberId()
    {
        //待完善
        return 0;
    }
}
