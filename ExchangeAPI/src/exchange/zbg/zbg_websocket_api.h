#pragma once
#include "websocket_api/websocket_api.h"
class CZbgWebsocketAPI : public CWebSocketAPI
{
public:
	CZbgWebsocketAPI(std::string strAPIKey, std::string strSecretKey);
	~CZbgWebsocketAPI();
public:
	virtual void API_EntrustDepth(eMarketType type, int depthSize, bool bAdd);
};
