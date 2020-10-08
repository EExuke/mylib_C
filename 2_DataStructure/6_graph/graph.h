/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : graph.h
 *     FIRST CREATION DATE    : 2020/10/07
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/07
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>

/*------------------Macro Definition-------------------------*/
#define maxSize    10
#define INF        4096
/*------------------End of Macro Definition------------------*/
//顶点类型
typedef struct {
	int no;
	char info;
}VertexType;

//图的定义(邻接矩阵)
typedef struct {
	int edges[maxSize][maxSize];
	int n, e;                   //顶点数和边数
	VertexType vex[maxSize];    //存放结点信息
}MGraph;

//邻接表表示
typedef struct ArcNode {
	int adjvex;              //该边所指向的结点的值
	struct ArcNode *nextarc; //指向下一条边的指针
	int info;
}ArcNode;
typedef struct {
	char data;        //顶点信息
	ArcNode *firstarc; //指向第一条边的指针
}VNode;
typedef struct {
	VNode adjlist[maxSize];    //邻接表
	int n, e;    //定点数和边数
}AGraph;

int visit[maxSize];    //访问标记

//for 克鲁斯卡尔算法
typedef struct {
	int a, b;    //a和b为一条边所连的两个顶点
	int w;    //边的权值
}Road;
Road road[maxSize];
int v[maxSize];    //定义并查集数组
/*------------------API Definition---------------------------*/
//图的遍历
void DFS(AGraph *G, int v);
void BFS(AGraph *G, int v, int visit[maxSize]);

//最小(代价)生成树
void Prim(MGraph g, int v0, int &sum);
void Kruskal(MGraph g, int &sum, Road road[]);

//最短路径
void printfPath(int path[], int a);
void Dijkstra(MGraph g, int v, int dist[], int path[]);
void printfPath(int u, int v, int path[][maxSize]);
void Floyd(MGraph g, int Path[][maxSize]);
/*------------------End of API Definition--------------------*/

#endif /* End of _GRAPH_H_ */

