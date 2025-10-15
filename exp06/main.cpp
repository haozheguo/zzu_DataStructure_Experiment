#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
#include<fstream>
#include"Huffman.h"
using namespace std;
#define FILEA "A.txt"
#define FILEB "B.txt"
#define FILEC "C.txt"
int main()
{
	int n = 26, i;
	int m = 2 * n - 1;
	FileAInput();
	Alphabet A[27];
	FileAStatistic(A);
	for (int i = 1; i <= 26; i++) {
		cout << A[i].data << " " << A[i].count << " ";
		if (i % 13 == 0)cout << endl;
	}
	HuffmanTree HT;
	HuffmanCode HC;
	CreateHuffman(HT, HC, A, n);
	cout << "**********哈夫曼顺序存储数组**********" << endl;
	cout << "数组下标 " << setw(5) << " 哈夫曼编码" << setw(5) << "结点信息 " << setw(5) << "权重 "
		<< setw(5) << "双亲 " << setw(5) << "左孩子 " << setw(5) << "右孩子 " << setw(5) << endl;
	for (i = 1; i <= n; i++)
		cout << setw(8) << i << setw(12) << HC[i] << setw(8) << HT[i].info << setw(5) << HT[i].weight
		<< setw(5) << HT[i].parent << setw(5) << HT[i].lchild << setw(5) << HT[i].rchild << endl;
	for (i = n + 1; i <= m; i++)
		cout << setw(8) << i << setw(20) << HT[i].info << setw(5) << HT[i].weight << setw(5) <<
		HT[i].parent << setw(5) << HT[i].lchild << setw(5) << HT[i].rchild << endl;
	FileBInput(HC);
	cout << "初始英文短文如下：" << endl;
	ifstream ifs;
	ifs.open(FILEA, ios::in);
	if (!ifs.is_open()) {
		cout << "FileA打开失败！" << endl;
		return ERROR;
	}
	char c;
	while (ifs >> c)cout << c;
	cout << endl << "哈夫曼译码结果如下：" << endl;
	TranslateC(HT);
	return 0;
}