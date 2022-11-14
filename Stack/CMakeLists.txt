cmake_minimum_required(VERSION 3.11)
project(MyStack VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set(STACK_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(STACK_BOOL_SRC mystack_bool_impl.cc)
set(STACK_BOOL_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(mystack INTERFACE)

target_include_directories(mystack INTERFACE ${STACK_INCLUDES})
target_sources(mystack INTERFACE ${STACK_BOOL_SRC_DIR}/${STACK_BOOL_SRC})

find_program(CLANG_TIDY "clang-tidy")
if (CLANG_TIDY)

    add_custom_target(clang_tidy
    COMMAND clang-tidy ${STACK_BOOL_SRC_DIR}/${STACK_BOOL_SRC} ${STACK_INCLUDES}/mystack.hh --format-style=file -- -I${STACK_INCLUDES}
    )

    message(STATUS "clang-tidy target ON")

    else()
    message(STATUS "clang-tidy target OFF")

endif()

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    file(GLOB_RECURSE ALL_SOURCE_FILES *.cc *.hh)
        add_custom_target(
            format
            COMMAND clang-format
            -style=file
            -i
            ${ALL_SOURCE_FILES}
        )
        message(STATUS "clang-format target ON")
endif()

add_subdirectory(tests)
