cmake_minimum_required(VERSION 2.8)
set(PROJECT lemmatizer)
project(${PROJECT})

# set(CMAKE_BUILD_TYPE Debug)

include_directories(
	include
	src)
set(UTF8_LIB_HEADERS
	include/utf8/checked.h
	include/utf8/unchecked.h
	include/utf8/core.h
	include/utf8.h
)
set(SOURCES
	src/wordnode.cpp
	src/wordnet.cpp
	src/traindataparser.cpp
	src/main.cpp)
set(HEADERS
	${UTF8_LIB_HEADERS}
	include/wordnet.h
	include/wordnode.h
	include/traindataparser.h)

add_definitions(--std=c++0x -Wall)
add_executable(lemmatizer ${SOURCES} ${HEADERS})
install(TARGETS ${PROJECT} DESTINATION bin)
