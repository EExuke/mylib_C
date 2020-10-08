/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : graph.cpp
 *     FIRST CREATION DATE    : 2020/10/07
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/07
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>
#include "graph.h"

using namespace std;

//深度优先搜索遍历DFS
void DFS(AGraph *G, int v)
{
	ArcNode *p;
	visit[v] = 1;    //访问标记
	cout << v << endl;    //访问
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (visit[p->adjvex] == 0) {
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}

//广度优先搜索遍历BFS
void BFS(AGraph *G, int v, int visit[maxSize])
{
	ArcNode *p;
	int que[maxSize], front = 0, rear = 0;    //队列
	int j;
	cout << v << endl;
	visit[v] = 1;
	rear = (rear+1)%maxSize;
	que[rear] = v;
	while (front != rear) {
		front = (front+1)%maxSize;
		j = que[front];
		p = G->adjlist[j].firstarc;
		while (p != NULL) {
			if (visit[p->adjvex] == 0) {
				cout << p->adjvex << endl;
				visit[p->adjvex] = 1;
				rear = (rear+1)%maxSize;    //进队
				que[rear] = p->adjvex;
			}
			p = p->nextarc;    //p指向j的下一条边
		}
	}
}

//普里姆算法
void Prim(MGraph g, int v0, int &sum)
{
	int lowcost[maxSize], vset[maxSize], v;
	int i, j, k, min;
	v = v0;
	for (i=0; i<g.n; i++) {
		lowcost[i] = g.edges[v0][i];
		vset[i] = 0;
	}
	vset[v0] = 1;
	sum = 0;
	for (i=0; i<g.n-1; i++) {
		min = INF;
		//选出候选边中的最小者
		for (j=0; j<g.n; j++) {
			if (vset[j] == 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
		}
		vset[k] = 1;
		v = k;
		sum += min;
		//更新候选边
		for (j=0; j<g.n; j++) {
			if (vset[j]==0 && g.edges[v][j] < lowcost[j]) {
				lowcost[j] = g.edges[v][j];
			}
		}
	}
}

//克鲁斯卡尔算法
int getRoot(int a)    //在并查集中查找根结点的函数
{
	while (a != v[a]) {
		a = v[a];
	}
	return a;
}
void Kruskal(MGraph g, int &sum, Road road[])
{
	int i;
	int N, E, a, b;
	N = g.n;
	E = g.e;
	sum = 0;
	for (i=0; i<N; i++) {
		v[i] = i;
	}
	//sort(road, E);    //排序
	for (i=0; i<E; i++) {
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b) {
			v[a] = b;
			sum += road[i].w;    //求生成树的权值
		}
	}
}

//最短路径算法
//打印路径
void printfPath(int path[], int a)
{
	int stack[maxSize], top=-1;
	//从叶子节点到根节点的顺序将其入栈
	while (path[a] != -1) {
		stack[++top] = a;
		a = path[a];
	}
	stack[++top] = a;
	while (top != -1) {
		cout << stack[top--] << " ";
	}
	cout << endl;
}

//迪杰斯特拉
void Dijkstra(MGraph g, int v, int dist[], int path[])
{
	int set[maxSize];
	int min, i, j, u;
	//初始化
	for (i=0; i<g.n; i++) {
		dist[i] = g.edges[v][i];
		set[i] = 0;
		if (g.edges[v][i] < INF) {
			path[i] = v;
		} else {
			path[i] = -1;
		}
	}
	set[v] = 1;
	path[v] = -1;

	for (i=0; i<g.n; i++) {
		min = INF;
		for (j=0; j<g.n; j++) {
			if (set[j]==0 && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		set[u] = 1;    //将选出的顶点并入最短路径中
		for (j=0; j<g.n; j++) {
			//判断顶点u的加入是否会出现通往顶点j的更短的路径
			if (set[j]==0 && dist[u]+g.edges[u][j] < dist[j]) {
				dist[j] = dist[u]+g.edges[u][j];
				path[j] = u;
			}
		}
	}
	//结束后dist[]数组中存放了v点到其余顶点的最短路径长度
	//path[]中存放v点到各顶点的最短路径
}

//打印Floyd路径
void printfPath(int u, int v, int path[][maxSize])
{
	if (path[u][v] = -1) {
		cout << path[u][v];
	} else {
		int mid = path[u][v];
		printfPath(u, mid, path);    //mid前半段路径
		printfPath(mid, v, path);    //mid后半段路径
	}
}

//弗洛伊德算法
void Floyd(MGraph g, int Path[][maxSize])
{
	int i, j, k;
	int A[maxSize][maxSize];
	//双循环初始化数组
	for (i=0; i<g.n; i++) {
		for (j=0; j<g.n; j++) {
			A[i][j] = g.edges[i][j];
			Path[i][j] = -1;
		}
	}
	//三循环主要操作
	for (k=0; k<g.n; k++) {
		for (i=0; i<g.n; i++) {
			for (j=0; j<g.n; j++) {
				if(A[i][j] > A[i][k]+A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
					Path[i][j] = k;
				}
			}
		}
	}
}



