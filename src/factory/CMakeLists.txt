set(HEADER_FILES 
		${CMAKE_SOURCE_DIR}/include/ClassFactory/LCF.h
		${CMAKE_SOURCE_DIR}/include/ClassFactory/detail/ClassFactory.h
		${CMAKE_SOURCE_DIR}/include/ClassFactory/detail/ClassAllocator.h
		${CMAKE_SOURCE_DIR}/include/ClassFactory/detail/Registration.h
		${CMAKE_SOURCE_DIR}/include/ClassFactory/detail/Singleton.h
)

include_directories(
	${CMAKE_SOURCE_DIR}/include/
)

add_library(ClassFactory STATIC
	${HEADER_FILES}
	${CMAKE_CURRENT_SOURCE_DIR}/ClassFactory.cpp
)	

set_target_properties(ClassFactory PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)