#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#define OK 1
#define ERROR 0
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
typedef int Status;
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
BiTree Root;
//1.二叉排序树的创建、插入
int InsertBST(BiTree& T, int e);
//2.二叉排序树的查找
Status SearchBST(BiTree T, int key, BiTree f, BiTree& p);
//3.二叉排序树的中序遍历输出
void InOrderPrint(BiTree T);

int main() {
	BiTree p;
	int i, val;
	int a[10] = { 24,43,53,32,33,45,65,87,76,12 };
	for (i = 1; i < 10; i++)
		InsertBST(Root, a[i]);
	cout << "二叉排序树的中序遍历序列为：" << endl;
	InOrderPrint(Root);
	int key;
	cout << "请输入你要查找的关键字：";
	cin >> key;
	val = SearchBST(Root, key, NULL, p);
	if (val) {
		cout << "查找成功！" << endl;
	}
	else
		cout << "未能找到该元素！" << endl;
	cout << "请输入你要查找的关键字：";
	cin >> key;
	val = SearchBST(Root, key, NULL, p);
	if (val) {
		cout << "查找成功！" << endl;
	}
	else
		cout << "未能找到该元素！" << endl;
	return 0;
}
//1.二叉排序树的创建、插入
int InsertBST(BiTree& T, int e) {
	BiTree s, p;
	if (!SearchBST(T, e, NULL, p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p)
			T = s;
		else if (e < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return 1;
	}
	else
		return 0;
}
//2.二叉排序树的查找
Status SearchBST(BiTree T, int key, BiTree f, BiTree& p) {
	int val;
	if (!T)
	{
		p = f;
		return 0;
	}
	else if (key == T->data)
	{
		p = T;
		return 1;
	}
	else if (key < T->data)
		val = SearchBST(T->lchild, key, T, p);
	else
		val = SearchBST(T->rchild, key, T, p);
	return val;
}
//3.二叉排序树的中序遍历输出
void InOrderPrint(BiTree T) {
	if (T) {
		InOrderPrint(T->lchild);
		cout << T->data << endl;
		InOrderPrint(T->rchild);
	}
}