/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : array_matrix_GTable.cpp
 *     FIRST CREATION DATE    : 2020/09/30
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/30
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>
#include "array_matrix_GTable.h"

using namespace std;

//矩阵的转置
void trsmat(int A[][maxSize], int B[][maxSize], int m, int n)
{
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			B[j][i] = A[i][j];
		}
	}
}

//矩阵的相加
void addmat(int C[][maxSize], int A[][maxSize], int B[][maxSize], int m, int n)
{
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			C[i][j] =  A[i][j] + B[i][j];
		}
	}
}

//矩阵相乘 A:m*n, B:n*k
void mutmat(int C[][maxSize], int A[][maxSize], int B[][maxSize], int m, int n, int k)
{
	for (int i=0; i<m; i++) {
		for (int j=0; j<k; j++) {
			C[i][j] = 0;
			for (int h=0; h<n; h++) {
				C[i][j] += A[i][h] * B[h][j];
			}
		}
	}
}


