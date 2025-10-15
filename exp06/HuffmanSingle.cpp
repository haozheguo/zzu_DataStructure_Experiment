#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define FILEA "A.txt"
#define FILEB "B.txt"
#define FILEC "C.txt"

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

//1.输入一段 100—200 字的英文短文，存入一文件 a 中
Status FileAInput() {
	ofstream ofs;
	ofs.open(FILEA, ios::trunc);
	if (!ofs.is_open()) {
		cout << "FileA不能成功打开！" << endl;
		return ERROR;
	}
	char ch;
	cout << "请输入200字左右的英文短文并以#结尾：" << endl;
	cin >> ch;
	while (ch != '#') {
		ofs << ch;
		cin >> ch;
	}
	ofs.close();
	return OK;
}
//2.写函数统计短文出现的字母个数 n 及每个字母的出现次数
Status FileAStatistic(Alphabet A[]) {
	ifstream ifs;
	char c;
	int i, m, countsum = 0, n = 0;
	for (i = 1; i <= 26; i++) {//英文字母数组初始化
		A[i].data = i + 97 - 1;
		A[i].count = 0;
	}
	ifs.open(FILEA, ios::in);
	if (!ifs.is_open()) {
		cout << "fileA不能打开！" << endl;
		return ERROR;
	}
	while (ifs >> c) {
		m = (int)c;
		countsum++;
		if (m >= 65 && m <= 90)A[m - 65 + 1].count++;
		else if (m >= 97 && m <= 122)A[m - 97 + 1].count++;
		else continue;
		n++;
	}
	cout << "总字符数为：" << countsum << ";" << "英文字符数为：" << n << endl;
	ifs.close();
	return OK;
}
//3.写函数以字母出现次数作权值，建 Huffman 树（n 个叶子），给出每个字母的Huffman 编码
Status CreateHuffman(HuffmanTree& HT, HuffmanCode& HC, Alphabet A[], int n)//HT为创建的哈夫曼树，A[]为权重统计，n为结点数 
{
	if (n <= 1)return ERROR;
	int m = 2 * n - 1, i, s1, s2;
	HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));//0号单元弃用,HT[m]表示根结点
	for (i = 1; i <= m; i++) {
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}
	for (i = 1; i <= n; i++) {
		HT[i].weight = A[i].count;
		HT[i].info = A[i].data;
	}
	//哈夫曼树结点的合并过程（select函数进行两个权重最小结点下标的返回）
	for (i = n + 1; i <= m; i++) {
		Select(HT, i, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;//相当于从哈夫曼树中删除s1,s2结点
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].info = '0';
	}
	char* cd;
	int start, c, f;
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));//分配n个字符编码的头指针矢量，0号单元弃用
	cd = (char*)malloc(n * sizeof(char));//分配临时存放编码的动态数组空间
	cd[n - 1] = '\0';
	for (i = 1; i <= n; i++) {
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0) {    //从叶子结点开始向上回溯，直到根结点
			start--;        //回溯一次start向前指一个位置
			if (HT[f].lchild == c)cd[start] = '0';//结点c是f的左孩子，则生成代码0；
			else cd[start] = '1';   //结点c是f的右孩子，则生成代码1
			c = f;
			f = HT[f].parent;       //继续向上回溯
		}     //求出第i个字符的编码
		HC[i] = (char*)malloc(sizeof(char) * (n - start)); //为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]);    //将求得的编码从临时空间cd复制到HC当前行中
	}
	free(cd);
	return OK;
}
//4.用每个字母编码对原短文进行编码，码文存入文件 b 中
Status FileBInput(HuffmanCode HC) {
	ifstream ifs;
	ofstream ofs;
	char* ch;
	char c;
	int n;
	ifs.open(FILEA, ios::in);
	ofs.open(FILEB, ios::trunc);
	if (!ifs.is_open()) {
		cout << "FileA打开失败！" << endl;
		return ERROR;
	}
	if (!ofs.is_open()) {
		cout << "FileB打开失败！" << endl;
		return ERROR;
	}
	while (ifs >> c) {
		n = (int)c;
		if (n >= 65 && n <= 90) {
			ch = HC[n - 65 + 1];
			ofs << ch;
		}
		else if (n >= 97 && n <= 122) {
			ch = HC[n - 97 + 1];
			ofs << ch;
		}
		else
			continue;
	}
	ifs.close();
	ofs.close();
	return OK;
}
//5.用 Huffman 树对文件 b 中码文进行译码，结果存入文件 c 中，比较 a,c 是否一致，以检验编码、译码的正确性。
Status TranslateC(HuffmanTree HT) {
	ifstream ifs;
	ofstream ofs;
	char c;
	int i = 51;//从2*n-1的根结点开始遍历哈夫曼树
	ifs.open(FILEB, ios::in);
	ofs.open(FILEC, ios::trunc);
	if (!ifs.is_open()) {
		cout << "FileB打开失败！" << endl;
		return ERROR;
	}
	if (!ofs.is_open()) {
		cout << "FileC打开失败！" << endl;
		return ERROR;
	}
	while (ifs >> c) {
		if (c == '0')i = HT[i].lchild;
		else if (c == '1')i = HT[i].rchild;
		if (HT[i].lchild == 0 && HT[i].rchild == 0) {
			ofs << HT[i].info;
			cout << HT[i].info;
			i = 51;//注意找到叶子结点后要回溯到根结点
		}
	}
	ifs.close();
	ofs.close();
	return OK;
}
//辅助函数进行两个权重最小结点下标的返回
//在HT中选择两个其双亲域为0，并且权值最小的结点，并返回他们在HT中的序号。
Status Select(HuffmanTree HT, int x, int& s1, int& s2) {
	s1 = Min_index(HT, x - 1);
	s2 = Min_index(HT, x - 1);
	return OK;
}
//辅助函数实现返回双亲为0且权值最小的结点索引
int Min_index(HuffmanTree& HT, int k) {
	int i, min;
	int minweight = 32767;
	for (i = 1; i <= k; i++) {
		if (HT[i].parent == 0 && HT[i].weight < minweight) {
			min = i;
			minweight = HT[i].weight;
		}
	}
	HT[min].parent = k + 1;
	//cout << endl << "min=" << min << " k=" << k << " parent=" << HT[min].parent << endl;
	return min;
}
