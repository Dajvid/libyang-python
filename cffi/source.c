/*
 * Copyright (c) 2018-2019 Robin Jarry
 * SPDX-License-Identifier: MIT
 */

#include <libyang/libyang.h>

static char *lypy_node_fullname(const struct lys_node *node)
{
	const struct lys_module *module;
	char *fullname = NULL;

	module = lys_node_module(node);
	if (!module)
		return NULL;

	if (asprintf(&fullname, "%s:%s", module->name, node->name) < 0)
		return NULL;

	return fullname;
}

static LY_ERR lypy_get_errno(void)
{
	return ly_errno;
}

static void lypy_set_errno(LY_ERR err)
{
	ly_errno = err;
}

static uint8_t lypy_module_implemented(const struct lys_module *module)
{
	if (module)
		return module->implemented;
	return 0;
}
