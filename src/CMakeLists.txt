set(source_files 
drone.cpp)

add_library(drones STATIC ${source_files})
target_link_libraries(drones Headers)

install(TARGETS drones
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)