# includes
set(MYAPI_INCLUDES)

# libs
set(MYAPI_LIBS)

# headers
file(GLOB_RECURSE MYAPI__HEADERS src/*.hpp src/*.h)

# sources
file(GLOB_RECURSE MYAPI__SOURCES src/*.cpp src/*.c)

# myApi library
add_library(myApi ${MYAPI__SOURCES} ${MYAPI__HEADERS})

# intern directories
target_include_directories(myApi PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/src
	$<INSTALL_INTERFACE:>/src
)

# extern directories
target_include_directories(myApi
	PRIVATE ${MYAPI_INCLUDES}
)

# extern libraries
target_link_libraries(myApi PRIVATE ${MYAPI_LIBS})

if(BUILD_SHARED_LIBS )
	target_compile_definitions(myApi PRIVATE DLL_TO_BUILD)
endif()

# file(COPY ${MYAPI__HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${MYAPI__HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})