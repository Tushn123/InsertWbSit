
// InsertWbSit.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CInsertWbSitApp: 
// �йش����ʵ�֣������ InsertWbSit.cpp
//

class CInsertWbSitApp : public CWinApp
{
public:
	CInsertWbSitApp();
	bool replaceNginxListen();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

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