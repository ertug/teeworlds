int L_sendchat(lua_State *L);

const static struct luaL_reg L_twlib[] = {
  {"sendchat", L_sendchat},
  {NULL, NULL}
};
