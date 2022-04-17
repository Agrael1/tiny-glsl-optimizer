cmake_minimum_required(VERSION 3.20)

project(GlslOptimizerV2 C CXX)

file(GLOB_RECURSE PROJECT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp 
${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

file(GLOB_RECURSE PROJECT_INC ${CMAKE_CURRENT_SOURCE_DIR}/include/*.cpp 
${CMAKE_CURRENT_SOURCE_DIR}/include/*.c
${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)


add_definitions(-DNOMINMAX)
add_definitions(-D_USE_MATH_DEFINES)


if(UNIX)
	if(APPLE)
		add_definitions(-DAPPLE)
	else()
		add_definitions(-DLINUX)
	endif()
	add_definitions(-DUNIX)
elseif(WIN32)
	add_definitions(-DWIN32)
	if(MINGW)
		add_definitions(-DMINGW32)
		add_definitions(-DHAVE_STRTOK_R)
		add_definitions(-DHAVE___BUILTIN_FFS)
	endif()
endif()

if(MSVC)
    # Ignore 4055 for glad
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /IGNORE:4055")
	add_definitions(-D__STDC__)
	add_definitions(-DMSVC)
	add_definitions(-Dstrdup=_strdup)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra") ## -std=gnu++0x
endif ()

add_library(GlslOptimizerV2 STATIC 
	${PROJECT_SRC}
	${PROJECT_INC}
)
set_target_properties(GlslOptimizerV2 PROPERTIES LINKER_LANGUAGE CXX)

include_directories(
		src
		src/mesa
		include
		include/c99
		include/c11
		src/compiler
		src/compiler/glsl
		src/mapi
		src/getopt
		src/gallium/include
		src/gallium/auxiliary
		src/util
		../../src/gallium/auxiliary
		../../src/util
)

