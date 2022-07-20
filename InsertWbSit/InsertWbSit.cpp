
// InsertWbSit.cpp : 定义应用程序的类行为。
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

// CInsertWbSitApp 构造

CInsertWbSitApp::CInsertWbSitApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CInsertWbSitApp 对象

CInsertWbSitApp theApp;


// CInsertWbSitApp 初始化

BOOL CInsertWbSitApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CRegKey key;
	LONG ret = 0;
	//BOOL bOpenReg = key.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\CloudClassroom\\WebService"));
	if ((ret = key.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\CloudClassroom\\WebService"), KEY_READ)) != ERROR_SUCCESS)
	{
		AfxMessageBox(_T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\CloudClassroom\\WebService注册表打开失败"));
	}
	else
	{
		DWORD len1 = 128 * sizeof(TCHAR);
		if(key.QueryStringValue(L"strLiveIp", strLiveIp, &len1) != ERROR_SUCCESS)
		{
			WriteLog("strLiveIp读取错误\r\n");
		}

		DWORD len2 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"strLivePort", strLivePort, &len2) != ERROR_SUCCESS)
		{
			WriteLog("strLivePort读取错误\r\n");
		}
		DWORD len3 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"WebServiceIP", WebServiceIP, &len3) != ERROR_SUCCESS)
		{
			WriteLog("WebServiceIP读取错误\r\n");
		}
		
		DWORD len4 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"WebServicePort", WebServicePort, &len4) != ERROR_SUCCESS)
		{
			WriteLog("WebServicePort读取错误\r\n");
		}
		DWORD len5 = 128 * sizeof(TCHAR);
		if(key.QueryStringValue(L"RecordMac", RecordMac, &len5) != ERROR_SUCCESS)
		{
			WriteLog("RecordMac读取错误\r\n");
		}
		DWORD len6 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"DiskPath", DiskPath, &len6) != ERROR_SUCCESS)
		{
			WriteLog("DiskPath读取错误\r\n");
		}
		DWORD len7 = 128 * sizeof(TCHAR);
		if (key.QueryStringValue(L"strHttpPort", strHttpPort, &len7) != ERROR_SUCCESS)
		{
			WriteLog("strHttpPort读取错误\r\n");
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


	//先获取服务器信息
	CBaseService cBaseService;
	char CWebServiceIP[128];
	char CWebServicePort[128];
	g_TcharToChar(WebServiceIP, CWebServiceIP);
	g_TcharToChar(WebServicePort, CWebServicePort);

	std::string str_websitName;
	CString localIp= GetLocalIP();
	CString name=localIp.Mid(localIp.ReverseFind(_T('.'))+1);
	name += "Http录播服务器";
	// //调用接口，发送直播数据到服务器
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
		WriteLog("插入数据库成功！\r\n");
	}
	else
	{
		WriteLog("插入数据库失败！\r\n");
	}

	//AfxMessageBox(L"--------------");

	CInsertWbSitDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = IDOK;
	//INT_PTR nResponse=dlg.DoModal();
	 if (nResponse == IDOK)
	 {
	 	// TODO: 在此放置处理何时用
	 	//  “确定”来关闭对话框的代码
	 }
	 else if (nResponse == IDCANCEL)
	 {
	 	// TODO: 在此放置处理何时用
	 	//  “取消”来关闭对话框的代码
	 }
	 else if (nResponse == -1)
	 {
	 	TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
	 	TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	 }
	
	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	//AfxMessageBox(L"11111111");

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

