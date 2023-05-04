cmake_minimum_required(VERSION 3.23)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(quill)

add_executable(test main.cpp
            cTypes.h cppTypes.h
            Kalman.cpp Kalman.h
            FileOperator.cpp FileOperator.h
            FootPlace.cpp FootPlace.h)
target_link_libraries(test PRIVATE quill::quill)



