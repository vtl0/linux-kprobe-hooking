#ifndef HOOKS_H_
#define HOOKS_H_

#include <linux/kprobes.h>

int x64_sys_write_hk(struct kprobe *probe, struct pt_regs *regs);

#endif // HOOKS_H_
