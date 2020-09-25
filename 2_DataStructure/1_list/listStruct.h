/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : listStruct.h
 *     FIRST CREATION DATE    : 2020/09/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/25
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _LISTSTRUCT_H_
#define _LISTSTRUCT_H_

#include <stdio.h>
#include <stdlib.h>

/*------------------Macro Definition-------------------------*/
#define maxSize    100
/*------------------End of Macro Definition------------------*/
//顺序表
typedef struct {
	int data[maxSize];
	int length;
}Sqlist;

//单链表
typedef struct LNode {
	int data;             //数据域
	struct LNode *next;   //指针域
}LNode;

//双链表
typedef struct DLNode {
	int data;
	struct DLNode *prior;
	struct DLNode *next;
}DLNode;

/*------------------API Definition---------------------------*/
int findElem(Sqlist L, int e);
int findElemSite(Sqlist L, int x);
int insertElem(Sqlist *L, int p, int e);
int deleteElem(Sqlist *L, int p, int *e);
void initList(Sqlist *L);
int getElem(Sqlist L, int p, int *e);

void mergeLinkIncrease(LNode *A, LNode *B, LNode *C);
void createListR(LNode *C, int a[], int n);
void createListF(LNode *C, int a[], int n);
void mergeLinkDecrease(LNode *A, LNode *B, LNode *C);
int findAndDelete(LNode *C, int x);
void createDListR(DLNode *L, int a[], int n);
/*------------------End of API Definition--------------------*/

#endif /* End of _LISTSTRUCT_H_ */














