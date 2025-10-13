#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define maxqsize 20
typedef char qelemtype;
typedef int status;
//约定以少用一个元素空间，以“队列头指针
//在队列尾指针的下一位置”作为队列满的标志
typedef struct {
	qelemtype* base;
	int front;
	int rear;
}sqqueue;
//1.初始化队列
status InitQueue(sqqueue& Q);
//2.求队列长度
int QueueLength(sqqueue Q);
//3.入队列
status EnQueue(sqqueue& Q, qelemtype e);
//4.队前元素出队列
status DeQueueFront(sqqueue& Q, qelemtype& e);
//5.队后元素出队列
status DeQueueRear(sqqueue& Q, qelemtype& e);
//6.判断是否队空
status QueueEmpty(sqqueue Q);
//7.判断是否队满
status QueueFull(sqqueue Q);
//8.获取队头元素
status GetHead(sqqueue Q, qelemtype& e);
//9.摧毁队列
status DestroyQueue(sqqueue& Q);
//中心对称的字符序列的检验
int CenterMatch(char* str);
int main() {
	sqqueue Q;
	qelemtype e;
	InitQueue(Q);
	cout << "-----------循环队列的基本操作测试：----------" << endl;
	EnQueue(Q, 'a');
	cout << "入队列'a',队列长度为：" << QueueLength(Q) << endl;
	EnQueue(Q, 'b');
	cout << "入队列'b',队列长度为：" << QueueLength(Q) << endl;
	EnQueue(Q, 'c');
	cout << "入队列'c',队列长度为：" << QueueLength(Q) << endl;
	EnQueue(Q, 'd');
	cout << "入队列'd',队列长度为：" << QueueLength(Q) << endl;
	if (QueueEmpty(Q))
		cout << "队列为空!" << endl;
	else
		cout << "队列不为空！" << endl;
	DeQueueFront(Q, e);
	cout << "出队头元素：" << e << ",队列长度为：" << QueueLength(Q) << endl;
	DeQueueRear(Q, e);
	cout << "出队头元素：" << e << ",队列长度为：" << QueueLength(Q) << endl;
	DeQueueFront(Q, e);
	cout << "出队头元素：" << e << ",队列长度为：" << QueueLength(Q) << endl;
	DeQueueRear(Q, e);
	cout << "出队头元素：" << e << ",队列长度为：" << QueueLength(Q) << endl;
	if (QueueEmpty(Q))
		cout << "队列为空!" << endl;
	else
		cout << "队列不为空！" << endl;
	DestroyQueue(Q);
	cout << "----------是否是中心对称序列测试----------" << endl;
	char str[maxqsize + 1];
	cout << "请输入待检测的字符串（@做间隔，#做结尾）：";
	cin >> str;
	if (CenterMatch(str))
		cout << "待检测序列是中心对称序列！" << endl;
	else
		cout << "待检测序列不是中心对称序列！" << endl;
	cout << "请输入待检测的字符串（@做间隔，#做结尾）：";
	cin >> str;
	if (CenterMatch(str))
		cout << "待检测序列是中心对称序列！" << endl;
	else
		cout << "待检测序列不是中心对称序列！" << endl;
	return 0;
}
//1.初始化队列
status InitQueue(sqqueue& Q) {
	Q.base = (qelemtype*)malloc(sizeof(qelemtype) * maxqsize);
	if (!Q.base)exit(-1);
	Q.front = Q.rear = 0;
	return OK;
}
//2.求队列长度
int QueueLength(sqqueue Q) {
	return (Q.rear - Q.front + maxqsize) % maxqsize;
}
//3.入队列
status EnQueue(sqqueue& Q, qelemtype e) {
	if ((Q.rear + 1) % maxqsize == Q.front)return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % maxqsize;
	return OK;
}
//4.队前元素出队列
status DeQueueFront(sqqueue& Q, qelemtype& e) {
	if (Q.rear == Q.front)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % maxqsize;
	return OK;
}
//5.队后元素出队列
status DeQueueRear(sqqueue& Q, qelemtype& e) {
	if (Q.rear == Q.front)return ERROR;
	e = Q.base[Q.rear - 1];
	Q.rear = (Q.rear - 1) % maxqsize;
	return OK;
}
//6.判断是否队空
status QueueEmpty(sqqueue Q) {
	if (Q.front == Q.rear)return OK;
	else
		return ERROR;
}
//7.判断是否队满
status QueueFull(sqqueue Q) {
	if ((Q.rear + 1) % maxqsize == Q.front)return OK;
	else
		return ERROR;
}
//8.获取队头元素
status GetHead(sqqueue Q, qelemtype& e) {
	if (Q.rear == Q.front)return ERROR;
	e = Q.base[Q.front];
	return OK;
}
//9.摧毁队列
status DestroyQueue(sqqueue& Q) {
	if (Q.base) {
		Q.front = Q.rear = NULL;
		free(Q.base);
	}
	return OK;
}
//中心对称的字符序列的检验
int CenterMatch(char* str) {
	sqqueue Q;
	char e1, e2;
	char* p = str;
	InitQueue(Q);
	while (*p != '@') {
		EnQueue(Q, *p);
		p++;
	}
	p++;
	while (*p != '#') {
		EnQueue(Q, *p);
		p++;
	}
	while (QueueLength(Q) != 0) {
		DeQueueFront(Q, e1);
		DeQueueRear(Q, e2);
		if (e1 != e2)
			break;
	}
	if (Q.rear != Q.front)
		return ERROR;
	return OK;
}