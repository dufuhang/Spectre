#ifndef __SPECTRE_UTIL_H__
#define __SPECTRE_UTIL_H__

#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdint.h>

namespace spectre
{
    //获取线程ID
    pid_t GetThreadId();
    //获取协程ID
    uint32_t GetFiberId();
}

#endif
