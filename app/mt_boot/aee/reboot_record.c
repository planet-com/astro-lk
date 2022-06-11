#include <string.h>
#include <arch/ops.h>
#include <dev/mrdump.h>
#include <debug.h>
#include "aee.h"
#include "mrdump_private.h"

struct mrdump_control_block *mrdump_cb_addr(void)
{
	/* directly return the address of debug service on SRAM */
	return (struct mrdump_control_block *)MRDUMP_CB_ADDR;
}

int mrdump_cb_size(void)
{
	return MRDUMP_CB_SIZE;
}

int aee_mrdump_get_info(struct mrdump_control_block *mcb)
{
	if (mcb == NULL)
		return -1;

	struct mrdump_control_block *bufp = NULL;

	memset(mcb, 0, sizeof(struct mrdump_control_block));

	bufp = mrdump_cb_addr();
	if (bufp == NULL)
		return -2;

	if (memcmp(bufp->sig, MRDUMP_GO_DUMP, 8) == 0) {
		memcpy(mcb, bufp, sizeof(struct mrdump_control_block));
		return 0;
	} else {
		return -3;
	}
}

struct mrdump_control_block *aee_mrdump_get_params(void)
{
	struct mrdump_control_block *bufp = mrdump_cb_addr();
	if (bufp == NULL) {
		dprintf(CRITICAL, "mrdump_cb is NULL\n");
		return NULL;
	}
	if (memcmp(bufp->sig, MRDUMP_GO_DUMP, 8) == 0) {
		bufp->sig[0] = 'X';
		aee_mrdump_flush_cblock(bufp);
		dprintf(CRITICAL, "Boot record found at %p[%02x%02x]\n", bufp, bufp->sig[0], bufp->sig[1]);
		return bufp;
	} else {
		dprintf(CRITICAL, "No Boot record found\n");
		return NULL;
	}
}

void aee_mrdump_flush_cblock(struct mrdump_control_block *bufp)
{
	if (bufp != NULL) {
		arch_clean_cache_range((addr_t)bufp, sizeof(struct mrdump_control_block));
	}
}
