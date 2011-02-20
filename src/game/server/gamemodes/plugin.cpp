/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "plugin.h"

CGameControllerPLUGIN::CGameControllerPLUGIN(class CGameContext *pGameServer, char *pSvGametype)
  : IGameController(pGameServer)
{
	pluginManager = new CPluginManager();
	plugin = pluginManager->getPlugin(pGameServer, pSvGametype);
	m_pGameType = plugin->GetName();
}

void CGameControllerPLUGIN::Tick()
{
	plugin->OnTick();
	DoPlayerScoreWincheck(); // checks for winners, no teams version
	//DoTeamScoreWincheck(); // checks for winners, two teams version
	IGameController::Tick();
}
