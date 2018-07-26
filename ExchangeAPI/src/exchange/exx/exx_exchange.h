#pragma once
#include "exchange/exchange.h"
class CExxExchange : public CExchange
{
public:
	CExxExchange(std::string strAPIKey, std::string strSecretKey);
	~CExxExchange();
	virtual void OnHttpResponse(eHttpAPIType type, Json::Value& retObj, const std::string& strRet, int customData, std::string strCustomData);
	virtual void OnWebsocketResponse(Json::Value& retObj, const std::string& strRet);

private:
	void Parse_Balance(Json::Value& retObj, const std::string& strRet);
	void Parse_Ticker(Json::Value& retObj, const std::string& strRet);
	void Parse_EntrustDepth(Json::Value& retObj, const std::string& strRet);
	void Parse_Trade(Json::Value& retObj, const std::string& strRet);
	void Parse_TradeOrderListState(Json::Value& retObj, const std::string& strRet) {}
	void Parse_TradeOrderState(Json::Value& retObj, const std::string& strRet);
};

