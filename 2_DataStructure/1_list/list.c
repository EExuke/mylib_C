/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : list.c
 *     FIRST CREATION DATE    : 2020/09/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/25
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include "listStruct.h"

/***************************************************************************************
 * Function Name : findElem
 * Description   : find Element in L
 * @param [in ]  : L
 *               : e
 * @param [out]  : NULL
 * @return       : i
 ***************************************************************************************/
int findElem(Sqlist L, int e)
{
	int i;
	for (i=0; i<L.length; i++) {
		if(e == L.data[i])
			return i;
	}
	return -1;
}

/***************************************************************************************
 * Function Name : findElemSite
 * Description   : find site in L for element x
 * @param [in ]  : L
 *               : x
 * @param [out]  : NULL
 * @return       : i
 ***************************************************************************************/
int findElemiSite(Sqlist L, int x)
{
	int i;
	for (i=0; i<L.length; i++) {
		if (x < L.data[i]) {
			return i;
		}
	}
	return i;
}

/***************************************************************************************
 * Function Name : insertElem
 * Description   : insert element x to L
 * @param [in ]  : L
 *               : p
 *               : e
 * @param [out]  : NULL
 * @return       : 1/0
 ***************************************************************************************/
int insertElem(Sqlist *L, int p, int e)
{
	int i;

	if (p < 0 || p > L->length || L->length == maxSize) {
		return 0;
	}
	
	for (i=L->length-1; i >= p; i--) {
		L->data[i+1] = L->data[i];
	}
	L->data[p] = e;

	++(L->length);

	return 1;
}

/***************************************************************************************
 * Function Name : deleteElem
 * Description   : delete element e from L
 * @param [in ]  : L
 *               : p
 *               : e
 * @param [out]  : NULL
 * @return       : 1/0
 ***************************************************************************************/
int deleteElem(Sqlist *L, int p, int *e)
{
	int i;

	if (p < 0 || p > L->length-1) {
		return 0;
	}

	e = L->data[p];
	for (i=p; i<L->length-1; i++) {
		L->data[i] = L->data[i+1];
	}
	--(L->length);
	return 1;
}

/***************************************************************************************
 * Function Name : initList
 * Description   : init list
 * @param [in ]  : L
 *               :
 * @param [out]  : NULL
 * @return       : NULL
 ***************************************************************************************/
void initList(Sqlist *L)
{
	L->length = 0;
}

/***************************************************************************************
 * Function Name : getElem
 * Description   : get e of p in L
 * @param [in ]  : L, p, e
 * @param [out]  : NULL
 * @return       : 1
 ***************************************************************************************/
int getElem(Sqlist L, int p, int *e)
{
	if (p < 0 || p > L.length-1) {
		return 0;
	}
	e = L.data[p];
	return 1;
}

/***************************************************************************************
 * Function Name : mergeLinkIncrease
 * Description   : merge link list A and B to C in up order
 * @param [in ]  : A, B
 * @param [out]  : C
 * @return       : NULL
 ***************************************************************************************/
void mergeLinkIncrease(LNode *A, LNode *B, LNode *C)
{
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *r;
	
	C = A;
	C->next = NULL;
	free(B);        //free head node of B
	r = C;
	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			r->next = p;
			p = p->next;
			r = r->next;
		} else {
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	r->next = NULL;

	if (p != NULL) {
		r->next = p;
	}
	if (q != NULL) {
		r->next = q;
	}
}

/***************************************************************************************
 * Function Name : createListR
 * Description   : tail insert
 * @param [in ]  : C, a[], n
 * @param [out]  : C
 * @return       : NULL
 ***************************************************************************************/
void createListR(LNode *C, int a[], int n)
{
	LNode *s, *r;
	int i;

	C = (LNode *)malloc(sizeof(LNode));    //head space of C
	C->next = NULL;

	r = C;    //tail point r
	for (i=0; i<n; i++) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;    //end node
}

/***************************************************************************************
 * Function Name : createListF
 * Description   : head insert
 * @param [in ]  : C, a[], n
 * @param [out]  : C
 * @return       : NULL
 ***************************************************************************************/
void createListF(LNode *C, int a[], int n)
{
	LNode *s;
	int i;

	C = (LNode *)malloc(sizeof(LNode));    //head space of C
	C->next = NULL;

	for (i=0; i<n; i++) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		s->next = C->next;
		C->next = s;
	}
}

/***************************************************************************************
 * Function Name : mergeLinkDecrease
 * Description   : merge A and B to C in decrease order
 * @param [in ]  : A, B, &C
 * @param [out]  : C
 * @return       : NULL
 ***************************************************************************************/
void mergeLinkDecrease(LNode *A, LNode *B, LNode *C)
{
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *s;

	C = A;
	C->next = NULL;
	free(B);    //free head node of B
	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
		} else {
			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}

	while (p != NULL) {
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL) {
		s = q;
		p = q->next;
		s->next = C->next;
		C->next = s;
	}
}

/***************************************************************************************
 * Function Name : findAndDelete
 * Description   : find x node in list C, and delete it
 * @param [in ]  : *C, x
 * @param [out]  : C
 * @return       : 0/1
 ***************************************************************************************/
int findAndDelete(LNode *C, int x)
{
	LNode *p, *q;
	p = C;

	//find
	while (p->next != NULL) {
		if (p->next->data == x) {
			break;
		}
		p = p->next;
	}
	
	if (p->next == NULL) {
		return 0;
	} else {
		//delete
		q = p->next;
		p->next = p->next->next;
		free(q);
		return 1;
	}
}

/***************************************************************************************
 * Function Name : createDListR
 * Description   : tail insert
 * @param [in ]  : &L, a[], n
 * @param [out]  : L
 * @return       : NULL
 ***************************************************************************************/
void createDListR(DLNode *L, int a[], int n)
{
	DLNode *s, *r;
	int i;

	L = (DLNode *)malloc(sizeof(DLNode));
	L->prior = NULL;
	L->next = NULL;
	r = L;    //tail point
	for (i=0; i<n; i++) {
		s = (DLNode *)malloc(sizeof(DLNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;    //end node
}






