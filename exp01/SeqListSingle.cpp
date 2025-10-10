#ifndef __SEQ_LIST_HEADER__
#define __SEQ_LIST_HEADER__
/// Sequence List ADT and Impl.
#include<stdio.h>
#include<stdlib.h> 
typedef int ElemType;
#define INIT_SIZE 100
typedef int Status;
#define ERROR 1
#define OK    0
//#define NULL  0
#define OVERFLOW -1
#define UNDERFLOW -2
//动态分配数组实现的顺序表
typedef struct SeqList {

	ElemType* data;
	int capacity;
	int size;
}SeqList;
//动态分配数组顺序表基本操作
Status SeqList_create(SeqList& list);
Status SeqList_clear(SeqList& list);
Status SeqList_destroy(SeqList& list);
Status SeqList_print(SeqList& list);
Status SeqList_insert(SeqList& list, int idx, ElemType elem);
Status SeqList_delete(SeqList& list, int idx, ElemType& elem);
//实验内容实现：
//1.a 在非递减有序的顺序表中插入一个元素 x，保持顺序表有序性(不使用基本操作）;
Status SeqList_OrderInsert_unuse(SeqList& list, ElemType x);
//1.b 在非递减有序的顺序表中插入一个元素 x，保持顺序表有序性(使用基本操作）;
Status SeqList_OrderInsert_use(SeqList& list, ElemType x);
//2.顺序表元素的逆置;
Status SeqList_Reverse(SeqList& list);
//两个（有序或无序）顺序表的合并
Status SeqList_Combine(SeqList list1, SeqList list2, SeqList& L);

