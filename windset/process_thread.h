#include <stdio.h>
#include <Windows.h>
void EnableDebugPriv();//提升权限
void SuspendTask(const DWORD Pid);//挂起一个进程中的所有线程
void ResumeTask(DWORD Pid);//恢复一个进程中的所有线程
int TraceAllThreadByPid(const DWORD Pid,DWORD *Tid);//遍历一个进程中所有的线程,返回线程数
void GetPIDbyName(char *ProcessName,DWORD *Pid);//枚举当成进程，通过名字获得pid，同一个进程可能有多个pid，此处只返回第一个
int GetProcPath(const DWORD Pid,char *Path);//通过pid取得程序路径
void CopyToClipboard(char *data);//将asci字符复制到剪贴板
void CopyToClipboard2(WCHAR *data);//将unicode字符复制到剪贴板
bool MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);//多字节转换为宽字节
char* GetClipboard();//取得剪贴板内容