set(header_files
drones/drone.h)

add_library(Headers INTERFACE ${header_files})
target_include_directories(Headers INTERFACE .)
install(DIRECTORY . DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.h")