//静态分配数组实现的顺序表
typedef struct StaticSeqList {
	ElemType data[INIT_SIZE];
	int capacity;
	int size;
}StaticSeqList;
//静态分配数组顺序表基本操作
Status StaticSeqList_create(StaticSeqList& list);
Status StaticSeqList_clear(StaticSeqList& list);
Status StaticSeqList_print(StaticSeqList& list);
Status StaticSeqList_insert(StaticSeqList& list, int idx, ElemType elem);
Status StaticSeqList_delete(StaticSeqList& list, int idx, ElemType& elem);
//实验内容实现：
//1.a 在非递减有序的顺序表中插入一个元素 x，保持顺序表有序性(不使用基本操作）;
Status StaticSeqList_OrderInsert_unuse(StaticSeqList& list, ElemType x);
//1.b 在非递减有序的顺序表中插入一个元素 x，保持顺序表有序性(使用基本操作）;
Status StaticSeqList_OrderInsert_use(StaticSeqList& list, ElemType x);
//2.顺序表元素的逆置;
Status StaticSeqList_Reverse(StaticSeqList& list);
//两个（有序或无序）顺序表的合并
Status StaticSeqList_Combine(StaticSeqList list1, StaticSeqList list2, StaticSeqList& L);
#endif
int main(int argc, char** argv)
{
	printf("————动态分配数组顺序表实现的功能测试————\n");
	SeqList L1, L2;
	SeqList_create(L1);
	SeqList_create(L2);
	for (int i = 0; i < 10; i++) {
		SeqList_insert(L1, i, 3 * i + 1);
		SeqList_insert(L2, i, 2 * i + 1);
	}
	printf("L1: ");
	SeqList_print(L1);
	printf("L2: ");
	SeqList_print(L2);
	printf("不使用基本操作实现的在L1中有序插入x操作测试:\n");
	SeqList_OrderInsert_unuse(L1, 8);
	SeqList_OrderInsert_unuse(L1, 12);
	SeqList_OrderInsert_unuse(L1, 36);
	printf("L1: ");
	SeqList_print(L1);
	printf("使用基本操作实现的在L2中有序插入x操作测试:\n");
	SeqList_OrderInsert_use(L2, 6);
	SeqList_OrderInsert_use(L2, 0);
	SeqList_OrderInsert_use(L2, 20);
	printf("L2: ");
	SeqList_print(L2);
	printf("对顺序表L1元素逆置操作测试：\n");
	SeqList_Reverse(L1);
	printf("L1:");
	SeqList_print(L1);
	printf("对顺序表L1，顺序表L2进行合并的测试：\n");
	SeqList L;
	SeqList_Reverse(L1);
	SeqList_Combine(L1, L2, L);
	printf("合并后：\n");
	SeqList_print(L);
	SeqList_destroy(L1);
	SeqList_destroy(L2);
	SeqList_destroy(L);
	printf("————静态分配数组顺序表实现的功能测试————\n");
	StaticSeqList L3, L4;
	StaticSeqList_create(L3);
	StaticSeqList_create(L4);
	for (int i = 0; i < 10; i++) {
		StaticSeqList_insert(L3, i, 3 * i + 1);
		StaticSeqList_insert(L4, i, 2 * i + 1);
	}
	printf("L3: ");
	StaticSeqList_print(L3);
	printf("L4: ");
	StaticSeqList_print(L4);
	printf("不使用基本操作实现的在L3中有序插入x操作测试:\n");
	StaticSeqList_OrderInsert_unuse(L3, 8);
	StaticSeqList_OrderInsert_unuse(L3, 0);
	StaticSeqList_OrderInsert_unuse(L3, 36);
	printf("L3: ");
	StaticSeqList_print(L3);
	printf("使用基本操作实现的在L4中有序插入x操作测试:\n");
	StaticSeqList_OrderInsert_use(L4, 6);
	StaticSeqList_OrderInsert_use(L4, 0);
	StaticSeqList_OrderInsert_use(L4, 20);
	printf("L4: ");
	StaticSeqList_print(L4);
	printf("对顺序表L3元素逆置操作测试：\n");
	StaticSeqList_Reverse(L3);
	printf("L3: ");
	StaticSeqList_print(L3);
	printf("对顺序表L3，顺序表L4进行合并的测试：\n");
	StaticSeqList L5;
	StaticSeqList_create(L5);
	StaticSeqList_Reverse(L3);
	StaticSeqList_Combine(L3, L4, L5);
	printf("L5: ");
	StaticSeqList_print(L5);
	return 0;
}
Status SeqList_create(SeqList& list) {
    list.data = (ElemType*)malloc(sizeof(ElemType) * INIT_SIZE);
    if (NULL == list.data) return ERROR;
    list.capacity = INIT_SIZE;
    list.size = 0;
    return OK;
}
Status SeqList_clear(SeqList& list) {
    list.size = 0;
    return OK;
}
Status SeqList_destroy(SeqList& list) {
    if (NULL != list.data) {
        free(list.data);
    }
    return OK;
}
Status SeqList_print(SeqList& list) {
    for (int i = 0; i < list.size; i++)
        printf("%d\t", list.data[i]);

    printf("\n");
    return OK;
}
Status SeqList_insert(SeqList& list, int idx, ElemType elem) {
    //FIXME:increate the SeqList capacity
    if (idx < 0 || list.size == list.capacity
        || idx > list.capacity - 1)
        return ERROR;
    for (int i = list.size - 1; i > idx - 1; i--) {
        list.data[i + 1] = list.data[i];
    }
    //FIXME:ElemType is struct or build-in simple type?
    list.data[idx] = elem;
    list.size++;
    return OK;
}
Status SeqList_delete(SeqList& list, int idx, ElemType& elem) {
    if (idx < 0 || idx > list.size - 1) return ERROR;
    elem = list.data[idx];

    for (int i = idx; i < list.size - 1; i++)
        list.data[i] = list.data[i + 1];
    list.size--;
    return OK;
}
//1.a 在非递减有序的顺序表中插入一个元素 x，保持顺序表有序性(不使用基本操作）;
Status SeqList_OrderInsert_unuse(SeqList& list, ElemType x)
{
    if (list.size == list.capacity)return ERROR;
    int i = list.size - 1;
    while (list.data[i] >= x)
    {
        list.data[i + 1] = list.data[i];
        i--;
    }
    list.data[i + 1] = x;
    list.size++;
    return OK;
}
//1.b 在非递减有序的顺序表中插入一个元素 x，保持顺序表有序性(使用基本操作）;
Status SeqList_OrderInsert_use(SeqList& list, ElemType x)
{
    if (list.size == list.capacity)return ERROR;
    int i = 0;
    while (x >= list.data[i] && i < list.size) {
        i++;
    }
    SeqList_insert(list, i, x);
    return OK;
}
//2.顺序表元素的逆置;
Status SeqList_Reverse(SeqList& list)
{
    if (list.size == 0)return ERROR;
    ElemType* t = (ElemType*)malloc(sizeof(ElemType) * list.size);
    if (!t)return ERROR;
    for (int i = 0; i < list.size; i++)
        t[i] = list.data[i];
    for (int i = 0; i < list.size; i++)
        list.data[i] = t[list.size - i - 1];
    free(t);
    return OK;
}
//两个（有序或无序）顺序表的合并
Status SeqList_Combine(SeqList list1, SeqList list2, SeqList& L)
{
    L.data = (ElemType*)malloc(sizeof(ElemType) * (list1.size + list2.size));
    if (!L.data)return ERROR;
    L.capacity = list1.size + list2.size;
    L.size = 0;
    int i = 0, j = 0, k = 0;
    while (i < list1.size && j < list2.size) {
        if (list1.data[i] > list2.data[j]) {
            L.data[k] = list2.data[j];
            k++; j++; L.size++;
        }
        else if (list1.data[i] < list2.data[j]) {
            L.data[k] = list1.data[i];
            k++; i++; L.size++;
        }
        else if (list1.data[i] == list2.data[j]) {
            L.data[k] = list1.data[i];
            k++; i++; j++; L.size++;
        }
    }
    for (; i < list1.size; k++, i++, L.size++)
        L.data[k] = list1.data[i];
    for (; j < list2.size; k++, j++, L.size++)
        L.data[k] = list2.data[j];
    return OK;
}


