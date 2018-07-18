#include "stdafx.h"
#include "exx_web_socket_api.h"


CExxWebSocketAPI::CExxWebSocketAPI(string strAPIKey, string strSecretKey)
{
	SetKey(strAPIKey, strSecretKey);
	SetURI("wss://ws.exx.com/websocket");
}


CExxWebSocketAPI::~CExxWebSocketAPI()
{
}


void CExxWebSocketAPI::API_EntrustDepth(const char* szType, int depthSize, bool bAdd)
{
	char szBuffer[128] = { 0 };
	_snprintf(szBuffer, 128, "{\"dataType\":\"1_ENTRUST_ADD_%s\",\"dataSize\":%d,\"action\":\"%s\"}", szType, depthSize, (bAdd?"ADD":"DEL"));
	Request(szBuffer);
}