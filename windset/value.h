#pragma once
#include "resource.h"
#include <string>
using namespace std;
#define MAXTOOLTIP 100//���������ʾ������
#define VALUEMAP(expr,expr2,expr3) {expr,_T(#expr#expr2),expr3}//����ֵ��ʾӳ��ĺ꣬���������������
typedef struct
{
	int id;
	string value;
	void *pOther;//Ϊ����չ����
}ValueIdMap;//ֵ��ʾӳ�䣬������ id==0 && value=="" ����