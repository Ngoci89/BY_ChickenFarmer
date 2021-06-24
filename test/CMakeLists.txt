set(test_files 
droneTest.cpp)

include(GoogleTest)

add_executable(drones_test ${test_files})
target_link_libraries(drones_test drones gtest_main)
gtest_discover_tests(drones_test)