#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>


char *mem_spvm = NULL;
struct kmem_cache *my_cachep = NULL;
void *object = NULL;
static int __init my_init(void)
{
    my_cachep = kmem_cache_create("zhaogang",35,0,SLAB_HWCACHE_ALIGN,NULL);
	if(my_cachep == NULL) 
		printk("failed!!\n");
	else
	{
		
		printk("add:[%p] size[%d] \n",my_cachep,kmem_cache_size(my_cachep));
		object = kmem_cache_alloc(my_cachep,GFP_KERNEL);
		if(object == NULL)
		{
			printk("dddddddddddddd\n");
		}
		printk("add:[%p] size[%d] 0x%lx \n",my_cachep,kmem_cache_size(my_cachep),(unsigned long )object);
	}
	  
    return 0;
}

static void  __exit my_exit(void)
{
	if(my_cachep)
	{
		kmem_cache_destroy(my_cachep);
	}
    printk("module exit hello\n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("Dragon");
MODULE_LICENSE("GPL");
