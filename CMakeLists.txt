cmake_minimum_required(VERSION 3.27) 

project(HelloOpenCL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCL REQUIRED)

add_executable(${PROJECT_NAME} HelloWorld.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenCL::OpenCL)
target_compile_definitions(${PROJECT_NAME} PRIVATE CL_HPP_TARGET_OPENCL_VERSION=300)