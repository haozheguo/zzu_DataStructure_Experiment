#include<iostream>
#include<stdlib.h>
#define STACK_SIZE 100
using namespace std;
#ifndef __SEQ_LIST_HEADER__
#define __SEQ_LIST_HEADER__
typedef char TElemType;

//二叉树
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef BiTree SElemType;
typedef BiTree QElemType;

#define INIT_SIZE 100
typedef int Status;
#define ERROR 1
#define OK    0
#define TRUE  1
#define FALSE 0
//#define NULL  0
#define OVERFLOW -1
#define UNDERFLOW -2

//先序创建二叉树
Status CreateBiTree(BiTree& T);
//打印树
Status Print(TElemType e);
//先序递归遍历
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//中序递归遍历
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//后序递归遍历
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//先序非递归遍历(借助先序特点实现）
Status PreOrderTraverse_unrecursion(BiTree T, Status(*Visit)(TElemType e));
//先序非递归遍历（用栈模拟递归实现）
Status PreOrderTraverse_stack(BiTree T, Status(*Visit)(TElemType e));
//中序非递归遍历（借助中序特点实现）
Status InOrderTraverse_unrecursion(BiTree T, Status(*Visit)(TElemType e));
//中序非递归遍历（用栈模拟递归实现）
Status InOrderTraverse_stack(BiTree T, Status(*Visit)(TElemType e));
//后序非递归遍历
Status PostOrderTraverse_unrecursion(BiTree T, Status(*Visit)(TElemType e));
//求二叉树中叶子结点数目的递归算法
int BiTreeLeaf(BiTree T);
//求二叉树深度的递归算法
int BiTreeDepth(BiTree T);
//判断二叉树是否相似的递归算法
int BiTreeSimilar(BiTree T1, BiTree T2);
// 编写求二叉树左右子树互换的递归算法
Status BiTreeExchange(BiTree& T);
//二叉树层序遍历
Status LevelBiTreeTraverse(BiTree T, Status(*Visit)(TElemType e));
//判断二叉树是否是完全二叉树
Status BiTreeFull(BiTree T);

#endif
//顺序栈
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

// 队列元素结构
typedef struct QNode {
	QElemType data;
	struct QNode* next;
} QNode, * QueuePtr;

// 队列结构
typedef struct {
	QueuePtr front;     // 队头指针
	QueuePtr rear;      // 队尾指针
} LinkQueue;

int main()
{
	BiTree T;
	cout << "请输入树T的先序序列(空结点用#表示):";
	CreateBiTree(T);
	cout << endl;
	cout << "先序递归遍历序列为：";
	PreOrderTraverse(T, Print);
	cout << endl;
	cout << endl;
	cout << "中序递归遍历序列为：";
	InOrderTraverse(T, Print);
	cout << endl;
	cout << endl;
	cout << "后序递归遍历序列为：";
	PostOrderTraverse(T, Print);
	cout << endl;
	cout << endl;
	cout << "先序非递归遍历序列(借助先序特点实现）为：";
	PreOrderTraverse_unrecursion(T, Print);
	cout << endl;
	cout << endl;
	cout << "先序非递归遍历序列（用栈模拟递归实现）为：";
	PreOrderTraverse_stack(T, Print);
	cout << endl;
	cout << endl;
	cout << "中序非递归遍历序列(借助中序特点实现）为：";
	InOrderTraverse_unrecursion(T, Print);
	cout << endl;
	cout << endl;
	cout << "中序非递归遍历序列（用栈模拟递归实现）为：";
	InOrderTraverse_stack(T, Print);
	cout << endl;
	cout << endl;
	cout << "后序非递归遍历序列为：";
	PostOrderTraverse_unrecursion(T, Print);
	cout << endl;
	cout << endl;
	cout << "该树的叶子结点数目为：";
	cout << BiTreeLeaf(T) << endl;
	cout << endl;
	cout << "该树的深度为：";
	cout << BiTreeDepth(T) << endl;
	cout << endl;
	BiTree T1;
	cout << "请输入树T1的先序遍历序列：";
	CreateBiTree(T1);
	cout << endl;
	if (BiTreeSimilar(T, T1))
		cout << "T和T1相似!" << endl;
	else
		cout << "T和T1不相似!" << endl;
	cout << endl;
	BiTreeExchange(T1);
	cout << "T1交换左右子树后的先序序列为：";
	PreOrderTraverse(T1, Print);
	cout << endl;
	cout << endl;
	cout << "二叉树的层序遍历序列为：";
	LevelBiTreeTraverse(T, Print);
	cout << endl;
	cout << endl;
	if (BiTreeFull(T))
		cout << "T是完全二叉树！" << endl;
	else
		cout << "T不是完全二叉树！" << endl;
	cout << endl;
	return 0;
}
Status InitStack(SqStack& S) {
	S.base = (SElemType*)malloc(STACK_SIZE * sizeof(SElemType));
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_SIZE;
	return OK;
}
Status GetTop(SqStack S, SElemType& e) {
	if (S.top == S.base)return ERROR;
	e = *(S.top - 1);
	return OK;
}
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)return ERROR;
	*(S.top++) = e;
	return OK;
}
Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)return ERROR;
	e = *(--S.top);
	return OK;
}
Status StackEmpty(SqStack S) {
	if (S.top == S.base)return TRUE;
	else return FALSE;
}
Status DestroyStack(SqStack& S) {
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
	return OK;
}
Status InitQueue(LinkQueue& Q) {
	Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.rear)exit(OVERFLOW);
	Q.front = Q.rear;
	return OK;
}
Status QueueEmpty(LinkQueue Q) {
	if (Q.rear == Q.front)return TRUE;
	else return FALSE;
}
Status EnQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue(LinkQueue& Q, QElemType& e) {
	if (Q.rear == Q.front)return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}
