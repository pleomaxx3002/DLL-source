// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"
#include <Windows.h>
#include <cstdio>
#include <string.h>
#include <tchar.h>
#define MAX_PATH_SIZE 200

__declspec(dllexport) DWORD GetStIn(LPSTARTUPINFO p) //getting Startupinfo of current process
{
	GetStartupInfo(p);
	return 0;
}
__declspec(dllexport) DWORD GetCmdLine(LPTSTR p)  //getting cmd line attributes for current process
{
	p = _tcsdup(GetCommandLine());
	return 0;
}

__declspec(dllexport) DWORD GetCurrDirr(LPVOID Dir) //getting dirrectory of current process
{
	if (GetCurrentDirectory(MAX_PATH_SIZE, (LPTSTR)Dir) != 0)
		return 1;
	return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

