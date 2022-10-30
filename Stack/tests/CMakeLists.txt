cmake_minimum_required(VERSION 3.11)
project(MyStack VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

set( COMMON_FLAGS -Wall -Wextra -Wpedantic -Werror )
set( DEBUG_FLAGS -O0 -g ${COMMON_FLAGS} )

find_package( GTest REQUIRED )
message("include testing")

set( MYSTACK_UTEST_NAME mystack_utests )
add_executable( ${MYSTACK_UTEST_NAME} )

set( MYSTACK_HIGHLOAD_TEST_NAME mystack_highload_test )
add_executable( ${MYSTACK_HIGHLOAD_TEST_NAME} )

target_link_libraries( ${MYSTACK_UTEST_NAME} PRIVATE
    "${GTEST_LIBRARIES}"
    "pthread"
)

target_include_directories( ${MYSTACK_UTEST_NAME} PRIVATE
    "${GTEST_INCLUDE_DIRS}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../include"
)

target_include_directories( ${MYSTACK_HIGHLOAD_TEST_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../include"
)

set( MYSTACK_UTESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mystack_utests" )

set( MYSTACK_UTESTS_FILES
    "tests_main.cc"
)

target_sources( ${MYSTACK_HIGHLOAD_TEST_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/mystack_highload_test.cc"
)

foreach( FILE IN LISTS MYSTACK_UTESTS_FILES )
    target_sources( ${MYSTACK_UTEST_NAME} PRIVATE "${MYSTACK_UTESTS_DIR}/${FILE}" )
endforeach()

enable_testing()

add_test( NAME UnitTests COMMAND
    ${MYSTACK_UTEST_NAME}
)

add_test( NAME SpeedTest COMMAND
    sh -c "./${MYSTACK_HIGHLOAD_TEST_NAME}"
)
set_tests_properties( SpeedTest PROPERTIES TIMEOUT 2 )

if(ADD_SANITIZERS)
    message("Build with sanitizers")
    target_compile_options(${MYSTACK_UTEST_NAME} PUBLIC -fsanitize=address -g ${COMMON_FLAGS})
    set_target_properties(${MYSTACK_UTEST_NAME} PROPERTIES LINK_FLAGS "-fsanitize=address")
    target_compile_options(${MYSTACK_HIGHLOAD_TEST_NAME} PUBLIC -fsanitize=address -g ${COMMON_FLAGS})
    set_target_properties(${MYSTACK_HIGHLOAD_TEST_NAME} PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()