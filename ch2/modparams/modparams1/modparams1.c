/*
 * ch2/modparams/modparams1/modparams1.c
 ***************************************************************
 * This program is part of the source code released for the book
 *  "Linux Kernel Development Cookbook"
 *  (c) Author: Kaiwan N Billimoria
 *  Publisher:  Packt
 *  GitHub repository:
 *  https://github.com/PacktPublishing/Linux-Kernel-Development-Cookbook
 *
 * From: Ch 2: Writing your First Kernel Module-the LKM Framework
 ****************************************************************
 * Brief Description:
 *
 * For details, please refer the book, Ch 2.
 */
#include <linux/init.h>
#include <linux/module.h>

#define OUR_MODNAME    "modparams1"
MODULE_AUTHOR("<insert your name here>");
MODULE_DESCRIPTION(
	"LKDC book:ch2/modparams/modparams1: module parameters demo LKM #1");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

/* Module parameters */
static int mp_debug_level;
module_param(mp_debug_level, int, 0660);
MODULE_PARM_DESC(mp_debug_level,
	"Debug level [0-2]; 0 => no debug messages, 2 => high verbosity");

static char *mp_strparam = "My string param";
module_param(mp_strparam, charp, 0660);
MODULE_PARM_DESC(mp_strparam, "A demo string parameter");

static int __init modparams1_init(void)
{
	pr_info("%s: inserted\n", OUR_MODNAME);
	pr_info("module parameters passed: mp_debug_level=%d mp_strparam=%s\n",
		mp_debug_level, mp_strparam);
	return 0;		/* success */
}

static void __exit modparams1_exit(void)
{
	pr_info("module parameters passed: mp_debug_level=%d mp_strparam=%s\n",
		mp_debug_level, mp_strparam);
	pr_info("%s: removed\n", OUR_MODNAME);
}

module_init(modparams1_init);
module_exit(modparams1_exit);