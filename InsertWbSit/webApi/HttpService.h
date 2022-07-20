
//#ifndef HTTPSERVICE_H_
//#define HTTPSERVICE_H_

#include <afxinet.h>
#include <string>

using namespace std;

#include "UrlCode.h"
#include "PingCpp.h"
#include "../xml/tinyxml2.h"
#include "../json/json.h"

#include <winsock2.h>
#include <iphlpapi.h>
#pragma comment(lib, "IPHLPAPI.lib")

#define  IE_AGENT  _T("Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727)")

#define		SUCCESS				0			// �����ɹ�
#define		FAILURE				1			// ����ʧ��
#define		OUTTIME				2			// ������ʱ 

#define		BUFFER_SIZE			1024

class  CHttpService {
public:
	CHttpService(LPCTSTR strAgent = IE_AGENT);
	virtual ~CHttpService(void);  
	// TODO: �ڴ�������ķ�����

	int HttpGet(LPCTSTR strUrl, char* cResponse);
	int HttpGet(LPCTSTR strUrl, std::string& sResponse);
    int HttpGetJson(LPCTSTR strUrl, std::string& sResponse);
	int HttpPost(LPCTSTR strUrl, LPCTSTR strPostData, char* cResponse);
	bool GetMacByGetAdaptersInfo(std::string& macOUT);
	long ParseResponse(char* buf, Json::Value& json_data);
	void ConvertElement(tinyxml2::XMLElement* node, Json::Value& json_data, bool root_is_array);
	

private:
	int ExecuteRequest(LPCTSTR strMethod, LPCTSTR strUrl, LPCTSTR strPostData, string &strResponse);
    int ExecuteRequestJson(LPCTSTR strMethod, LPCTSTR strUrl, LPCTSTR strPostData, string &strResponse);
	void Clear();

private:
	CInternetSession	*m_pSession;
	CHttpConnection		*m_pConnection;
	CHttpFile			*m_pFile;

public:
	CUrlCode			m_urlcode;
};

int WriteLog(char *fmt, ...);

void g_charToTCHAR(const char* strIn, TCHAR* strOut);			//charתTCHAR
void g_TcharToChar(const TCHAR* tcStr, char* cStr);				//TCHARתchar
void g_StringToChar(std::string sStr, char* cStr);				//std::stringתchar
CString WINAPI GetLocalIP();									//��ȡ������ip
int GetIPbyName(const std::string& name, std::string& ip);      //ͨ��������ȡIP
BOOL isIpFormatRight(LPTSTR ipAddress);							//�ж�IP�Ƿ�Ϸ�
bool WINAPI PingServer(CString strIP);                          //�ж�IP�Ƿ����pingͨ
CString GetstrValueFromRegedit(LPCTSTR lpSubKey, LPCTSTR lpValueName);
DWORD SetstrValueToRegedit(LPCTSTR lpSubKey, LPCTSTR lpValueName, DWORD dwSize, LPCTSTR strValue);
//#endif //HTTPSERVICE_H_