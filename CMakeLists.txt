cmake_minimum_required(VERSION 3.16)
project(MySDLApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SDL directory
set(SDL_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3")

# Includes and libraries
include_directories(${SDL_DIR}/include)
link_directories(${SDL_DIR}/lib)

# Your executable
file(GLOB SOURCES src/*.cpp
               src/events/*.cpp
             
               )
add_executable(MySDLApp ${SOURCES})

# Link SDL3
target_link_libraries(MySDLApp SDL3)

# Tell MSVC to use main() not WinMain()
if (MSVC)
    set_target_properties(MySDLApp PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif()
add_custom_command(TARGET MySDLApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL_DIR}/bin/SDL3.dll"
        $<TARGET_FILE_DIR:MySDLApp>)

