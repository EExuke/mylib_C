/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : tree.h
 *     FIRST CREATION DATE    : 2020/09/30
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/30
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

/*------------------Macro Definition-------------------------*/
#define maxSize    100
/*------------------End of Macro Definition------------------*/
//顺序存储结构：数组表示，2*i为左child， 2*i+1为右child

//链式存储的二叉结点
typedef struct BTNode {
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

//线索二叉树
typedef struct TBTNode {
	char data;
	int ltag, rtag;    //线索标记
	struct TBTNode *lchild;
	struct TBTNode *rchild;
}TBTNode;

/*------------------API Definition---------------------------*/
void preorder(BTNode *p);
void inorder(BTNode *p);
void postorder(BTNode *p);
void level(BTNode *p);

void preorderNonrecursion(BTNode *bt);
void inorderNonrecursion(BTNode *bt);
void postorderNonrecursion(BTNode *bt);

void InThread(TBTNode *p, TBTNode *&pre);
void createInThread(TBTNode *root);
TBTNode *First(TBTNode *p);
TBTNode *Next(TBTNode *p);
void Inorder(TBTNode *root);

void preThread(TBTNode *p, TBTNode *&pre);
void preorder(TBTNode *root);

void postThread(TBTNode *p, TBTNode *&pre);
/*------------------End of API Definition--------------------*/

#endif /* End of _TREE_H_ */

