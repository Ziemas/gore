#include "irx_imports.h"

static int thread_id = -1;

void
gore_thread(void* param)
{
    SleepThread();
}

int
_start()
{
    iop_thread_t thread;

    printf("-- GORE IOP SERVICE BOOT --\n");

    thread.attr = TH_C;
    thread.thread = &gore_thread;
    thread.priority = 50;
    thread.stacksize = 0x800;

    thread_id = CreateThread(&thread);
    StartThread(thread_id, NULL);

    return 0;
}
