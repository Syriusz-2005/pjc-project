cmake_minimum_required(VERSION 3.25)
project(pjc_project)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)

FetchContent_MakeAvailable(fmt)

FetchContent_MakeAvailable(SFML)

add_executable(pjc_project main.cpp
        Engine/Object/Object.cpp
        Engine/Object/Object.h
        Engine/Context/Context.cpp
        Engine/Context/Context.h
        Engine/Scene/Scene.cpp
        Engine/Scene/Scene.h
        Engine/Camera/Camera.cpp
        Engine/Camera/Camera.h
        Engine/Renderer/Renderer.cpp
        Engine/Renderer/Renderer.h
        Engine/Rect/Rect.cpp
        Engine/Rect/Rect.h)
target_link_libraries(pjc_project sfml-graphics)
target_link_libraries(pjc_project fmt)