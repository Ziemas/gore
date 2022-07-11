#include "gore.h"
#include "thread.h"

#include <debug.h>
#include <iopcontrol.h>
#include <kernel.h>
#include <loadfile.h>
#include <sbv_patches.h>
#include <sifrpc.h>
#include <stdbool.h>
#include <stdio.h>

static s32 vb_sema = 0;

s32
vblank_handler()
{
	iSignalSema(vb_sema);
	return 0;
}

void
foo_thread()
{
	while (true) {
		scr_printf("hello from foo_thread\n");
		gore_thread_yield();
	}
}

void
bar_thread()
{
	while (true) {
		scr_printf("hello from bar_thread\n");
		gore_thread_yield();
	}
}

int
main()
{
	ee_sema_t vblank_sema = {};

	struct gore_thread *threads[2];

	sbv_patch_enable_lmb();
	sbv_patch_disable_prefix_check();
	sbv_patch_fileio();

	init_scr();
	scr_clear();

	//SifInitRpc(0);

	//while (!SifIopReboot("host:ioprp300.img"))
	//	;
	//while (!SifIopSync())
	//	;

	//SifInitRpc(0);

	SifLoadModule("host:gore.irx", 0, NULL);

	vblank_sema.init_count = 1;
	vblank_sema.max_count = 2;
	vb_sema = CreateSema(&vblank_sema);

	AddIntcHandler(INTC_VBLANK_E, vblank_handler, 0);
	EnableIntc(INTC_VBLANK_E);

	scr_printf("-- GORE EE SERVICE --\n");

	threads[0] = gore_thread_create(0x900, foo_thread);
	threads[1] = gore_thread_create(0x900, bar_thread);

	while (true) {
		WaitSema(vb_sema);
		gore_thread_exec(threads[0]);
		gore_thread_exec(threads[1]);
	}

	return 0;
}