//静态数组
Status StaticSeqList_create(StaticSeqList& list) {
    list.capacity = INIT_SIZE;
    list.size = 0;
    return OK;
}
Status StaticSeqList_clear(StaticSeqList& list) {
    list.size = 0;
    return OK;
}
Status StaticSeqList_print(StaticSeqList& list) {
    for (int i = 0; i < list.size; i++)
        printf("%d\t", list.data[i]);
    printf("\n");
    return OK;
}
Status StaticSeqList_insert(StaticSeqList& list, int idx, ElemType elem) {
    if (idx < 0 || list.size == list.capacity
        || idx > list.capacity - 1)
        return ERROR;
    for (int i = list.size - 1; i > idx - 1; i--) {
        list.data[i + 1] = list.data[i];
    }
    list.data[idx] = elem;
    list.size++;
    return OK;
}
Status StaticSeqList_delete(StaticSeqList& list, int idx, ElemType& elem) {
    if (idx < 0 || idx > list.size - 1) return ERROR;
    elem = list.data[idx];

    for (int i = idx; i < list.size - 1; i++)
        list.data[i] = list.data[i + 1];
    list.size--;
    return OK;
}
//1.a 在非递减有序的顺序表中插入一个元素 x，保持顺序表有序性(不使用基本操作）;
Status StaticSeqList_OrderInsert_unuse(StaticSeqList& list, ElemType x)
{
    if (list.size == list.capacity)return ERROR;
    int i = list.size - 1;
    while (i >= 0 && list.data[i] >= x)
    {
        list.data[i + 1] = list.data[i];
        i--;
    }
    list.data[i + 1] = x;
    list.size++;
    return OK;
}
//1.b 在非递减有序的顺序表中插入一个元素 x，保持顺序表有序性(使用基本操作）;
Status StaticSeqList_OrderInsert_use(StaticSeqList& list, ElemType x) {
    if (list.size == list.capacity)return ERROR;
    int i = 0;
    while (i < list.size && x >= list.data[i]) {
        i++;
    }
    StaticSeqList_insert(list, i, x);
    return OK;
}
//2.顺序表元素的逆置;
Status StaticSeqList_Reverse(StaticSeqList& list) {
    if (list.size == 0)return ERROR;
    ElemType t[INIT_SIZE];
    if (!t)return ERROR;
    for (int i = 0; i < list.size; i++)
        t[i] = list.data[i];
    for (int i = 0; i < list.size; i++)
        list.data[i] = t[list.size - i - 1];
    return OK;
}
//两个（有序或无序）顺序表的合并
Status StaticSeqList_Combine(StaticSeqList list1, StaticSeqList list2, StaticSeqList& L) {
    if (list1.size + list2.size > L.capacity)return ERROR;
    L.size = 0;
    int i = 0, j = 0, k = 0;
    while (i < list1.size && j < list2.size) {
        if (list1.data[i] > list2.data[j]) {
            L.data[k] = list2.data[j];
            k++; j++; L.size++;
        }
        else if (list1.data[i] < list2.data[j]) {
            L.data[k] = list1.data[i];
            k++; i++; L.size++;
        }
        else if (list1.data[i] == list2.data[j]) {
            L.data[k] = list1.data[i];
            k++; i++; j++; L.size++;
        }
    }
    for (; i < list1.size; k++, i++, L.size++)
        L.data[k] = list1.data[i];
    for (; j < list2.size; k++, j++, L.size++)
        L.data[k] = list2.data[j];
    return OK;
}
