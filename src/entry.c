#include <linux/kprobes.h>
#include <linux/module.h>

#include "hooks.h"
#include "kprobe_hooking.h"

static struct kprobe hook_list[] = {
  HOOK_PRE("__x64_sys_write", &x64_sys_write_hk),
  HOOKS_END
};

static int __init example_init(void) {
  if (install_hooks(hook_list) < 0)
    return 1;

  printk(KERN_INFO "Hooked functions successfully\n");
  return 0;
}

static void __exit example_exit(void) {
  printk(KERN_INFO "Unhooking everything and exiting\n");
  uninstall_hooks(hook_list);
}

module_init(example_init);
module_exit(example_exit);

MODULE_LICENSE("GPL");
