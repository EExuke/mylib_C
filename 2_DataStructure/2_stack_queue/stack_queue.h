/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : stack_queue.h
 *     FIRST CREATION DATE    : 2020/09/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/25
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _STACK_QUEUE_H_
#define _STACK_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

/*------------------Macro Definition-------------------------*/
#define maxSize    100
/*------------------End of Macro Definition------------------*/
//顺序栈的定义
typedef struct {
	int data[maxSize];
	int top;
}SqStack;

//链栈结点定义
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode;

//顺序队列定义
typedef struct {
	int data[maxSize];
	int front;    //head point
	int rear;     //tail point
}SqQueue;

//链队结点类型定义
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode;

//链队类型定义
typedef struct {
	QNode *front;    //head
	QNode *rear;     //tail
}LiQueue;

/*------------------API Definition---------------------------*/
void initStack(SqStack &st);
int isEmpty(SqStack st);
int push(SqStack &st, int x);
int pop(SqStack &st, int &x);

void initStack(LNode *&lst);
int isEmpty(LNode *lst);
void push(LNode *lst, int x);
int pop(LNode *lst, int &x);

int match(char exp[], int n);

void initQueue(SqQueue &qu);
int isQueueEmpty(SqQueue qu);
int enQueue(SqQueue &qu, int x);
int deQueue(SqQueue &qu, int &x);

void initQueue(LiQueue *&lqu);
int isQueueEmpty(LiQueue *lqu);
int enQueue(LiQueue *lqu, int x);
int deQueue(LiQueue *lqu, int &x);
/*------------------End of API Definition--------------------*/

#endif /* End of _STACK_QUEUE_H_ */

