// SPDX-License-Identifier: GPL-3.0-only

#include "hello1.h"

MODULE_AUTHOR("Malashki Viacheslav");
MODULE_DESCRIPTION("Hello1 advanced, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

LIST_HEAD(list);

int print_hello(uint count)
{
	if (count == 0) {
		pr_warn("Small value of 'count'!\n");
	} else if (count > 5 && count <= 10) {
		pr_warn("Big value of 'count'!\n");
	} else if (count > 0 && count <= 5) {
		int i = 0;

		for (; i < count; i++) {
			data = kmalloc(sizeof(*data), GFP_KERNEL);
			ktime_t before = ktime_get();

			pr_alert("Hello, world!\n");
			data->time = ktime_sub(ktime_get(), before);
			list_add_tail(&(data->list), &list);
		}
	} else {
		pr_err("Invalid value of 'count'!\n");
		return -EINVAL;
	}

	return 0;
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_info("hello1 init!\n");
	return 0;
}

static void __exit hello1_exit(void)
{

	list_for_each_safe(elem, safe, &list) {
		data = list_entry(elem, struct hello_data, list);
		pr_alert("print ktime: %lu\n", (unsigned long) data->time);
		list_del(elem);
		kfree(data);
	}
}

module_init(hello1_init);
module_exit(hello1_exit);
