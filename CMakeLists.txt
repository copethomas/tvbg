cmake_minimum_required(VERSION 3.10)

# set the project name
project(TVBG)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

# add the executable
add_executable(TVBG main.cpp BulletEntity.cpp EnemyFighter.cpp Explosion.cpp PlayerDeathPartical.cpp Ship.cpp TextStats.cpp DrawUtil.cpp EnemyShip.cpp ExplosionPartical.cpp Message.cpp PlayerShip.cpp SpawnEngine.cpp World.cpp EnemyFighterBullet.cpp Entity.cpp JAMCT_Logger.cpp MovableEntity.cpp Score.cpp Text.cpp)

include_directories (/usr/include/freetype2)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
target_link_libraries(TVBG glfw ftgl)
find_package(OpenGL REQUIRED)
target_link_libraries(TVBG OpenGL::GL)
