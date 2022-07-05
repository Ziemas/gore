#include <sbv_patches.h>

int
main()
{
    sbv_patch_enable_lmb();
    sbv_patch_disable_prefix_check();
    sbv_patch_fileio();
}
