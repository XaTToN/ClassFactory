include_directories(
	${CMAKE_SOURCE_DIR}/include/
)

add_executable(FactoryExample main.cpp)
target_link_libraries(FactoryExample ClassFactory) 
set_target_properties(FactoryExample PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)