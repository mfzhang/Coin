#include "stdafx.h"
#include "okex_websocket_api.h"


COkexWebsocketAPI::COkexWebsocketAPI(std::string strAPIKey, std::string strSecretKey, bool bFutures)
{
	SetKey(strAPIKey, strSecretKey, bFutures);
	if(bFutures)
		SetURI("wss://real.okex.com:10440/websocket/okexapi");
	else
		SetURI("wss://real.okex.com:10441/websocket");
}


COkexWebsocketAPI::~COkexWebsocketAPI()
{
}

bool COkexWebsocketAPI::Ping()
{
	return Request("{\"event\":\"ping\"}");
}

void COkexWebsocketAPI::API_EntrustDepth(eMarketType type, int depthSize, bool bAdd)
{
	if(m_pExchange)
		m_pExchange->GetDataCenter()->ClearAllEntrustDepth();
	char szBuffer[512] = {0};
	_snprintf(szBuffer, 512, "{\"event\":\"%s\",\"channel\":\"ok_sub_spot_%s_depth\"}", (bAdd ? "addChannel" : "removeChannel"), m_pExchange->GetMarketString(type, false));
	Request(szBuffer);
}


void COkexWebsocketAPI::API_FuturesKlineData(bool bAdd, std::string& strKlineType, std::string& strCoinType, std::string& strFuturesCycle)
{
	m_lastAddChannelFuturesKline = "ok_sub_futureusd_";
	m_lastAddChannelFuturesKline.append(strCoinType);
	m_lastAddChannelFuturesKline.append("_kline_");
	m_lastAddChannelFuturesKline.append(strFuturesCycle);
	m_lastAddChannelFuturesKline.append("_");
	m_lastAddChannelFuturesKline.append(strKlineType);
	char szBuffer[512] = {0};
	_snprintf(szBuffer, 512, "{\"event\":\"%s\",\"channel\":\"ok_sub_futureusd_%s_kline_%s_%s\"}", (bAdd ? "addChannel" : "removeChannel"), strCoinType.c_str(),  strFuturesCycle.c_str(), strKlineType.c_str());
	Request(szBuffer);
}


void COkexWebsocketAPI::API_FuturesTickerData(bool bAdd, std::string& strCoinType, std::string& strFuturesCycle)
{
	m_lastAddChannelFuturesTicker = "ok_sub_futureusd_";
	m_lastAddChannelFuturesTicker.append(strCoinType);
	m_lastAddChannelFuturesTicker.append("_ticker_");
	m_lastAddChannelFuturesTicker.append(strFuturesCycle);
	char szBuffer[512] = {0};
	_snprintf(szBuffer, 512, "{\"event\":\"%s\",\"channel\":\"ok_sub_futureusd_%s_ticker_%s\"}", (bAdd ? "addChannel" : "removeChannel"), strCoinType.c_str(), strFuturesCycle.c_str());
	Request(szBuffer);

}