// FileName: SeqList.cpp

#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"

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