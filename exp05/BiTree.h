#pragma once
#ifndef __SEQ_LIST_HEADER__
#define __SEQ_LIST_HEADER__
typedef char TElemType;
//typedef BiTree SElemType;

//二叉树
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

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