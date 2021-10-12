cmake_minimum_required(VERSION 3.5)
project(AVS_HW1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

set(LIB_FILES
        # Headers
        random.h
        transport.h
        truck.h
        bus.h
        car.h
        container.h

        # Source files
        random.cpp
        transport.cpp
        truck.cpp
        bus.cpp
        car.cpp
        container.cpp
        )

add_library(transport STATIC ${LIB_FILES})

add_executable(task main.cpp)

target_link_libraries(task transport)
