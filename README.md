# Kernel Probe Hooking

Demonstration of kernel probe hooking through kprobes. Works in new kernel versions where syscall tables are not a thing anymore.

Useful resource for hooking syscalls: https://syscalls.mebeim.net/?table=x86/64/x64/latest

### Testing

Go to src/, run make, insmod hooker.ko, then run echo "Hello World!"
After that, a message should appear on dmesg
