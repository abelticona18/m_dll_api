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

# extern libraries
target_link_libraries(myDemo PRIVATE myApi)

if(BUILD_SHARED_LIBS )
	target_compile_definitions(myDemo PRIVATE DLL_TO_SHARE)
endif()