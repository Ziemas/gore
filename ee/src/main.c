#include <iopcontrol.h>
#include <loadfile.h>
#include <sbv_patches.h>
#include <sifrpc.h>
#include <stdbool.h>

int
main()
{
    sbv_patch_enable_lmb();
    sbv_patch_disable_prefix_check();
    sbv_patch_fileio();

    SifInitRpc(0);

    while (!SifIopReboot("host:ioprp300.img"))
        ;
    while (!SifIopSync())
        ;

    SifInitRpc(0);

    SifLoadModule("host:gore.irx", 0, NULL);

    while (true)
        ;

    return 0;
}
