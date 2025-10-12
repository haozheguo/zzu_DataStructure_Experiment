#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define OK 1
#define ERROR 0
#define stackinitsize 20
#define stackincrement 10
typedef char elemtype;
typedef int status;
typedef struct {
	elemtype* base;
	elemtype* top;
	int stacksize;
}sqstack;
//1.初始化栈
status InitStack(sqstack& S);
//2.将栈置空
status ClearStack(sqstack& S);
//3.入栈
status Push(sqstack& S, elemtype e);
//4.出栈
status Pop(sqstack& S, elemtype& e);
//5.取栈顶元素
status GetTop(sqstack S, elemtype& e);
//6.摧毁栈
status DestroyStack(sqstack& S);
//栈的括号匹配检验
status CheckMatch_Brackets(char* str);
//栈的中心对称序列检验
status CheckMatch_Symmetry(char* str);
int main() {
	char str[30];
	cout << "栈的括号匹配检验函数测试1：" << endl;
	cout << "请输入待检测的括号字符串序列：";
	cin >> str;
	status flag = CheckMatch_Brackets(str);
	if (flag)
		cout << "括号匹配！" << endl;
	else
		cout << "括号不匹配！" << endl;
	cout << "栈的括号匹配检验函数测试2：" << endl;
	cout << "请输入待检测的括号字符串序列：";
	cin >> str;
	flag = CheckMatch_Brackets(str);
	if (flag)
		cout << "括号匹配！" << endl;
	else
		cout << "括号不匹配！" << endl;
	cout << "栈的中心对称序列检验函数测试1：" << endl;
	cout << "请输入待检测的字符串序列（以@做为对称中心，#结尾）：";
	cin >> str;
	flag = CheckMatch_Symmetry(str);
	if (flag)
		cout << "是中心对称！" << endl;
	else
		cout << "不是中心对称！" << endl;
	cout << "栈的中心对称序列检验函数测试2：" << endl;
	cout << "请输入待检测的字符串序列（以@做为对称中心，#结尾）：";
	cin >> str;
	flag = CheckMatch_Symmetry(str);
	if (flag)
		cout << "是中心对称！" << endl;
	else
		cout << "不是中心对称！" << endl;
	return 0;
}
//1.初始化栈
status InitStack(sqstack& S) {
	S.base = (elemtype*)malloc(stackinitsize * sizeof(elemtype));
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = stackinitsize;
	return OK;
}
//2.将栈置空
status ClearStack(sqstack& S) {
	if (S.top != S.base)
		S.top = S.base;
	return OK;
}
//3.入栈
status Push(sqstack& S, elemtype e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (elemtype*)realloc(S.base, (S.stacksize + stackincrement) * sizeof(elemtype));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += stackincrement;
	}
	*S.top++ = e;
	return OK;
}
//4.出栈
status Pop(sqstack& S, elemtype& e) {
	if (S.top == S.base)return ERROR;
	e = *--S.top;
	return OK;
}
//5.取栈顶元素
status GetTop(sqstack S, elemtype& e) {
	if (S.top == S.base)return ERROR;
	e = *(S.top - 1);
	return OK;
}
//6.摧毁栈
status DestroyStack(sqstack& S) {
	if (S.base)free(S.base);
	S.top = NULL;
	S.stacksize = 0;
	return OK;
}
//栈的括号匹配检验
status CheckMatch_Brackets(char* str) {
	sqstack S;
	InitStack(S);
	ClearStack(S);
	int len = strlen(str);
	elemtype e;
	int i;
	for (int i = 0; i < len; i++) {
		switch (str[i]) {
		case '{':
		case '[':
		case '(':
			Push(S, str[i]);
			break;
		case '}':
			if (S.top == S.base)
				return ERROR;
			Pop(S, e);
			if (e != '{')
				return ERROR;
			break;
		case ']':
			if (S.top == S.base)
				return ERROR;
			Pop(S, e);
			if (e != '[')
				return ERROR;
			break;
		case ')':
			if (S.top == S.base)
				return ERROR;
			Pop(S, e);
			if (e != '(')
				return ERROR;
			break;
		default:
			break;
		}
	}
	if (S.top != S.base)return ERROR;
	return OK;
}
//栈的中心对称序列检验
status CheckMatch_Symmetry(char* str) {
	sqstack S;
	elemtype e;
	char* p = str;
	InitStack(S);
	while (*p != '@') {
		Push(S, *p);
		p++;
	}
	p++;
	while (*p != '#') {
		Pop(S, e);
		if (e != *p)
			return ERROR;
		p++;
	}
	if (S.top != S.base)return ERROR;
	return OK;
}