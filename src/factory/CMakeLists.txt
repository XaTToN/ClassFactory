# Copyright (C) 2015 Marcel Mueller
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <http://www.gnu.org/licenses/>.

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