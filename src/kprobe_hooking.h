#ifndef KPROBE_HOOKING_H_
#define KPROBE_HOOKING_H_

#include <linux/kprobes.h>
#include <linux/ptrace.h>

#define HOOK_PRE(_name, _function)              \
  {.symbol_name = _name, .pre_handler = _function}
#define HOOK_POST(_name, _function)             \
  {.symbol_name = _name, .post_handler = _function}
#define HOOKS_END                               \
  {.symbol_name = NULL, .addr = NULL}

int install_hooks(struct kprobe *list);
void uninstall_hooks(struct kprobe *list);

#endif // KPROBE_HOOKING_H_
