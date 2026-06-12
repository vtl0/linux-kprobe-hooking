#include <linux/kprobes.h>
#include <linux/string.h>
#include <linux/uaccess.h>

#include "hooks.h"

int x64_sys_write_hk(struct kprobe *probe, struct pt_regs *regs) {
  char copied_buf[16];
  struct pt_regs *usermode_regs = (struct pt_regs *)regs->di;
  const char *buf = (const char *)usermode_regs->si;
  size_t count = usermode_regs->dx;
  int fd = usermode_regs->di;

  if (fd == 1 /* STDOUT_FILENO */) {
    if (copy_from_user(copied_buf, buf, 12) == 0) {
      copied_buf[12] = '\0';
      if (strcmp(copied_buf, "Hello World!") == 0) {
        printk(KERN_INFO "Hello world indeed!\n");
      }
    }
  }

  return 0;
}
