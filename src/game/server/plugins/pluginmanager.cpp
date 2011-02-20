/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "pluginmanager.h"

CPluginManager::CPluginManager()
{
}

CPlugin* CPluginManager::getPlugin(class CGameContext *pGameServer, char *pSvGametype)
{
	return new CPlugin(pGameServer, pSvGametype);
}
