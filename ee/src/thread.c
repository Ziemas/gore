#include "thread.h"

#include <stdlib.h>

extern void gore_task_switch(char *cur_state, char *next_state);

static char kernel_state[0x58];
static struct gore_thread *current_thread;

struct gore_thread *
gore_thread_create(size_t size, void *entry)
{
	struct gore_thread *thread = malloc(sizeof(struct gore_thread));
	char *stack = malloc(size);
	long *p;

	thread->sp_base = stack;
	p = (long *)(thread->thread_state + 72);

	*p = (long)entry;
	p++;
	*p = (long)stack;

	return thread;
}

int
gore_thread_destroy(struct gore_thread *thread)
{
	free(thread->sp_base);
	free(thread);

	return 0;
}

void
gore_thread_exec(struct gore_thread *thread)
{
	current_thread = thread;
	gore_task_switch(kernel_state, thread->thread_state);
	current_thread = NULL;
}

void
gore_thread_yield()
{
	gore_task_switch(current_thread->thread_state, kernel_state);
}
