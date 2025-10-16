#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
using namespace std;
#define OK 1
#define ERROR -1
#define INFINITY INT_MAX
#define MAXSIZE 20
#define true 1
#define false 0
typedef enum { DG, UDG, DN, UDN } GraphType;
typedef char VertexType;
typedef int Status;
typedef int Boolen;
Boolen visited[MAXSIZE];
typedef struct {
	int vexnum, arcnum;
	int arc[MAXSIZE][MAXSIZE];
	VertexType vexs[MAXSIZE];
	GraphType type;
}MGraph;

//找到顶点v在图中的位置
int Locatevex(char v, MGraph& G) {
	for (int i = 1; i <= G.vexnum; i++)
		if (v == G.vexs[i])return i;
	return -1;
}
//创建图
void CreateGraph(MGraph& G) {
	cout << "请输入图的类型(0.有向图；1.无向图；2.有向网；3.无向网):";
	int t, v1, v2;
	char c1, c2;
	cin >> t;
	if (t == DG)G.type = DG;
	else if (t == UDG)G.type = UDG;
	else if (t == DN)G.type = DN;
	else if (t == UDN)G.type = UDN;
	cout << endl << "请输入图的顶点数和弧数（空格间隔）:";
	cin >> G.vexnum >> G.arcnum;
	cout << "请输入" << G.vexnum << "个顶点的信息:";
	for (int i = 1; i <= G.vexnum; i++)
		cin >> G.vexs[i];
	if (G.type == DG || G.type == UDG) {
		for (int i = 1; i <= G.vexnum; i++)
			for (int j = 1; j <= G.vexnum; j++)
				G.arc[i][j] = 0;
	}
	else if (G.type == DN || G.type == UDN) {
		for (int i = 1; i <= G.vexnum; i++)
			for (int j = 1; j <= G.vexnum; j++)
				G.arc[i][j] = INFINITY;
	}
	for (int i = 1; i <= G.arcnum; i++) {
		cout << "请输入各条弧的两个结点v1,v2(空格间隔)：";
		cin >> c1 >> c2;
		v1 = Locatevex(c1, G);
		v2 = Locatevex(c2, G);
		if (G.type == DG)G.arc[v1][v2] = 1;
		else if (G.type == UDG)G.arc[v1][v2] = G.arc[v2][v1] = 1;
		else if (G.type == DN) {
			cout << "请输入该边的权值：";
			int weight;
			cin >> weight;
			G.arc[v1][v2] = weight;
		}
		else if (G.type == UDN) {
			cout << "请输入该边的权值：";
			int weight;
			cin >> weight;
			G.arc[v1][v2] = weight;
			G.arc[v2][v1] = weight;
		}
	}
}
//打印图
void print(MGraph G) {
	if (G.type == DG)cout << "图的类型:有向图" << endl;
	else if (G.type == UDG)cout << "图的类型:无向图" << endl;
	else if (G.type == DN)cout << "图的类型:有向网" << endl;
	else if (G.type == UDN)cout << "图的类型:无向网" << endl;
	cout << "图的顶点数目：" << G.vexnum << endl;
	cout << "图的弧的数目：" << G.arcnum << endl;
	cout << "图的顶点集合：";
	for (int i = 1; i <= G.vexnum; i++)cout << G.vexs[i] << " ";
	cout << endl << "图的邻接矩阵：" << endl;
	int flag = 1;
	for (int i = 1; i <= G.vexnum; i++) {
		for (int j = 1; j <= G.vexnum; j++) {
			if (flag) { flag = 0; cout << G.arc[i][j]; }
			else { cout << setw(4) << G.arc[i][j] << " "; }
		}
		flag = 1;
		cout << endl;
	}
}
//在图中插入一个新结点
Status InsertVex(MGraph& G, char v) {
	if (G.vexnum + 1 > MAXSIZE)return ERROR;
	G.vexs[G.vexnum + 1] = v;
	if (G.type == DG || G.type == UDG) {
		for (int i = 1; i <= G.vexnum + 1; i++)
			G.arc[i][G.vexnum + 1] = G.arc[G.vexnum + 1][i] = 0;
	}
	else if (G.type == DN || G.type == UDN) {
		for (int i = 1; i <= G.vexnum + 1; i++)
			G.arc[i][G.vexnum + 1] = G.arc[G.vexnum + 1][i] = INFINITY;
	}
	G.vexnum++;
	return OK;
}
//在图中插入一条弧
Status InsertArc(MGraph& G, char v, char w) {
	int k1 = Locatevex(v, G);
	int k2 = Locatevex(w, G);
	if (k1 < 0 || k2 < 0)return ERROR;
	if (G.type == DG)G.arc[k1][k2] = 1;
	if (G.type == UDG)G.arc[k1][k2] = G.arc[k2][k1] = 1;
	if (G.type == DN) {
		int weight;
		cout << "请输入该边的权值:";
		cin >> weight;
		G.arc[k1][k2] = weight;
	}
	if (G.type == UDN) {
		int weight;
		cout << "请输入该边的权值:";
		cin >> weight;
		G.arc[k1][k2] = G.arc[k2][k1] = weight;
	}
	G.arcnum++;
	return OK;
}
//在图中删除一个结点
Status DeleteVex(MGraph& G, char v) {
	int k = Locatevex(v, G);
	if (k == -1)return ERROR;
	for (int i = 1; i <= G.vexnum; i++)
		if (G.arc[k][i])G.arcnum--;
	for (int i = 1; i <= G.vexnum; i++)
		if (G.arc[i][k])G.arcnum--;
	for (int i = k; i <= G.vexnum - 1; i++)
		G.vexs[i] = G.vexs[i + 1];
	for (int i = 1; i <= G.vexnum; i++)
		for (int j = k; j <= G.vexnum - 1; j++)
			G.arc[i][j] = G.arc[i][j + 1];
	for (int i = k; i <= G.vexnum - 1; i++)
		for (int j = 1; j <= G.vexnum; j++)
			G.arc[i][j] = G.arc[i + 1][j];
	G.vexnum--;
	return OK;
}
//在图中删除一条边
Status DeleteArc(MGraph& G, char v, char w) {
	int k1 = Locatevex(v, G);
	int k2 = Locatevex(w, G);
	if (k1 < 0 || k2 < 0)return ERROR;
	if (G.type == DG)G.arc[k1][k2] = 0;
	else if (G.type == UDG)G.arc[k2][k1] = G.arc[k1][k2] = 0;
	else if (G.type == DN)G.arc[k1][k2] = INFINITY;
	else if (G.type == UDN)G.arc[k1][k2] = G.arc[k2][k1] = INFINITY;
	G.arcnum--;
	return OK;
}
//图的深度优先遍历
void DFS(MGraph G, int i) {
	int j;
	visited[i] = true;
	cout << G.vexs[i] << "->";
	for (j = 1; j <= G.vexnum; j++) {
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G, j);
	}
}
void DFSTraverse(MGraph G) {
	int i;
	for (i = 1; i <= G.vexnum; i++)
		visited[i] = false;
	for (i = 1; i <= G.vexnum; i++)
		if (!visited[i])
			DFS(G, i);
}
int main() {
	MGraph G;
	cout << "---------图的基本操作测试----------" << endl;
	CreateGraph(G);
	print(G);
	char v, w;
	cout << "请输入要插入的顶点信息：";
	cin >> v;
	InsertVex(G, v);
	print(G);
	cout << "请输入要删除的顶点信息：";
	cin >> v;
	DeleteVex(G, v);
	print(G);
	cout << "请输入要插入弧的弧尾顶点和弧头顶点(空格间隔)：";
	cin >> v >> w;
	InsertArc(G, v, w);
	print(G);
	cout << "请输入要删除弧的弧尾顶点和弧头顶点(空格间隔)：";
	cin >> v >> w;
	DeleteArc(G, v, w);
	print(G);
	cout << "----------图的深度优先遍历测试----------" << endl;
	DFSTraverse(G);
	return 0;
}