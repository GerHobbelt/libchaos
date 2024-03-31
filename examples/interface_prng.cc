#include <chaos.h>

CHAOS_PRNG_XOROSHIRO128PLUS prng;

#if defined(BUILD_MONOLITHIC)
#define main chaos_interface_main
#endif

int main(void) {
	uint64_t a = 0x84242f96eca9c41d, b = 0xa3c65b8776f96855, c, check = 0;

	// SEED
	prng.seed(a);
	prng << b;

	// NEXT
	c = prng.next();
	check += c;
	c << prng;
	check += c;
	c = prng();
	check += c;

	int rv = (check != 0x1);
	if (rv)
		printf("Test failed.\n");

	return rv;
}
