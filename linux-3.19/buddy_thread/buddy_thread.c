#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/cpumask.h>
#include <linux/smp.h>
#include <linux/signal.h>
//#include <sched.h>

asmlinkage long sys_buddy_thread_start(pid_t buddy_pid) {
	
	struct task_struct* p;
	printk("Starting\n");
	p = find_task_by_vpid(buddy_pid);
	//current->bt = get_pid_task(&buddy_pid, PIDTYPE_PID);
	printk("Got task\n");
	current->bt = p;
	//current->bt_init = 22;
	printk("Set task\n");
	current->bt_init = 22;
	printk("Set init\n");
	current->bt->bt = NULL;
	printk("Nulled bt->bt\n");
	return 0;	
	
	
//	struct task_struct *parent = current; //For the buddy
//
//	/* First set the appropriate CPU affinities so the processes
//	 * are always together
//	 */	
//	cpumask_t mask;
//	unsigned cpu = get_cpu();
//
//	/* Determine if we are child process */
//	pid_t pid = fork();
//	if(pid == 0) {
//		parent->bt = current;
//		current->bt = NULL;
//		/* Determine buddy thread placement */
//		if(cpu % 2)
//			CPU_SET(cpu-1, &mask);
//		else
//			CPU_SET(cpu+1, &mask);
//	}
//	else {
//		CPU_SET(cpu, &mask);
//	}
//	
//	if(sched_setaffinity(0, sizeof(struct cpu_set_t), &mask) != 0) {
//		printk("Error setting affinity\n");
//	}
//
//	/* TODO: SET BUDDY THREAD TO EXECUTE WITH execl() */
//
//	printk("Added buddy thread");
//	return 0;
}
