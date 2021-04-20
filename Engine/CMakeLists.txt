cmake_minimum_required(VERSION 3.17)
project(Engine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_DIRECTORY}")

include_directories(include)
add_compile_definitions(ENGINE_BUILD_DLL)
add_compile_definitions(IMGUI_DISABLE_WIN32_DEFAULT_IME_FUNCTIONS)

# Build only GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# ImGui sources
set(IMGUI_SOURCES 3rd-party/imgui/imgui.cpp 3rd-party/imgui/imgui_demo.cpp 3rd-party/imgui/imgui_draw.cpp 3rd-party/imgui/imgui_tables.cpp 3rd-party/imgui/imgui_widgets.cpp src/ImGui/ImGuiBuild.cpp)

add_subdirectory(3rd-party/spdlog)
add_subdirectory(3rd-party/GLFW)
add_subdirectory(3rd-party/glad)

# Build libraries
add_library(imgui ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC 3rd-party/GLFW/include 3rd-party/glad/include 3rd-party/imgui)

# Find packages
find_package(OpenGL REQUIRED)

add_library(engine SHARED src/Core/Application.cpp src/Core/Log.cpp src/Core/Window.cpp src/Platform/GlfwWindow.cpp src/Platform/Windows/WindowsPlatform.cpp src/Platform/Platform.cpp src/Events/EventManager.cpp src/Core/Layer.cpp src/Core/LayerStack.cpp src/Platform/GlfwInput.cpp src/ImGui/ImGuiLayer.cpp)

target_link_libraries(engine spdlog glfw glad imgui opengl32)
target_include_directories(engine PUBLIC 3rd-party/spdlog/include 3rd-party/GLFW/include 3rd-party/glad/include 3rd-party/imgui)

target_precompile_headers(engine PRIVATE include/pch.h)
set_property(TARGET engine PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

# Copy .dll file after build
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_custom_command(TARGET engine POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy
                       ${ENGINE_OUTPUT_DIRECTORY}libengine.dll
                       ${GAME_OUTPUT_DIRECTORY})
elseif(MSVC)
    add_custom_command(TARGET engine POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${ENGINE_OUTPUT_DIRECTORY}engine.dll
            ${GAME_OUTPUT_DIRECTORY})
endif()

add_dependencies(imgui glfw)
add_dependencies(imgui glad)

add_dependencies(engine spdlog)
add_dependencies(engine imgui)
