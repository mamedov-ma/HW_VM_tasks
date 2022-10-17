cmake_minimum_required(VERSION 3.11)
project(MyStack VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set( COMMON_FLAGS -Wall -Wextra -Wpedantic -Werror )
set( DEBUG_FLAGS -O0 -g ${COMMON_FLAGS} )

option(ADD_TIDY "Activate clang-tidy" ON)
option(ADD_FORMAT "Activate clang-format" ON)
option(ADD_TESTING "Activate google-testing" ON)

set(STACK_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(STACK_BOOL_IMPL mystack_bool_impl.cc)
set(STACK_BOOL_IMPL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(mystack INTERFACE)

target_include_directories(mystack INTERFACE ${STACK_INCLUDES})
target_sources(mystack INTERFACE ${STACK_BOOL_IMPL_DIR}/${STACK_BOOL_IMPL})

if(ADD_TIDY)
    set(CLANG_TIDY_FLAGS
        clang-tidy;
        --checks=*;
        --header-filter=.;
        --warning-as-errors=*;
        --format-style=file;    
    )
    message(STATUS "clang-tidy ON")
endif()

if(ADD_FORMAT)
    file(GLOB_RECURSE ALL_SOURCE_FILES *.cc *.hh)
    add_custom_target(
        format
        COMMAND clang-format
        -style=file
        -i
        ${ALL_SOURCE_FILES}
    )
    message(STATUS "clang-format ON")
endif()

if(ADD_TESTING)
    message(STATUS "testing ON")
    add_subdirectory(tests)
endif()


