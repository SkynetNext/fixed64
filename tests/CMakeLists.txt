# Collect all test source files
file(GLOB TEST_SOURCES 
    "*.cpp"
    "basic/*.cpp"
    "math/*.cpp"
)

# Create test executable
add_executable(fixed64_tests ${TEST_SOURCES})

# Add Google Test include paths
target_include_directories(fixed64_tests PRIVATE 
    ${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include
)

# Link Google Test and your library
target_link_libraries(fixed64_tests
  PRIVATE
    gtest
    gtest_main
    Fixed64
)

# Use precise trigonometric functions
add_compile_definitions(FIXED64_MATH_USE_FAST_TRIG=0)

# Add compilation options
target_compile_options(fixed64_tests PRIVATE ${COMPILER_WARNINGS})

# Enable console output during test execution
target_compile_definitions(fixed64_tests PRIVATE 
    GTEST_COUT_OUTPUT
)

# Use Google Test for test discovery
include(GoogleTest)
gtest_discover_tests(fixed64_tests PROPERTIES TIMEOUT 120)