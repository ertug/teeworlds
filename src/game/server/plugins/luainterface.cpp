extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include "plugin.h"
#include <game/server/gamecontext.h>


int L_sendchat(lua_State *L) {
  // TODO: check param count
  int n = lua_gettop(L);

  int ClientID = lua_tointeger(L, 1);
  int Team = lua_tointeger(L, 2);
  char *Text = (char*)lua_tostring(L, 3);

  CPlugin::CurrentGameServer()->SendChat(ClientID, Team, Text);

  return 0;
}