//先序创建二叉树
Status CreateBiTree(BiTree& T) {
	TElemType ch;
	cin >> ch;
	if (ch == '#')T = NULL;
	else {
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
//打印树
Status Print(TElemType e) {
	cout << e << " ";
	return OK;
}
//先序递归遍历
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		Visit(T->data);
		PreOrderTraverse(T->lchild, Visit);
		PreOrderTraverse(T->rchild, Visit);
	}
	return OK;
}
//中序递归遍历
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		InOrderTraverse(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse(T->rchild, Visit);
	}
	return OK;
}
//后序递归遍历
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
		Visit(T->data);
	}
	return OK;
}
//先序非递归遍历(借助先序特点实现）
Status PreOrderTraverse_unrecursion(BiTree T, Status(*Visit)(TElemType e)) {
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			Visit(p->data);
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			p = p->rchild;
		}
	}
	DestroyStack(S);
	return OK;
}
//先序非递归遍历（用栈模拟递归实现）
Status PreOrderTraverse_stack(BiTree T, Status(*Visit)(TElemType e)) {
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S)) {
		while (p) {
			Push(S, p);
			Visit(p->data);
			p = p->lchild;
		}
		if (!StackEmpty(S)) {
			Pop(S, p);
			p = p->rchild;
		}
	}
	DestroyStack(S);
	return OK;
}
//中序非递归遍历（借助中序特点实现）
Status InOrderTraverse_unrecursion(BiTree T, Status(*Visit)(TElemType e)) {
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			Visit(p->data);
			p = p->rchild;
		}
	}
	DestroyStack(S);
	return OK;
}
//中序非递归遍历（用栈模拟递归实现）
Status InOrderTraverse_stack(BiTree T, Status(*Visit)(TElemType e)) {
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S)) {
		while (p) {
			Push(S, p);
			p = p->lchild;
		}
		if (!StackEmpty(S)) {
			Pop(S, p);
			Visit(p->data);
			p = p->rchild;
		}
	}
	DestroyStack(S);
	return OK;
}
//后序非递归遍历
Status PostOrderTraverse_unrecursion(BiTree T, Status(*Visit)(TElemType e)) {
	SqStack S;
	InitStack(S);
	BiTree p = T, r = NULL;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p);
			p = p->lchild;
		}
		else {
			GetTop(S, p);
			if (p->rchild && p->rchild != r) {
				p = p->rchild;
				Push(S, p);
				p = p->lchild;
			}
			else {
				Pop(S, p);
				Visit(p->data);
				r = p;
				p = NULL;
			}
		}
	}
	DestroyStack(S);
	return OK;
}
//求二叉树中叶子结点数目的递归算法
int BiTreeLeaf(BiTree T) {
	int L, R;
	if (!T)return 0;
	if (!T->lchild && !T->rchild)
		return 1;
	else {
		L = BiTreeLeaf(T->lchild);
		R = BiTreeLeaf(T->rchild);
		return L + R;
	}
}
//求二叉树深度的递归算法
int BiTreeDepth(BiTree T) {
	int cnt = 0;
	int L = 0, R = 0;
	if (T == NULL)return 0;
	else {
		L = BiTreeDepth(T->lchild);
		R = BiTreeDepth(T->rchild);
		cnt = (L > R ? L : R) + 1;
		return cnt;
	}
}
//判断二叉树是否相似的递归算法
int BiTreeSimilar(BiTree T1, BiTree T2) {
	if (!T1 && !T2)return TRUE;
	else {
		if (T1 && T2) {
			if (BiTreeSimilar(T1->lchild, T2->lchild) && BiTreeSimilar(T1->rchild, T2->rchild))
				return TRUE;
		}
	}
	return FALSE;
}
// 编写求二叉树左右子树互换的递归算法
Status BiTreeExchange(BiTree& T) {
	if (!T)return ERROR;
	if (T) {
		BiTree p;
		p = T->lchild;
		T->lchild = T->rchild;
		T->rchild = p;
		BiTreeExchange(T->lchild);
		BiTreeExchange(T->rchild);
		return OK;
	}
}
//二叉树层序遍历
Status LevelBiTreeTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p = T;
	if (!T)return OK;
	EnQueue(Q, T);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);
		Visit(p->data);
		if (p->lchild)EnQueue(Q, p->lchild);
		if (p->rchild)EnQueue(Q, p->rchild);
	}
	return OK;
}
//判断二叉树是否是完全二叉树
Status BiTreeFull(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p = T;
	int leaf = FALSE;
	if (!T)return TRUE;
	EnQueue(Q, T);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);
		if (!p->lchild && p->rchild)
			return FALSE;
		if (leaf && (p->lchild || p->rchild))
			return FALSE;
		if (p->lchild)EnQueue(Q, p->lchild);
		if (p->rchild)EnQueue(Q, p->rchild);
		if ((p->lchild && !p->rchild) || (!p->lchild && p->rchild))
			leaf = TRUE;
	}
	return TRUE;
}
