#include <linux/kthread.h>
#include <linux/time.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/nmi.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/highmem.h>
#include <linux/interrupt.h>
#include <linux/capability.h>
#include <linux/completion.h>
#include <linux/kernel_stat.h>
#include <linux/debug_locks.h>
#include <linux/perf_event.h>
#include <linux/security.h>
#include <linux/notifier.h>
#include <linux/profile.h>
#include <linux/freezer.h>
#include <linux/vmalloc.h>
#include <linux/blkdev.h>
#include <linux/delay.h>
#include <linux/pid_namespace.h>
#include <linux/smp.h>
#include <linux/threads.h>
#include <linux/timer.h>
#include <linux/rcupdate.h>
#include <linux/cpu.h>
#include <linux/cpuset.h>
#include <linux/percpu.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sysctl.h>
#include <linux/syscalls.h>
#include <linux/times.h>
#include <linux/tsacct_kern.h>
#include <linux/kprobes.h>
#include <linux/delayacct.h>
#include <linux/unistd.h>
#include <linux/pagemap.h>
#include <linux/hrtimer.h>
#include <linux/tick.h>
#include <linux/debugfs.h>
#include <linux/ctype.h>
#include <linux/ftrace.h>
#include <linux/slab.h>
#include <linux/init_task.h>
#include <linux/binfmts.h>
#include <linux/string.h>

#include <linux/slab_def.h>

struct list_head  *pos;
struct kmem_cache *kc;

static int __init my_init(void)
{

	
	static unsigned long * slab_caches;
	slab_caches = (void *)kallsyms_lookup_name("slab_caches");//获取slab链表的首地址
	 
	printk("slab_caches add:%p \n",slab_caches);
	
	list_for_each(pos,(struct list_head  *)slab_caches) //遍历所有的结构体
	{
		kc = list_entry( pos , struct kmem_cache , list);
		printk("name:%s \t\t%d",kc->name ,kc->size );
		
	}
	
   
	
    return 0;
}

static void  __exit my_exit(void)
{

	
    printk("module exit hello\n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("Dragon");
MODULE_LICENSE("GPL");
