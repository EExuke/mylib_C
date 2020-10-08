/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : sort.h
 *     FIRST CREATION DATE    : 2020/10/07
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/07
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _SORT_H_
#define _SORT_H_

/*------------------Macro Definition-------------------------*/
/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
//直接插入排序
void InsertSort(int R[], int n);
//起泡排序
void BubblesSort(int R[], int n);
//快速排序
void QuickSort(int iR[], int low, int high);
//简单选择排序
void SelectSort(int R[], int n);
//堆排序
void Sift(int R[], int low, int high);
void heapSort(int R[], int n);
//二路归并排序
void mergeSort(int A[], int low, int high);

/*------------------End of API Definition--------------------*/

#endif /* End of _SORT_H_ */

