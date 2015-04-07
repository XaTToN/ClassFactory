set(HEADER_FILES 
		${CMAKE_CURRENT_SOURCE_DIR}/libClassFactory.h
		${CMAKE_CURRENT_SOURCE_DIR}/detail/ClassFactory.h
		${CMAKE_CURRENT_SOURCE_DIR}/detail/ClassAllocator.h
		${CMAKE_CURRENT_SOURCE_DIR}/detail/Registration.h
		${CMAKE_CURRENT_SOURCE_DIR}/detail/Singleton.h
)

add_library(ClassFactory STATIC
	${HEADER_FILES}
	${CMAKE_CURRENT_SOURCE_DIR}/detail/ClassFactory.cpp
)	

set_target_properties(ClassFactory PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_include_directories(ClassFactory PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/detail
)