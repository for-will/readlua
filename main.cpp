#include <iostream>
#include "lua.hpp"

int main() {
//    std::cout << "Hello, World!" << std::endl;

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
//    int status = luaL_dostring(L, "print(123)");
    int status = luaL_dofile(L, "test.lua");

    if (status==EXIT_SUCCESS){
        std::cout << "EXIT_SUCCESS" << std::endl;
    }else{
        std::cout << "EXIT_FAILURE"<< std::endl;
    }

    lua_close(L);
    return 0;
}