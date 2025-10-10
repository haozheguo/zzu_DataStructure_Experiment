// FileName: SeqList.h

#ifndef __SEQ_LIST_HEADER__
#define __SEQ_LIST_HEADER__
/// Sequence List ADT and Impl.
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