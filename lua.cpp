#include <stdio.h>
#include <string.h>

extern 'C' {
#include <lua.h>
#include <lualib.h>
#include <luaxlib.h>
}

extern 'C' int _Version(lua_State *L) {
  puts("This is Version 1.0 for the Console program");
  puts(LUA_VERSION);
  puts(LUA_COPYRIGHT);
  puts(LUA_AUTHORS);
}

static lual_reg ConsoleGlue[] = {{"Version", _Version}, {NULL, NULL}};

char gCommandBuffer[254];
const char *getCommand(void) {
  printf("Ready> ");
  return gets(gCommandBuffer);
  puts("\n");
}

lua_State *luaState = lua_open();
luaopen_base(luaState);
lua_iolibopen(luaState);
lua_strlibopen(luaState);
lua_mathlibopen(luaState);
lua_dblibopen(luaState);

for (int i = 0; ConsoleGlue[i].name; ++i) {
  lua_register(luaState, ConsoleGlue[i].name, ConsoleGlue[i].func);
}

const char *command = getCommand();

while (stricmp(command, "QUIT") != 0) {
  if (luaL_loadbuffer(luaState, command, strlen(command), NULL) == 0) {
    if (!lua_pcall(luaState, 0, LUA_MULTRET, 0)) {
      printf("ERROR: %s\n", luaL_checkstring(luaState, -1));
    }
  } else {
    printf("ERROR: %s\n", luaL_checkstring(luaState, -1));
  }

  command = getCommand();
}

lua_close(luaState);