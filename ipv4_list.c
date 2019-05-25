/**
* Description: kenrel module to list all ipv4
* Date: 2019-05-25
*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/inetdevice.h>

void get_ipv4_list(void)
{
    struct net_device *dev = NULL;
    struct in_device *in_dev = NULL;
    struct in_ifaddr *ifa = NULL;
    int i = 0;

    dev = first_net_device(&init_net);
    while(dev) {
        in_dev = __in_dev_get_rtnl(dev);
        if (!in_dev)
            return;
        i = 0;
        printk(KERN_INFO"    Network interface[%s]\n",dev->name);
        for (ifa = in_dev->ifa_list; ifa; ifa = ifa->ifa_next) {
	        printk(KERN_INFO "        IP addr[%d]: %pI4\n", i++, &ifa->ifa_local);
        }
        dev = next_net_device(dev);
    }
    return;
}

static int ipv4_list_init(void)
{
    get_ipv4_list();		
	return 0;
}

static void ipv4_list_exit(void)
{
}

module_init(ipv4_list_init);
module_exit(ipv4_list_exit);

MODULE_AUTHOR("Liang Wang");
MODULE_LICENSE("GPL");
