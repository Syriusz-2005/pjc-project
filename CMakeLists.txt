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
        Engine/Rect/Rect.h
        Engine/PhysicsEngine/PhysicsEngine.cpp
        Engine/PhysicsEngine/PhysicsEngine.h
        Engine/PhysicalObject/PhysicsModule.cpp
        Engine/PhysicalObject/PhysicsModule.h
        Engine/Group/Group.cpp
        Engine/Group/Group.h
        Game/Player/Player.cpp
        Game/Player/Player.h
        Game/GameManager/GameManager.cpp
        Game/GameManager/GameManager.h
        Game/SceneInitializer/SceneInitializer.cpp
        Game/SceneInitializer/SceneInitializer.h
        Game/Tree/Tree.cpp
        Game/Tree/Tree.h
        Game/Ground/Ground.cpp
        Game/Ground/Ground.h
        Game/BackgroundShader/BackgroundShader.cpp
        Game/BackgroundShader/BackgroundShader.h
        Engine/VecUtils/VecUtils.h
)
target_link_libraries(pjc_project sfml-graphics)
target_link_libraries(pjc_project fmt)