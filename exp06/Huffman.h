#pragma once
#ifndef __SEQ_LIST_HEADER__
#define __SEQ_LIST_HEADER__
/// Sequence List ADT and Impl.

//哈夫曼树
typedef struct {
	int weight;
	char info;//结点信息
	int parent, lchild, rchild;
}HTNode, * HuffmanTree;

//哈夫曼编码表
typedef char** HuffmanCode;//可变长度的字符串数组

//字母名称及其出现的次数
typedef struct {
	char data;
	int count;
}Alphabet;

#define INIT_SIZE 100
typedef int Status;
#define ERROR 1
#define OK 0
#define TRUE 1
#define FALSE 0
//#define NULL 0
#define OVERFLOW - 1
#define UNDERFLOW - 2

//1.输入一段 100—200 字的英文短文，存入一文件 a 中
Status FileAInput();
//2.写函数统计短文出现的字母个数 n 及每个字母的出现次数
Status FileAStatistic(Alphabet A[]);
//3.写函数以字母出现次数作权值，建 Huffman 树（n 个叶子），给出每个字母的Huffman 编码
Status CreateHuffman(HuffmanTree& HT, HuffmanCode& HC, Alphabet A[], int n);
//4.用每个字母编码对原短文进行编码，码文存入文件 b 中
Status FileBInput(HuffmanCode HC);
//5.用 Huffman 树对文件 b 中码文进行译码，结果存入文件 c 中，比较 a,c 是否一致，以检验编码、译码的正确性。
Status TranslateC(HuffmanTree HT);

//辅助函数进行两个权重最小结点下标的返回
//在HT中选择两个其双亲域为0，并且权值最小的结点，并返回他们在HT中的序号。
Status Select(HuffmanTree HT, int x, int& s1, int& s2);
//辅助函数实现返回双亲为0且权值最小的结点索引
int Min_index(HuffmanTree& HT, int k);
#endif
