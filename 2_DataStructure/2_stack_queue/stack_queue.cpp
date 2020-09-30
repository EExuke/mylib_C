/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : stack_queue.cpp
 *     FIRST CREATION DATE    : 2020/09/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/25
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>
#include "stack_queue.h"

using namespace std;

//初始化栈
void initStack(SqStack &st)
{
	st.top = -1;
}

//判断栈空
int isEmpty(SqStack st)
{
	if (st.top == -1) {
		return 1;
	} else {
		return 0;
	}
}

//进栈
int push(SqStack &st, int x)
{
	if (st.top == maxSize-1) {
		return 0;
	}
	++(st.top);
	st.data[st.top] = x;
	return 1;
}

//出栈
int pop(SqStack &st, int &x)
{
	if (st.top == -1) {
		return 0;
	}
	x = st.data[st.top];
	--(st.top);
	return 1;
}

//链栈的初始化
void initStack(LNode *&lst)
{
	lst = (LNode *)malloc(sizeof(LNode));
	lst->next = NULL;
}

//判断栈空
int isEmpty(LNode *lst)
{
	if (lst->next == NULL) {
		return 1;
	} else {
		return 0;
	}
}

//进栈
void push(LNode *lst, int x)
{
	LNode *p;
	p = (LNode *)malloc(sizeof(LNode));
	p->next = NULL;
	p->data = x;

	p->next = lst->next;
	lst->next = p;
}

//出栈
int pop(LNode *lst, int &x)
{
	LNode *p;
	if (lst->next == NULL) {
		return 0;
	}

	p = lst->next;
	x = p->data;
	lst->next = p->next;
	free(p);
	return 1;
}

//应用栈，匹配括号
int match(char exp[], int n)
{
	char stack[maxSize];
	int top = -1;

	for (int i=0; i<n; i++) {
		if (exp[i] == '(') {
			stack[++top] = '(';
		}
		if (exp[i] == ')') {
			if (top == -1) {
				return 0;
			} else {
				--top;
			}
		}
	}

	if (top == -1) {
		return 1;
	} else {
		return 0;
	}
}

/*
 * 循环队列
 */
//初始化队列
void initQueue(SqQueue &qu)
{
	qu.front = qu.rear = 0;
}

//判断队空
int isQueueEmpty(SqQueue qu)
{
	if (qu.front == qu.rear) {
		return 1;
	} else {
		return 0;
	}
}

//进队算法
int enQueue(SqQueue &qu, int x)
{
	//队满判断
	if ((qu.rear+1)%maxSize == qu.front) {
		return 0;
	}
	qu.rear = (qu.rear+1)%maxSize;
	qu.data[qu.rear] = x;
	return 1;
}

//出队算法
int deQueue(SqQueue &qu, int &x)
{
	//队空判断
	if (qu.front == qu.rear) {
		return 0;
	}
	qu.front = (qu.front+1)%maxSize;
	x = qu.data[qu.front];
	return 1;
}

//初始化链队
void initQueue(LiQueue *&lqu)
{
	lqu = (LiQueue *)malloc(sizeof(LiQueue));
	lqu->front = lqu->rear = NULL;
}

//判断链队空
int isQueueEmpty(LiQueue *lqu)
{
	if (lqu->rear == NULL || lqu->front == NULL) {
		return 1;
	} else {
		return 0;
	}
}

//入链队
int enQueue(LiQueue *lqu, int x)
{
	QNode *p;
	p = (QNode *)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;

	if (lqu->rear == NULL) {
		lqu->front = lqu->rear = p;
	} else {
		lqu->rear->next = p;
		lqu->rear = p;
	}
}

//出链队
int deQueue(LiQueue *lqu, int &x)
{
	QNode *p;
	if (lqu->rear == NULL) {
		return 0;
	} else {
		p = lqu->front;
	}
	if (lqu->front == lqu->rear) {
		lqu->front = lqu->rear = NULL;
	} else {
		lqu->front = lqu->front->next;
	}

	x = p->data;
	free(p);
	return 1;
}


