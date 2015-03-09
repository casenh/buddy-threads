#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/cpumask.h>
#include <linux/smp.h>
#include <linux/signal.h>
//#include <sched.h>

asmlinkage long sys_buddy_thread_start(struct pid buddy_pid) {

	current->bt = get_pid_task(&buddy_pid, PIDTYPE_PID);
	current->bt->bt = NULL;
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
