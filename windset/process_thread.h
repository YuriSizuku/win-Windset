#include <stdio.h>
#include <Windows.h>
void EnableDebugPriv();//����Ȩ��
void SuspendTask(const DWORD Pid);//����һ�������е������߳�
void ResumeTask(DWORD Pid);//�ָ�һ�������е������߳�
int TraceAllThreadByPid(const DWORD Pid,DWORD *Tid);//����һ�����������е��߳�,�����߳���
void GetPIDbyName(char *ProcessName,DWORD *Pid);//ö�ٵ��ɽ��̣�ͨ�����ֻ��pid��ͬһ�����̿����ж��pid���˴�ֻ���ص�һ��
int GetProcPath(const DWORD Pid,char *Path);//ͨ��pidȡ�ó���·��
void CopyToClipboard(char *data);//��asci�ַ����Ƶ�������
void CopyToClipboard2(WCHAR *data);//��unicode�ַ����Ƶ�������
bool MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);//���ֽ�ת��Ϊ���ֽ�
char* GetClipboard();//ȡ�ü���������