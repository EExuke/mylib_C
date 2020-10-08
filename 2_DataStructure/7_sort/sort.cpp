/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : sort.cpp
 *     FIRST CREATION DATE    : 2020/10/07
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/07
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>

using namespace std;

//直接插入排序
void InsertSort(int R[], int n)
{
	int i, j;
	int temp;
	for (i=0; i<n; i++) {
		temp = R[i];
		j = i-1;
		while (j>=0 && temp<R[j]) {
			R[j+1] = R[j];
			--j;
		}
		R[j+1] = temp;
	}
}

//起泡排序
void BubblesSort(int R[], int n)
{
	int i, j, flag;
	int temp;
	for (i=n-1; i>=1; i--) {
		flag = 0;
		for (j=0; j<=i; j++) {
			if (R[j-1] > R[j]) {
				temp = R[j];
				R[j] = R[j-1];
				R[j-1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			return;
		}
	}
}

//快速排序
void QuickSort(int R[], int low, int high)
{
	int temp;
	int i=low, j=high;
	if (low < high) {
		temp = R[low];
		while (i < j) {
			while (j>i && R[j]>=temp) {
				--j;
			}
			if (i < j) {
				R[i] = R[j];
				++i;
			}
			while (i<j && R[i]<temp) {
				++i;
			}
			if (i < j) {
				R[j] = R[i];
				--j;
			}
		}
		R[i] = temp;
		QuickSort(R, low, i-1);
		QuickSort(R, i+1, high);
	}
}

//简单选择排序
void SelectSort(int R[], int n)
{
	int i, j, k;
	int temp;
	for (i=0; i<n; i++) {
		k = i;
		for (j=i+1; j<n; j++) {
			if (R[k] > R[j]) {
				k = j;
			}
		}
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
}

//调整
void Sift(int R[], int low, int high)
{
	int i=low, j=2*i;
	int temp = R[i];
	while (j <= high) {
		if (j<high && R[j]<R[j+1]) {
			++j;
		}
		if (temp < R[j]) {
			R[i] = R[j];
			i = j;
			j = 2*i;
		} else {
			break;
		}
	}
	R[i] = temp;
}

//堆排序
void heapSort(int R[], int n)
{
	int i;
	int temp;
	for (i=n/2; i>=1; i--) {
		Sift(R, i, n);
	}
	for (i=n; i>=2; i--) {
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift(R, 1, i-1);
	}
}

//二路归并排序
void mergeSort(int A[], int low, int high)
{
	if (low < high) {
		int mid = (low + high)/2;
		mergeSort(A, low, mid);
		mergeSort(A, mid+1, high);
		//merge(A, low, mid, high);    //把A数组中low到mid和mid+1到high内的两段有序序列归并成一段有序序列
	}
}

