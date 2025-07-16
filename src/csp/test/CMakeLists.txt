
add_executable(test-base-cds base-cds.cc)
add_executable(test-sim-module sim-module.cc)
target_link_libraries(test-sim-module sim-csp)

add_test(csp-base-cds   test-base-cds)
add_test(csp-sim-module test-sim-module)
