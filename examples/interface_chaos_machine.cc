#include <chaos.h>

CHAOS_MACHINE_XORRING64 machine;

#if defined(BUILD_MONOLITHIC)
#define main chaos_machine_interface_main
#endif

int main(void) {
	uint64_t a = 0x84242f96eca9c41d, b = 0xa3c65b8776f96855, c;

	// PUSH
	machine.push(a);
	machine << b;

	// PULL
	machine.pull();
	machine >> c;
	machine();

	return 0;
}
