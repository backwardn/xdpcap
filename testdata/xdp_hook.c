/**
 * Definitions expected to be provided by the loader
 * newtools and libbpf support the same basic definitions
 */
struct bpf_map_def {
	unsigned int type;
	unsigned int key_size;
	unsigned int value_size;
	unsigned int max_entries;
    unsigned int flags;
};

int tail_call(void *ctx, void *map, int index);

#include "../hook.h"

#define __section(NAME) __attribute__((section(NAME), used))

__section("license")
char __license[] = "BSD";

/**
 * Example / test XDP program that exposes packets through an xdpcap hook.
 */
__section("test_hook") int xdp_hook(struct xdp_md *ctx) {
	return xdpcap_exit(ctx, XDP_PASS);
}

/**
 * Second entrypoint that doesn't use xdpcap exit() to test patching.
 */
__section("test_nohook") int xdp_nohook(struct xdp_md *ctx) {
    return XDP_PASS;
}
