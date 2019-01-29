# Only the root CMake file must start with a version declaration
cmake_minimum_required(VERSION 3.7)
# Name of project (executable)
project(2DPlatformer)
include_directories(
  ${PROJECT_SOURCE_DIR}/headers
  ${PROJECT_SOURCE_DIR}/headers/types
  ${PROJECT_SOURCE_DIR}/headers/FrameAnim
)
  set(sourcefiles
      ${PROJECT_SOURCE_DIR}/src/Main.cpp
      ${PROJECT_SOURCE_DIR}/src/FrameAnimation.cpp
    )
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
find_package(unofficial-box2d CONFIG REQUIRED)
set(SFML_DIR "C:\\vcpkg\\packages\\sfml_x86-windows\\share\\sfml")
set(CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/cmake_modules"
     ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 COMPONENTS system window graphics main REQUIRED)
# Add all SOURCE files to object and link
#add_executable(2DPlatformer WIN32 src/MainLoop.cpp src/Map.cpp)
add_executable(2DPlatformer ${sourcefiles})
target_compile_features(2DPlatformer
                        PRIVATE
                        cxx_std_17)
target_link_libraries(2DPlatformer sfml-system sfml-window sfml-graphics sfml-main ${CMAKE_THREAD_LIBS_INIT} unofficial::box2d::Box2D)