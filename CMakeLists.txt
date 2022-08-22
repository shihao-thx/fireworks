cmake_minimum_required(VERSION 3.0)

project(projectName)

include_directories("C:/Program Files/mingw64/x86_64-w64-mingw32/include")
include_directories(include)

set(CMAKE_CXX_FLAGS "-O2")

link_directories("C:/Program Files/mingw64/x86_64-w64-mingw32/lib")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(HappyBirthday main.cpp src/fire.cpp src/words.cpp src/flower.cpp src/runner.cpp)

target_link_libraries(HappyBirthday graphics64 uuid msimg32 gdi32 imm32 ole32 oleaut32 winmm gdiplus)

set(CMAKE_EXE_LINKER_FLAGS "-static")
