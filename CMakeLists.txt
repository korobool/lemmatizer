cmake_minimum_required(VERSION 2.8)
set(PROJECT lemmatizer)
project(${PROJECT})

include_directories(include)
set(SOURCES
	src/wordnode.cpp
	src/wordnet.cpp
	src/traindataparser.cpp
	src/main.cpp)
set(HEADERS
	include/wordnet.h
	include/wordnode.h)

add_definitions(--std=c++0x -Wall)
add_executable(lemmatizer ${SOURCES} ${HEADERS})
install(TARGETS ${PROJECT} DESTINATION bin)
