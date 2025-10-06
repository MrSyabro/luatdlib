#include <td/telegram/td_json_client.h>
#include <lua.h>
#include <lauxlib.h>

static int ltd_create_client_id (lua_State *L) {
    lua_pushinteger(L, td_create_client_id());

    return 1;
}

static int ltd_receive (lua_State *L) {
    int isnum;
    double timeout = (double)lua_tonumberx(L, 1, &isnum);
    if (!isnum) timeout = 10;

    const char *result = td_receive(timeout);
    if (result) {
        lua_pushstring(L, result);
        return 1;
    }
    return 0;
}

static int ltd_execute (lua_State *L) {
    const char *command = luaL_checkstring(L, 1);
    const char *result = td_execute(command);
    if (result) {
        lua_pushstring(L, result);
        return 1;
    }
    return 0;
}

static int ltd_send (lua_State *L) {
    int client_id = luaL_checkinteger(L, 1);
    const char *request = luaL_checkstring(L, 2);
    td_send(client_id, request);
    return 0;
}

static const struct luaL_Reg luatd [] = {
    {"create_client_id", ltd_create_client_id},
    {"receive", ltd_receive},
    {"execute", ltd_execute},
    {"send", ltd_send},
    {NULL, NULL} /* sentinel */
};

#if defined(_WIN32) || defined(_WIN64)
__declspec(dllexport)
#endif
int luaopen_luatd(lua_State *L) {
    luaL_newmetatable(L, "luatd");
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    luaL_setfuncs(L, luatd, 0);

    return 1;
}