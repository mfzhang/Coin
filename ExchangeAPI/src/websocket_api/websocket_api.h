#pragma once
#include <boost/thread/thread.hpp>
#include "websocket.h"
class CWebSocketAPI
{
public:
	CWebSocketAPI();
	~CWebSocketAPI();
	void SetKey(string strAPIKey, string strSecretKey);
	void SetURI(string strURI);
	void Request(const char* szRequestInfo);
	void SetCallBackOpen(websocketpp_callbak_open callbak0pen);
	void SetCallBackClose(websocketpp_callbak_close callbakClose);
	void SetCallBackMessage(websocketpp_callbak_message callbakMessage);
	void Run();
	void Close();
	void Update();
	void PushRet(int type, Json::Value& retObj, const char* szRet);
	static unsigned __stdcall CWebSocketAPI::RunThread(LPVOID arg);
	//订阅交易深度
	virtual void API_EntrustDepth(const char* szType, int depthSize, bool bAdd){}
private:
	websocketpp_callbak_open		m_callbakOpen;
	websocketpp_callbak_close		m_callbakClose;
	websocketpp_callbak_message		m_callbakMessage;
protected:
	string m_strAPIKey;			//用户申请的apiKey
	string m_strSecretKey;		//请求参数签名的私钥
	string m_strURI;
	WebSocket* m_pWebsocket;
	HANDLE m_hThread;
	std::deque<SWebSocketResponse> m_queueResponseInfo;
	boost::mutex m_responseMutex;
	
};

