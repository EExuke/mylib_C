/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : search.cpp
 *     FIRST CREATION DATE    : 2020/10/08
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/08
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>
#include "search.h"

using namespace std;

//顺序查找
int Search(int a[], int n, int k)
{
	int i;
	for (i=1; i<=n; i++) {
		if (a[i] == k) {
			return i;
		}
	}
	return 0;
}


//折半查找
int Bsearch(int R[], int low, int high, int k)
{
	int mid;
	while (low <= high) {
		mid = (low+high)/2;
		if (R[mid] == k) {
			return mid;
		} else if(R[mid] > k) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return 0;
}

