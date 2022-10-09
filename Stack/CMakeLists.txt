cmake_minimum_required(VERSION 3.11)

project(MyStack VERSION 1.0 LANGUAGES CXX )
find_package( GTest REQUIRED )

set( MYSTACK_UTEST_NAME mystack_utests )
add_executable( ${MYSTACK_UTEST_NAME} )

set( MYSTACK_HIGHLOAD_TEST_NAME mystack_highload_test )
add_executable( ${MYSTACK_NAME} )

target_link_libraries( ${MYSTACK_UTEST_NAME} PRIVATE
    "${GTEST_LIBRARIES}"
    "pthread"
)

target_include_directories( ${MYSTACK_UTEST_NAME} PRIVATE
    "${GTEST_INCLUDE_DIRS}"
    "${CMAKE_SOURCE_DIR}/include"
)

target_include_directories( ${MYSTACK_HIGHLOAD_TEST_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

set( MYSTACK_UTESTS_DIR "${CMAKE_SOURCE_DIR}/tests/mystack_utests" )

set( MYSTACK_UTESTS_FILES
    "line-tests.cc"
    "plane-tests.cc"
    "point-tests.cc"
    "seg-tests.cc"
    "tests-main.cc"
    "utils-tests.cc"
    "vec-tests.cc"
    "triangle-tests.cc"
    "domain-tests.cc"
    "split-tests.cc"
)

target_sources( ${MYSTACK_HIGHLOAD_TEST_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/tests/mystack_highload_test.cc"
)

foreach( FILE IN LISTS MYSTACK_UTESTS_FILES )
    target_sources( ${MYSTACK_UTEST_NAME} PRIVATE "${MYSTACK_UTESTS_DIR}/${FILE}" )
endforeach()

set( COMMON_FLAGS -Wall -Wextra -Wpedantic -Werror )
set( DEBUG_FLAGS -O0 -g ${COMMON_FLAGS} )

target_compile_features( ${MYSTACK_UTEST_NAME} PRIVATE cxx_std_17 )
target_compile_features( ${MYSTACK_HIGHLOAD_TEST_NAME} PRIVATE cxx_std_17 )

target_compile_options( ${MYSTACK_UTEST_NAME} PRIVATE ${DEBUG_FLAGS} )
target_compile_options( ${MYSTACK_HIGHLOAD_TEST_NAME} PRIVATE ${DEBUG_FLAGS} )


# Testing stuff
set( GEN_OUTPUT_NAME out.txt )
set( GEN_SCRIPT_NAME ${CMAKE_HOME_DIRECTORY}/gen_data.py )
execute_process( COMMAND python3 ${GEN_SCRIPT_NAME} OUTPUT_FILE ${GEN_OUTPUT_NAME} )

enable_testing()

add_test( NAME UnitTests COMMAND
    ${MYSTACK_UTEST_NAME}
)

add_test( NAME ValgrindTest COMMAND
    sh -c "valgrind --leak-check=full --error-exitcode=1 ${VALGRIND_FLAGS} ./${MYSTACK_HIGHLOAD_TEST_NAME} < ${GEN_OUTPUT_NAME}"
)
add_test( NAME SpeedTest COMMAND
    sh -c "./${MYSTACK_HIGHLOAD_TEST_NAME} < ${GEN_OUTPUT_NAME}"
)
set_tests_properties( SpeedTest PROPERTIES TIMEOUT 2 )

