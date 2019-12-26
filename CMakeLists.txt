cmake_minimum_required(VERSION 3.15)
project(readlua)

set(CMAKE_CXX_STANDARD 14)
AUX_SOURCE_DIRECTORY(hello ALL_SRC)
AUX_SOURCE_DIRECTORY(lua-5.3.5/src LUA_ALL_SRC)
#include_directories(src hello)
SET(LUA_LIB_SRC ${LUA_ALL_SRC})
LIST(REMOVE_ITEM LUA_LIB_SRC lua-5.3.5/src/lua.c lua-5.3.5/src/luac.c)

SET(LUA_EXCUTE_SRC ${LUA_ALL_SRC})
LIST(REMOVE_ITEM LUA_EXCUTE_SRC lua-5.3.5/src/luac.c)
#message(${LUA_EXCUTE_SRC})

INCLUDE_DIRECTORIES(lua-5.3.5/src)


add_executable(hello2 ${ALL_SRC})
add_library(lualib ${LUA_LIB_SRC})
add_executable(lua ${LUA_EXCUTE_SRC})

add_executable(hello main.cpp)
target_link_libraries(hello lualib)