/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include "plugin.h"
#include "luainterface.h"
#include <engine/shared/linereader.h>
//#include <iostream>

CGameContext *CPlugin::m_pCurrentGameServer;

CPlugin::CPlugin(class CGameContext *pGameServer, char *pSvGametype)
{
	// XXX: watch out for concurrency
	CPlugin::m_pCurrentGameServer = pGameServer;
  
	L = lua_open();
	luaL_openlibs(L);
	luaL_register(L, "tw", L_twlib);

	// FIXME: use storage interface
	// m_pStorage = Kernel()->RequestInterface<IStorage>();
	// m_pStorage->OpenFile()

	// std::cout << "asdf1";
	// IOHANDLE File = io_open("plugins/dummy.lua", IOFLAG_READ);
	// char *pLine;
	// int FileLength = io_length(File);
	// std::cout << "flength:" << FileLength;
	// char aBuffer[FileLength];
	// CLineReader LineReader;
	// LineReader.Init(File);
	// while((pLine = LineReader.Get()))
	// {
	// 	std::cout << "line:" << pLine;
	// 	str_append(aBuffer, pLine, sizeof(aBuffer));
	// }
	// io_close(File);

	// luaL_loadstring(L, aBuffer);
	// lua_pcall(L, 0, 0, 0);

	luaL_dofile(L, "plugins/dummy.lua");
}

char *CPlugin::GetName()
{
	lua_getglobal(L, "modname");
	char* name = (char*)lua_tostring(L, -1);
	lua_pop(L, 1);
	return name;
}

void CPlugin::OnTick()
{
	lua_getglobal(L, "tick");
	lua_call(L, 0, 0);
}
