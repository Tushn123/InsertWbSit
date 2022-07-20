
// InsertWbSit.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CInsertWbSitApp: 
// 有关此类的实现，请参阅 InsertWbSit.cpp
//

class CInsertWbSitApp : public CWinApp
{
public:
	CInsertWbSitApp();
	bool replaceNginxListen();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()

private:
	TCHAR strLiveIp[128] = L"";
	TCHAR strLivePort[128] = L"";
	TCHAR WebServiceIP[128] = L"";
	TCHAR WebServicePort[128] = L"";
	TCHAR RecordMac[128] = L"";
	TCHAR strHttpPort[128] = L"";
	//TCHAR strLivePort[128] = L"";
	TCHAR DiskPath[128] = L"";

	CRegKey m_key;
};

extern CInsertWbSitApp theApp;