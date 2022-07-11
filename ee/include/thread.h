#pragma once

#include <stddef.h>

struct gore_thread {
	void *entry;
	void *sp_base;
	char thread_state[0x84];
};

// Only call in kernel
void gore_thread_exec(struct gore_thread *thread);

struct gore_thread *gore_thread_create(size_t size, void *entry);
int gore_thread_destroy();
void gore_thread_yield();
