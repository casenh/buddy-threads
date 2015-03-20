#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/cpumask.h>
#include <linux/smp.h>
#include <linux/signal.h>
//#include <sched.h>

asmlinkage long sys_buddy_thread_start(pid_t buddy_pid) {
	
	struct task_struct* p;
	p = find_task_by_vpid(buddy_pid);
	printk("Got task\n");
	current->bt = p;
	printk("Set task\n");
	current->bt_init = 0;
	printk("Set init\n");
	current->bt->bt = NULL;
	printk("Nulled bt->bt\n");
	return 0;	
}
