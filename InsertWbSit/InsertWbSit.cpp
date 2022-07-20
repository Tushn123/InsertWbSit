
// InsertWbSit.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "InsertWbSit.h"

#include <algorithm>

#include "InsertWbSitDlg.h"
#include "atlbase.h"
#include "webApi/BaseService.h"
#include "webApi/HttpService.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CInsertWbSitApp

BEGIN_MESSAGE_MAP(CInsertWbSitApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

string TCHARTurnString(TCHAR *STR)

{

	int iLen = WideCharToMultiByte(CP_ACP, 0, STR, -1, NULL, 0, NULL, NULL);


	char* chRtn = new char[iLen*sizeof(char)];

	WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);

	string str(chRtn);

	return str;

}

// CInsertWbSitApp ����

CInsertWbSitApp::CInsertWbSitApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CInsertWbSitApp ����

CInsertWbSitApp theApp;


// CInsertWbSitApp ��ʼ��

BOOL CInsertWbSitApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CRegKey key;
	LONG ret = 0;
	//BOOL bOpenReg = key.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\CloudClassroom\\WebService"));
	if ((ret = key.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\CloudClassroom\\WebService"), KEY_READ)) != ERROR_SUCCESS)
	{
		AfxMessageBox(_T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\CloudClassroom\\WebServiceע����ʧ��"));
	}
	else
	{
		DWORD len1 = 128 * sizeof(TCHAR);
		if(key.QueryStringValue(L"strLiveIp", strLiveIp, &len1) != ERROR_SUCCESS)
		{
			WriteLog("strLiveIp��ȡ����\r\n");
		}

		DWORD len2 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"strLivePort", strLivePort, &len2) != ERROR_SUCCESS)
		{
			WriteLog("strLivePort��ȡ����\r\n");
		}
		DWORD len3 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"WebServiceIP", WebServiceIP, &len3) != ERROR_SUCCESS)
		{
			WriteLog("WebServiceIP��ȡ����\r\n");
		}
		
		DWORD len4 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"WebServicePort", WebServicePort, &len4) != ERROR_SUCCESS)
		{
			WriteLog("WebServicePort��ȡ����\r\n");
		}
		DWORD len5 = 128 * sizeof(TCHAR);
		if(key.QueryStringValue(L"RecordMac", RecordMac, &len5) != ERROR_SUCCESS)
		{
			WriteLog("RecordMac��ȡ����\r\n");
		}
		DWORD len6 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"DiskPath", DiskPath, &len6) != ERROR_SUCCESS)
		{
			WriteLog("DiskPath��ȡ����\r\n");
		}
		DWORD len7 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"strHttpPort", strHttpPort, &len7) != ERROR_SUCCESS)
		{
			WriteLog("strHttpPort��ȡ����\r\n");
		}
	}
	key.Close();

	std::string str_strLiveIp = TCHARTurnString(strLiveIp);
	std::string str_strLivePort = TCHARTurnString(strLivePort);
	std::string str_DiskPath = TCHARTurnString(DiskPath);
	std::string str_RecordMac = TCHARTurnString(RecordMac);
	std::string str_strHttpPort = TCHARTurnString(strHttpPort);
	replace(str_RecordMac.begin(), str_RecordMac.end(), '-', ' ');
	str_RecordMac.erase(std::remove_if(str_RecordMac.begin(), str_RecordMac.end(), [](unsigned char x) {return std::isspace(x); }), str_RecordMac.end());


	//�Ȼ�ȡ��������Ϣ
	CBaseService cBaseService;
	char CWebServiceIP[128];
	char CWebServicePort[128];
	g_TcharToChar(WebServiceIP, CWebServiceIP);
	g_TcharToChar(WebServicePort, CWebServicePort);

	std::string str_websitName;
	CString localIp= GetLocalIP();
	CString name=localIp.Mid(localIp.ReverseFind(_T('.'))+1);
	name += "Http¼��������";
	// //���ýӿڣ�����ֱ�����ݵ�������
	struct AbnormalInfo temp;
	temp.lanIp = CW2A(localIp.GetString());
	//temp.lanPort = 0;
	temp.lanPort = std::stoi(str_strHttpPort);
	temp.macAddr = str_RecordMac;
	temp.passWord = "NULL";
	temp.phyPath = "NULL";
	temp.userName = "NULL";
	temp.virtualDirName = "NULL";
	temp.wanIp = "NULL";//str_strLiveIp;
	temp.wanPort = NULL;// std::stoi(str_strLivePort);
	temp.websitName = CW2A(name.GetString());
	temp.websitType = 1;
	bool ret_insert=cBaseService.InsertStatusCtx(CWebServiceIP, CWebServicePort, temp);
	if(ret_insert)
	{
		WriteLog("�������ݿ�ɹ���\r\n");
	}
	else
	{
		WriteLog("�������ݿ�ʧ�ܣ�\r\n");
	}

	//AfxMessageBox(L"--------------");

	CInsertWbSitDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = IDOK;
	//INT_PTR nResponse=dlg.DoModal();
	 if (nResponse == IDOK)
	 {
	 	// TODO: �ڴ˷��ô����ʱ��
	 	//  ��ȷ�������رնԻ���Ĵ���
	 }
	 else if (nResponse == IDCANCEL)
	 {
	 	// TODO: �ڴ˷��ô����ʱ��
	 	//  ��ȡ�������رնԻ���Ĵ���
	 }
	 else if (nResponse == -1)
	 {
	 	TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
	 	TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	 }
	
	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	//AfxMessageBox(L"11111111");

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

