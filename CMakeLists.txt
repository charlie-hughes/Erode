cmake_minimum_required(VERSION 3.5.0)
project(Erode VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 " )


# Project header files
FILE(GLOB HEADER_FILES source/*.h source/*/*.hpp)

# Project c++ files
FILE(GLOB SOURCE_FILES source/*.cpp source/*/*.cpp)


set(SOURCES ${SOURCE_FILES} ${HEADER_FILES})

add_executable(${PROJECT_NAME} ${SOURCES})


# glfw
add_subdirectory("include/glfw-3.3.8")
target_link_libraries(${PROJECT_NAME} glfw)

# glm
add_subdirectory("include/glm")
target_link_libraries(${PROJECT_NAME} glm)

# glad
set(GLAD_DIR "include/glad")
add_library(glad "${GLAD_DIR}/src/glad.c")
target_include_directories(glad PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} glad ${CMAKE_DL_LIBS})


if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
