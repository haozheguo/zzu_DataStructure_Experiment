#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define maxsize 20
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
typedef int keytype;
typedef struct {
	keytype key;
}redtype;
typedef struct {
	redtype r[maxsize + 1];
	int length;
}SqList;
//9-1 插入类排序--直接插入排序
void InsertSort(SqList& L) {
	int i, j;
	for (i = 2; i <= L.length; i++) {
		if (LT(L.r[i].key, L.r[i - 1].key)) {
			L.r[0] = L.r[i];
			for (j = i - 1; LT(L.r[0].key, L.r[j].key); j--)
				L.r[j + 1] = L.r[j];
			L.r[j + 1] = L.r[0];
		}
	}
}
//9-2 插入类排序--希尔排序
void ShellInsert(SqList& L, int dk) {
	int i, j;
	for (i = dk + 1; i <= L.length; i++) {
		if (LT(L.r[i].key, L.r[i - dk].key)) {
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && LT(L.r[0].key, L.r[j].key); j -= dk)
				L.r[j + dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}
	}
}
void ShellSort(SqList& L, int dlta[], int t) {
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(L, dlta[k]);
}
//9-3 交换类排序--冒泡排序
void BubbleSort(SqList& L) {
	int i, j, exchange = 1;
	redtype tmp;
	for (i = 1; i <= L.length - 1 && exchange; i++) {
		exchange = 0;
		for (j = 1; j <= L.length - i; j++) {
			if (LT(L.r[j + 1].key, L.r[j].key)) {
				tmp = L.r[j + 1]; L.r[j + 1] = L.r[j]; L.r[j] = tmp;
				exchange = 1;
			}
		}
	}
}
//9-4 交换类排序-快速排序
int Partition(SqList& L, int low, int high) {
	keytype pivotkey;
	L.r[0] = L.r[low];
	pivotkey = L.r[low].key;
	while (low < high) {
		while (low < high && L.r[high].key >= pivotkey)high--;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= pivotkey)low++;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}
void Qsort(SqList& L, int low, int high) {
	int pivotloc;
	if (low < high) {
		pivotloc = Partition(L, low, high);
		Qsort(L, low, pivotloc - 1);
		Qsort(L, pivotloc + 1, high);
	}
}
//9-5 选择类排序-简单选择排序
void SelectSort(SqList& L) {
	int i, j, k;
	redtype tmp;
	for (i = 1; i <= L.length - 1; i++) {
		k = i;
		for (j = i; j <= L.length; j++) {
			if (LT(L.r[j].key, L.r[k].key))
				k = j;
		}
		if (k != i) {
			tmp = L.r[i]; L.r[i] = L.r[k]; L.r[k] = tmp;
		}
	}
}
//9-6 选择类排序-堆排序
void HeapAdjust(SqList& L, int s, int m) {
	int j;
	redtype rc = L.r[s];
	for (j = 2 * s; j <= m; j *= 2) {
		if (j < m&& LT(L.r[j].key, L.r[j + 1].key)) ++j;
		if (!LT(rc.key, L.r[j].key))break;
		L.r[s] = L.r[j]; s = j;
	}
	L.r[s] = rc;
}
void HeapSort(SqList& L) {
	int i;
	redtype tmp;
	for (i = L.length / 2; i > 0; i--)
		HeapAdjust(L, i, L.length);
	for (i = L.length; i > 1; i--) {
		tmp = L.r[1]; L.r[1] = L.r[i]; L.r[i] = tmp;
		HeapAdjust(L, 1, i - 1);
	}
}
//9-7 递归形式的归并排序
void Merge(redtype SR[], redtype TR[], int i, int m, int n) {
	int  j, k;
	for (j = m + 1, k = i; i <= m && j <= n; k++) {
		if (LQ(SR[i].key, SR[j].key))TR[k] = SR[i++];
		else TR[k] = SR[j++];
	}
	if (i <= m) {
		for (; i <= m; i++, k++)
			TR[k] = SR[i];
	}
	if (j <= n) {
		for (; j <= n; j++, k++)
			TR[k] = SR[j];
	}
}
void MSort(redtype SR[], redtype TR[], int s, int t) {
	int m;
	redtype TR1[maxsize + 1];
	if (s == t)TR[s] = SR[s];
	else {
		m = (s + t) / 2;
		MSort(SR, TR1, s, m);
		MSort(SR, TR1, m + 1, t);
		Merge(TR1, TR, s, m, t);
	}
}
int main() {
	SqList L;
	int i;
	cout << "请输入关键字序列长度：";
	cin >> L.length;
	cout << "请输入关键字序列：";
	for (i = 1; i <= L.length; i++)
		cin >> L.r[i].key;
	InsertSort(L);
	cout << "插入类排序->直接插入排序测试：";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl << endl;
	cout << "请输入关键字序列长度：";
	cin >> L.length;
	cout << "请输入关键字序列：";
	for (i = 1; i <= L.length; i++)
		cin >> L.r[i].key;
	int dlta[3] = { 5,3,1 };
	ShellSort(L, dlta, 3);
	cout << "插入类排序->希尔排序测试：";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl << endl;
	cout << "请输入关键字序列长度：";
	cin >> L.length;
	cout << "请输入关键字序列：";
	for (i = 1; i <= L.length; i++)
		cin >> L.r[i].key;
	BubbleSort(L);
	cout << "交换类排序->冒泡排序测试：";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl << endl;
	cout << "请输入关键字序列长度：";
	cin >> L.length;
	cout << "请输入关键字序列：";
	for (i = 1; i <= L.length; i++)
		cin >> L.r[i].key;
	Qsort(L, 1, L.length);
	cout << "交换类排序->快速排序测试：";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl << endl;
	cout << "请输入关键字序列长度：";
	cin >> L.length;
	cout << "请输入关键字序列：";
	for (i = 1; i <= L.length; i++)
		cin >> L.r[i].key;
	SelectSort(L);
	cout << "选择类排序->简单选择排序测试：";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl << endl;
	cout << "请输入关键字序列长度：";
	cin >> L.length;
	cout << "请输入关键字序列：";
	for (i = 1; i <= L.length; i++)
		cin >> L.r[i].key;
	HeapSort(L);
	cout << "选择类排序->堆排序测试：";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl << endl;
	cout << "请输入关键字序列长度：";
	cin >> L.length;
	cout << "请输入关键字序列：";
	for (i = 1; i <= L.length; i++)
		cin >> L.r[i].key;
	MSort(L.r, L.r, 1, L.length);
	cout << "递归形式的归并排序测试：";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl << endl;
	return 0;
}