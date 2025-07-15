
add_executable(test-base-cds test-cds.cc)
add_executable(test-sim-module test-module.cc)
target_link_libraries(test-sim-module sim-csp)

add_test(base-cds test-base-cds)
add_test(sim-module test-sim-module)
