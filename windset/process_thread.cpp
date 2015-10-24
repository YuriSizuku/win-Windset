#include "process_thread.h"
#include "stdafx.h"
#include <tlhelp32.h>//必须在此文件中添加
void EnableDebugPriv(void)//提升权限
{
	HANDLE hToken;  
	LUID sedebugnameValue;  
	TOKEN_PRIVILEGES tkp;  

	if (!OpenProcessToken(GetCurrentProcess(),  
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {  
			return;  
	}  
	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &sedebugnameValue)) {  
		CloseHandle(hToken);  
		return;  
	}  
	tkp.PrivilegeCount = 1;  
	tkp.Privileges[0].Luid = sedebugnameValue;  
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;  
	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL)) {  
		CloseHandle(hToken);  
		return;  
	}   
}
void SuspendTask(const DWORD Pid)//挂起一个进程中的所有线程
{
	THREADENTRY32 th32;
	th32.dwSize=sizeof(th32);//指定结构的长度，以字节为单位。在调用Thread32First时，设置这个成员为SIZEOF（THREADENTRY32）。如果你不初始化的dwSize，Thread32First将调用失败。 
	HANDLE hThreadSnap=::CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,0);
	//CreateToolhelp32Snapshot可以通过获取进程信息为指定的进程、进程使用的堆[HEAP]、模块[MODULE]、线程建立一个快照。
	if(hThreadSnap==INVALID_HANDLE_VALUE)
	{
		//AfxMessageBox(_T("CreateToolhelp32Snapshot调用失败！"));
		return;
	}
	bool more=Thread32First(hThreadSnap,&th32);
	while(more)
	{
		if(th32.th32OwnerProcessID==Pid)
		{
			HANDLE oth=OpenThread(THREAD_ALL_ACCESS,FALSE,th32.th32ThreadID);
			if(!(::SuspendThread(oth))<=0)
			{
				//MessageBox(0,_T("冻结失败"),0,0);
			}
			else
			{
				//MessageBox(0,_T("已冻结！"),0,0);
			}
			CloseHandle(oth);
		}
		more=Thread32Next(hThreadSnap,&th32);//hTreadSnap快照句柄
	}
	CloseHandle(hThreadSnap);
}
void ResumeTask(DWORD Pid)//恢复一个进程中的所有线程
{
	THREADENTRY32 th32;
	th32.dwSize=sizeof(th32);

	HANDLE hThreadSnap=CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,0);
	if(hThreadSnap==INVALID_HANDLE_VALUE)
	{
		//AfxMessageBox(_T("CreateToolhelp32Snapshot调用失败！"));
		return;
	}

	bool more=Thread32First(hThreadSnap,&th32);
	while(more)
	{
		if(th32.th32OwnerProcessID==Pid)
		{
			HANDLE oth=OpenThread(THREAD_ALL_ACCESS,FALSE,th32.th32ThreadID);
			if(!(::ResumeThread(oth))<0)
			{
				//MessageBox(0,_T("解冻失败"),0,0);
			}
			else
			{
				//MessageBox(0,_T("已 解冻！"),0,0);
			}
			CloseHandle(oth);
		}
		more=Thread32Next(hThreadSnap,&th32);//hTreadSnap快照句柄
	}
	CloseHandle(hThreadSnap);
}
void GetPIDbyName(char *ProcessName,DWORD *Pid)//枚举当成进程，通过名字获得pid，同一个进程可能有多个pid，此处只返回第一个
{
	HANDLE hThreadSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//TH32CS_SNAPPROCESS - 在快照中包含系统中所有的进程。
	//TH32CS_SNAPTHREAD - 在快照中包含系统中所有的线程。
	PROCESSENTRY32 pe32={0};
	pe32.dwSize=sizeof(pe32);

	BOOL more=Process32First(hThreadSnap,&pe32);
	while(more)
	{
		if(strcmp(ProcessName,pe32.szExeFile)==0)
		{
			*Pid=pe32.th32ProcessID;
			CloseHandle(hThreadSnap);
			return ;
		}
		more=Process32Next(hThreadSnap,&pe32);
	}
	CloseHandle(hThreadSnap);
	*Pid=0;
}
int TraceAllThreadByPid(const DWORD Pid,DWORD *Tid)
{
	int count=0;
	THREADENTRY32 th32;
	th32.dwSize=sizeof(th32);//指定结构的长度，以字节为单位。在调用Thread32First时，设置这个成员为SIZEOF（THREADENTRY32）。如果你不初始化的dwSize，Thread32First将调用失败。 
	HANDLE hThreadSnap=::CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,0);
	//CreateToolhelp32Snapshot可以通过获取进程信息为指定的进程、进程使用的堆[HEAP]、模块[MODULE]、线程建立一个快照。
	if(hThreadSnap==INVALID_HANDLE_VALUE)
	{
		return -1;
	}
	bool more=Thread32First(hThreadSnap,&th32);
	while(more)
	{
		if(th32.th32OwnerProcessID==Pid)
		{
			Tid[count++]=th32.th32ThreadID;
		}
		more=Thread32Next(hThreadSnap,&th32);//hTreadSnap快照句柄
	}
	CloseHandle(hThreadSnap);
	return count;
}
int GetProcPath(const DWORD Pid,char *Path)
{
	HANDLE hModule;
	MODULEENTRY32 minfo;
	minfo.dwSize=sizeof(MODULEENTRY32);
    hModule=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,Pid);           
	Module32First(hModule,&minfo);
	strcpy(Path,minfo.szExePath);
    CloseHandle(hModule);
	return strlen(minfo.szExePath);
}
void CopyToClipboard(char *data)
{
	if(OpenClipboard(NULL))
	{
		HGLOBAL clipbuffer;//内存区
		char *buffer;//内存区缓冲区
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, strlen(data)+1);//分配内存
		buffer = (char*)GlobalLock(clipbuffer);
		strcpy(buffer, LPCSTR(data));
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_TEXT,clipbuffer);
		CloseClipboard();
	}
}
void CopyToClipboard2(WCHAR *data)
{
	if(OpenClipboard(NULL))
	{
		HGLOBAL clipbuffer;//内存区
		WCHAR *buffer;//内存区缓冲区
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, sizeof(WCHAR)*(wcslen(data)+1));//分配内存
		buffer = (WCHAR*)GlobalLock(clipbuffer);
		wcscpy(buffer, LPWSTR(data));
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_UNICODETEXT,clipbuffer);
		CloseClipboard();
	}
}
char* GetClipboard()
{
	if ( OpenClipboard(NULL) )
	{
		HANDLE hData = GetClipboardData(CF_TEXT);
		char * buffer = (char*)GlobalLock(hData);
		GlobalUnlock(hData);
		CloseClipboard();
		return buffer;
	}
}
bool MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize)
 {
    // Get the required size of the buffer that receives the Unicode
    // string.
    DWORD dwMinSize;
    dwMinSize = MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, NULL, 0);
 
    if(dwSize < dwMinSize)
    {
     return FALSE;
    }
    // Convert headers from ASCII to Unicode.
    MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize); //多字节转换为unicode
    return TRUE;
}