/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */

#include "lua.h"

class CPlugin
{
	lua_State *L;
	static class CGameContext *m_pCurrentGameServer;
public:
	static CGameContext *CurrentGameServer() { return m_pCurrentGameServer; }
	CPlugin(class CGameContext *pGameServer, char *pSvGametype);
	virtual char* GetName();
	virtual void OnTick();
};
