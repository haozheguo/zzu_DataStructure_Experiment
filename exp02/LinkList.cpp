#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#define OK 1
#define ERROR 0
typedef int elemtype;
typedef int status;
typedef struct lnode {
	elemtype data;
	struct lnode* next;
}lnode, * linklist;//带头结点的单链表
//1.逆序建立单链表
void CreateList_L(linklist& L, int n);
//2.遍历单链表(输出单链表每个元素的值)
void PrintList(linklist L);
//3.单链表的插入
status ListInsert(linklist& L, int i, elemtype e);
//4.单链表的删除
status ListDelete(linklist& L, int i, elemtype& e);

int main() {
	linklist L;
	int cnt;
	elemtype e;
	cout << "请输入你要逆序建立的单链表元素个数:";
	cin >> cnt;
	CreateList_L(L, cnt);
	cout << "单链表序列为：" << endl;
	PrintList(L);
	cout << endl << "在单链表第5个元素前插入一个值为999的元素后，单链表序列为：" << endl;
	ListInsert(L, 5, 999);
	PrintList(L);
	cout << endl << "删除单链表第5个元素后，单链表序列为：" << endl;
	ListDelete(L, 5, e);
	PrintList(L);
	cout << "被删除的元素是：" << e << endl;
}

//1.逆序建立单链表
void CreateList_L(linklist& L, int n) {
	L = (linklist)malloc(sizeof(lnode));
	L->next = NULL;
	for (int i = n; i > 0; i--) {
		linklist p = (lnode*)malloc(sizeof(lnode));
		cout << "请输入元素值：";
		cin >> p->data;
		p->next = L->next; L->next = p;
	}
}
//2.遍历单链表(输出单链表每个元素的值)
void PrintList(linklist L) {
	linklist p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//3.单链表的插入
status ListInsert(linklist& L, int i, elemtype e) {
	linklist p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next; j++;
	}
	if (!p || j > i - 1)return ERROR;
	linklist s = (linklist)malloc(sizeof(lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//4.单链表的删除
status ListDelete(linklist& L, int i, elemtype& e) {
	linklist p = L, q;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next; j++;
	}
	if (!(p->next) || j > i - 1)return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}