#include <chaos.h>
#include <chaos/monolithic_examples.h>

#include <iostream>

#include "TestU01/suite.h"

// Chaos Machines

CHAOS_MACHINE_NCG x_0;
CHAOS_MACHINE_XORRING64 x_1;

// Pseudo-Random Number Generators

chaos::generators::xorshift<uint32_t, 1, 3, 10> x_2;
CHAOS_PRNG_ABYSSINIAN x_3;
chaos::generators::lcg<uint32_t, 48271, 0, 2147483647> x_4;
CHAOS_PRNG_KISS x_5;

////////////////////////////////////////////////////////////////////////////////

// Adapters (double is universal in this case)

double UNIF01_NEXT_ADAPTER0() { return CHAOS_DOUBLE_U32(x_0.pull()); }
double UNIF01_NEXT_ADAPTER1() { return CHAOS_DOUBLE_U64(x_1.pull()); }
double UNIF01_NEXT_ADAPTER2() { return CHAOS_DOUBLE_U32(x_2.next()); }
double UNIF01_NEXT_ADAPTER3() { return CHAOS_DOUBLE_U32(x_3.next()); }
double UNIF01_NEXT_ADAPTER4() { return CHAOS_DOUBLE_U32(x_4.next()); }
double UNIF01_NEXT_ADAPTER5() { return CHAOS_DOUBLE_U32(x_5.next()); }

#if defined(BUILD_MONOLITHIC)
#define main chaos_testu01_main
#endif

int main(void) {
	unif01_Gen *gen;
	CHAOS_MACHINE_XORRING64 inst;
	gen = unif01_CreateExternGen01(inst.name.c_str(), UNIF01_NEXT_ADAPTER1);

	//////////////////////////////////////////////////////////////////////////////
	std::cout << "=== XORRING ==================================================="
	          << std::endl;
	chaos::analysis gen1(UNIF01_NEXT_ADAPTER1);
	gen1.raport();
	std::cout << "=== XORSHIFT =================================================="
	          << std::endl;
	chaos::analysis gen2(UNIF01_NEXT_ADAPTER2);
	gen2.raport();
	std::cout << "=== ABYSSINIAN ================================================"
	          << std::endl;
	chaos::analysis gen3(UNIF01_NEXT_ADAPTER3);
	gen3.raport();
	std::cout << "=== KISS ======================================================"
	          << std::endl;
	chaos::analysis gen5(UNIF01_NEXT_ADAPTER5);
	gen5.raport();
	std::cout << "=== LCG ======================================================="
	          << std::endl;
	chaos::analysis gen4(UNIF01_NEXT_ADAPTER4);
	gen4.raport();
	std::cout << "=== NCG ======================================================="
	          << std::endl;
	chaos::analysis gen0(UNIF01_NEXT_ADAPTER0);
	gen0.raport();
	//////////////////////////////////////////////////////////////////////////////

#if 0
	smarsa_BirthdaySpacings(gen, NULL, 1, 1000, 0, 10000, 2, 1);
	smarsa_BirthdaySpacings(gen, NULL, 1, 10000, 0, 1000000, 2, 1);

	smarsa_BirthdaySpacings(gen, NULL, 3, 200000, 14, 256, 8, 1);
	smarsa_BirthdaySpacings(gen, NULL, 3, 20000000, 14, 256, 8, 1);

	bbattery_BlockAlphabit(gen, 1024 * 1024, 0, 8);
	bbattery_Alphabit(gen, 1024 * 1024, 0, 8);

	bbattery_FIPS_140_2(gen);
	bbattery_Rabbit(gen, 10000000);
#endif

	bbattery_pseudoDIEHARD(gen);

#if 0
	bbattery_SmallCrush(gen);
	bbattery_Crush(gen);
	bbattery_BigCrush(gen);
#endif

	//////////////////////////////////////////////////////////////////////////////

	unif01_DeleteExternGenBits(gen);

	return 0;
}
