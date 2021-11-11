cmake_minimum_required(VERSION 3.17)
project(Breakout_08)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH /usr/local/lib/cmake /usr/local/lib/x86_64-linux-gnu/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw3)

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
find_package (glfw3 REQUIRED)
find_package (GLEW REQUIRED STATIC)
include_directories(../fgcugl)
set(SOURCE_FILES ../fgcugl/fgcugl.h ../fgcugl/fgcugl.cpp slopeCalc.cpp slopeCalc.h point.h point.cpp line.h line.cpp)
add_executable(breakout ${SOURCE_FILES})
target_link_libraries (breakout ${OPENGL_LIBRARIES} ${GLFW3_LIBRARY}
        ${GLEW_LIBRARY} glfw Xxf86vm pthread Xrandr Xinerama Xi Xcursor)