cmd_/root/module/gfp_kernel_user/gfp_kernel_user.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /root/module/gfp_kernel_user/gfp_kernel_user.ko /root/module/gfp_kernel_user/gfp_kernel_user.o /root/module/gfp_kernel_user/gfp_kernel_user.mod.o ;  true