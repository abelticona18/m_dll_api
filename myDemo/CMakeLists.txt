# headers
file(GLOB_RECURSE MYDEMO__HEADERS src/*.hpp src/*.h)

# sources
file(GLOB_RECURSE MYDEMO__SOURCES src/*.cpp src/*.c)

# executable
add_executable(myDemo ${MYDEMO__SOURCES} ${MYDEMO__HEADERS})

# intern directories
target_include_directories(myDemo PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/src
	$<INSTALL_INTERFACE:>/src
)

add_library(myApiExternal SHARED IMPORTED)
set_target_properties(myApiExternal PROPERTIES
	IMPORTED_LOCATION_DEBUG        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/myApi.dll
	IMPORTED_IMPLIB_DEBUG          ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/myApi.lib
	IMPORTED_LOCATION_RELEASE      ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/myApi.dll
	IMPORTED_IMPLIB_RELEASE        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/myApi.lib
	INTERFACE_INCLUDE_DIRECTORIES  ${CMAKE_INSTALL_INCLUDEDIR}
)

# extern libraries
target_link_libraries(myDemo PRIVATE myApiExternal)

if(BUILD_SHARED_LIBS )
	target_compile_definitions(myDemo PRIVATE DLL_TO_SHARE)
endif()