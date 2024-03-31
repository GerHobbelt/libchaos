//
// part of Demo 
//

#pragma once

#if !defined(MONOLITHIC_TEMPLATE_DEMO)
#error "You are missing an include path pointing at your own monolithic_example.h as you are loading this template demo one instead!"
#endif

#if defined(BUILD_MONOLITHIC)

#ifdef __cplusplus
extern "C" {
#endif

int mbdemo1_main(int argc, const char** argv);
int mbdemo2_main(void);

#ifdef __cplusplus
}
#endif

#endif
#define main chaos_benchmark_graph_main
#define main chaos_file_checksum_main
#define main chaos_machine_interface_main
#define main chaos_interface_main
#define main chaos_long_period_urandom_main
#define main chaos_normal_dist_diagram_main
#define main chaos_tests_library_main
#define main chaos_tests_testU01_main
#define main chaos_truely_random_main
#define main chaos_deep_main
#define main chaos_sandbox_main
#define main chaos_testu01_main
