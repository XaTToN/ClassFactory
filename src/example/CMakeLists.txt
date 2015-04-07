add_executable(FactoryExample main.cpp)
target_link_libraries(FactoryExample LINK_PUBLIC ClassFactory) 

set_target_properties(FactoryExample PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)