#include "process_thread.h"
#include "stdafx.h"
#include <tlhelp32.h>//�����ڴ��ļ������
void EnableDebugPriv(void)//����Ȩ��
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
void SuspendTask(const DWORD Pid)//����һ�������е������߳�
{
	THREADENTRY32 th32;
	th32.dwSize=sizeof(th32);//ָ���ṹ�ĳ��ȣ����ֽ�Ϊ��λ���ڵ���Thread32Firstʱ�����������ԱΪSIZEOF��THREADENTRY32��������㲻��ʼ����dwSize��Thread32First������ʧ�ܡ� 
	HANDLE hThreadSnap=::CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,0);
	//CreateToolhelp32Snapshot����ͨ����ȡ������ϢΪָ���Ľ��̡�����ʹ�õĶ�[HEAP]��ģ��[MODULE]���߳̽���һ�����ա�
	if(hThreadSnap==INVALID_HANDLE_VALUE)
	{
		//AfxMessageBox(_T("CreateToolhelp32Snapshot����ʧ�ܣ�"));
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
				//MessageBox(0,_T("����ʧ��"),0,0);
			}
			else
			{
				//MessageBox(0,_T("�Ѷ��ᣡ"),0,0);
			}
			CloseHandle(oth);
		}
		more=Thread32Next(hThreadSnap,&th32);//hTreadSnap���վ��
	}
	CloseHandle(hThreadSnap);
}
void ResumeTask(DWORD Pid)//�ָ�һ�������е������߳�
{
	THREADENTRY32 th32;
	th32.dwSize=sizeof(th32);

	HANDLE hThreadSnap=CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,0);
	if(hThreadSnap==INVALID_HANDLE_VALUE)
	{
		//AfxMessageBox(_T("CreateToolhelp32Snapshot����ʧ�ܣ�"));
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
				//MessageBox(0,_T("�ⶳʧ��"),0,0);
			}
			else
			{
				//MessageBox(0,_T("�� �ⶳ��"),0,0);
			}
			CloseHandle(oth);
		}
		more=Thread32Next(hThreadSnap,&th32);//hTreadSnap���վ��
	}
	CloseHandle(hThreadSnap);
}
void GetPIDbyName(char *ProcessName,DWORD *Pid)//ö�ٵ��ɽ��̣�ͨ�����ֻ��pid��ͬһ�����̿����ж��pid���˴�ֻ���ص�һ��
{
	HANDLE hThreadSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//TH32CS_SNAPPROCESS - �ڿ����а���ϵͳ�����еĽ��̡�
	//TH32CS_SNAPTHREAD - �ڿ����а���ϵͳ�����е��̡߳�
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
	th32.dwSize=sizeof(th32);//ָ���ṹ�ĳ��ȣ����ֽ�Ϊ��λ���ڵ���Thread32Firstʱ�����������ԱΪSIZEOF��THREADENTRY32��������㲻��ʼ����dwSize��Thread32First������ʧ�ܡ� 
	HANDLE hThreadSnap=::CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,0);
	//CreateToolhelp32Snapshot����ͨ����ȡ������ϢΪָ���Ľ��̡�����ʹ�õĶ�[HEAP]��ģ��[MODULE]���߳̽���һ�����ա�
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
		more=Thread32Next(hThreadSnap,&th32);//hTreadSnap���վ��
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
		HGLOBAL clipbuffer;//�ڴ���
		char *buffer;//�ڴ���������
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, strlen(data)+1);//�����ڴ�
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
		HGLOBAL clipbuffer;//�ڴ���
		WCHAR *buffer;//�ڴ���������
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, sizeof(WCHAR)*(wcslen(data)+1));//�����ڴ�
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
    MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize); //���ֽ�ת��Ϊunicode
    return TRUE;
}