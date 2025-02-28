#include <linux/kprobes.h>

#include "kprobe_hooking.h"

int install_hooks(struct kprobe *list) {
  int i, j;

  // loop until a invalid entry
  for (i = 0; list[i].symbol_name || list[i].addr; i++) {
    // not a valid hook, ignore
    if (list[i].pre_handler == NULL && list[i].post_handler == NULL)
      continue;

    if (register_kprobe(&list[i]) < 0) {
      if (list[i].symbol_name)
        printk(KERN_ERR "Failed to hook %s\n", list[i].symbol_name);
      else
        printk(KERN_ERR "Failed to hook %p\n", list[i].addr);
      // unregister all registered before returning
      for (j = 0; j < i; j++)
        unregister_kprobe(&list[j]);

      return -1;
    }
  }

  return 0;
}

void uninstall_hooks(struct kprobe *list) {
  int i;
  // loop until a invalid entry
  for (i = 0; list[i].symbol_name && list[i].addr; i++)
    unregister_kprobe(&list[i]);
}
