/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : array_matrix_GTable.h
 *     FIRST CREATION DATE    : 2020/09/30
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/30
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _ARRAY_MATRIX_GTABLE_H_
#define _ARRAY_MATRIX_GTABLE_H_

#include <stdio.h>
#include <stdlib.h>

/*------------------Macro Definition-------------------------*/
#define maxSize    10
/*------------------End of Macro Definition------------------*/
/*
 * 稀疏矩阵
 */
//三元组表示法
typedef struct {
	int val;
	int i, j;
}Trimat;

//十字链表,普通结点
typedef struct OLNode {
	int row, col;
	struct OLNode *right, *down;
	float val;
}OLNode;

//十字链表,头结点
typedef struct {
	OLNode *rhead, *chead;
	int m, n, k;
}CrossList;

/*------------------API Definition---------------------------*/
void trsmat(int A[][maxSize], int B[][maxSize], int m, int n);
void addmat(int C[][maxSize], int A[][maxSize], int B[][maxSize], int m, int n);
void mutmat(int C[][maxSize], int A[][maxSize], int B[][maxSize], int m, int n, int k);
/*------------------End of API Definition--------------------*/

#endif /* End of _ARRAY_MATRIX_GTABLE_H_ */

