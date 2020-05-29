
/* �ο�drivers\input\keyboard\gpio_keys.c */

#include <linux/module.h>
#include <linux/version.h>

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/sched.h>
#include <linux/pm.h>
#include <linux/sysctl.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/irq.h>

static struct input_dev *buttons_dev;

static int buttons_init(void)
{
	//int i;
	
	/* 1. ����һ��input_dev�ṹ�� */
	buttons_dev = input_allocate_device();;

	/* 2. ���� */
	/* 2.1 �ܲ��������¼� */
	set_bit(EV_KEY, buttons_dev->evbit);
	//set_bit(EV_REP, buttons_dev->evbit);
	
	/* 2.2 �ܲ���������������Щ�¼�: L,S,ENTER,LEFTSHIT */
	set_bit(KEY_A, buttons_dev->keybit);//ע����һ�������¼�
	set_bit(700, buttons_dev->keybit);//ע����һ�������¼�
	
	//������֤�£��������ö��ٸ�����ֵ
	
	//set_bit(KEY_S, buttons_dev->keybit);
	//set_bit(KEY_ENTER, buttons_dev->keybit);
	//set_bit(KEY_LEFTSHIFT, buttons_dev->keybit);

	/* 3. ע�� */
	//����/dev/input����һ��event
	//crw-rw----  1 root input 13, 70 5��  29 21:47 event6
	input_register_device(buttons_dev);
	
	/* 4. Ӳ����صĲ��� */
	//init_timer(&buttons_timer);
	//buttons_timer.function = buttons_timer_function;
	//add_timer(&buttons_timer);
	
	//for (i = 0; i < 4; i++)
	//{
	//	request_irq(pins_desc[i].irq, buttons_irq, IRQT_BOTHEDGE, pins_desc[i].name, &pins_desc[i]);
	//}
	
	return 0;
}

static void buttons_exit(void)
{
	//int i;
	//for (i = 0; i < 4; i++)
	//{
	//	free_irq(pins_desc[i].irq, &pins_desc[i]);
	//}

	//del_timer(&buttons_timer);
	input_unregister_device(buttons_dev);
	input_free_device(buttons_dev);
	printk("exit input subsystem \n");
}



module_init(buttons_init);

module_exit(buttons_exit);

MODULE_LICENSE("GPL");



