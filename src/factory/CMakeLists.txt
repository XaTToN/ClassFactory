set(MAIN_HEADER_FILE
		${CMAKE_SOURCE_DIR}/include/ClassFactory/LCF.h
)

set(DETAIL_HEADER_FILES 
		${CMAKE_SOURCE_DIR}/include/ClassFactory/detail/ClassFactory.h
		${CMAKE_SOURCE_DIR}/include/ClassFactory/detail/ClassAllocator.h
		${CMAKE_SOURCE_DIR}/include/ClassFactory/detail/Registration.h
		${CMAKE_SOURCE_DIR}/include/ClassFactory/detail/Singleton.h
)

include_directories(
	${CMAKE_SOURCE_DIR}/include/
)

source_group("" FILES ${MAIN_HEADER_FILE})
source_group("detail" FILES ${DETAIL_HEADER_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/ClassFactory.cpp)

add_library(ClassFactory STATIC
	${MAIN_HEADER_FILE}
	${DETAIL_HEADER_FILES}
	${CMAKE_CURRENT_SOURCE_DIR}/ClassFactory.cpp
)

set_target_properties(ClassFactory PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)