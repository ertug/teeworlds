/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "plugin.h"

class CPluginManager
{
public:
	CPluginManager();
	virtual CPlugin* getPlugin(class CGameContext *pGameServer, char *pSvGametype);
};
