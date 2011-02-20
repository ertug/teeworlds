/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_PLUGIN_H
#define GAME_SERVER_GAMEMODES_PLUGIN_H
#include <game/server/gamecontroller.h>
#include <game/server/plugins/pluginmanager.h>

class CGameControllerPLUGIN : public IGameController
{
	CPluginManager *pluginManager;
	CPlugin* plugin;
public:
	CGameControllerPLUGIN(class CGameContext *pGameServer, char *pSvGametype);
	virtual void Tick();
};
#endif
