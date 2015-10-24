#pragma once
#include "resource.h"
#include <string>
using namespace std;
#define MAXTOOLTIP 100//最大气泡提示的数量
#define VALUEMAP(expr,expr2,expr3) {expr,_T(#expr#expr2),expr3}//用与值显示映射的宏，后面参数可以留空
typedef struct
{
	int id;
	string value;
	void *pOther;//为了拓展方便
}ValueIdMap;//值显示映射，数组以 id==0 && value=="" 结束