/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : tree.cpp
 *     FIRST CREATION DATE    : 2020/09/30
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/30
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>
#include "tree.h"

using namespace std;

//前序遍历
void preorder(BTNode *p)
{
	if (p != NULL) {
		cout << p->data << endl;
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

//中序遍历
void inorder(BTNode *p)
{
	if (p != NULL) {
		preorder(p->lchild);
		cout << p->data << endl;
		preorder(p->rchild);
	}
}

//后序遍历
void postorder(BTNode *p)
{
	if (p != NULL) {
		preorder(p->lchild);
		preorder(p->rchild);
		cout << p->data << endl;
	}
}

//层次遍历
void level(BTNode *p)
{
	int front, rear;
	BTNode *que[maxSize];
	front = rear = 0;
	BTNode *q;

	if (p != NULL) {
		rear = (rear+1)%maxSize;
		que[rear] = p;
		while (front != rear) {
			front = (front+1)%maxSize;
			q = que[front];
			cout << q->data << endl;
			if (q->lchild != NULL) {
				rear = (rear+1)%maxSize;
				que[rear] = q->lchild;
			}
			if (q->rchild != NULL) {
				rear = (rear+1)%maxSize;
				que[rear] = q->rchild;
			}
		}
	}
}

//前序非递归遍历
void preorderNonrecursion(BTNode *bt)
{
	if (bt != NULL) {
		BTNode *Stack[maxSize];
		int top = -1;
		BTNode *p;

		Stack[++top] = bt;

		while (top != -1) {
			p = Stack[top--];
			cout << p->data << endl;
			if (p->rchild != NULL) {
				Stack[++top] = p->rchild;
			}
			if (p->lchild != NULL) {
				Stack[++top] = p->lchild;
			}
		}
	}
}

//中序非递归遍历
void inorderNonrecursion(BTNode *bt)
{
	if (bt != NULL) {
		BTNode *Stack[maxSize];
		int top = -1;
		BTNode *p;
		p = bt;

		while (top != -1 || p != NULL) {
			while (p != NULL) {
				Stack[++top] = p;
				p = p->lchild;
			}
			if (top != -1) {
				p = Stack[top--];
				cout << p->data << endl;
				p = p->rchild;
			}
		}
	}
}

//后序非递归遍历
void postorderNonrecursion(BTNode *bt)
{
	if (bt != NULL) {
		BTNode *Stack1[maxSize];
		int top1 = -1;
		BTNode *Stack2[maxSize];
		int top2 = -1;
		BTNode *p = NULL;

		Stack1[++top1] = bt;
		while (top1 != -1) {
			p = Stack1[top1--];
			Stack2[++top2] = p;
			if (p->lchild != NULL) {
				Stack1[++top1] = p->lchild;
			}
			if (p->rchild != NULL) {
				Stack1[++top1] = p->rchild;
			}
		}
		//出栈序列则为后序遍历
		while (top2 != -1) {
			p = Stack2[top2--];
			cout << p->data << endl;
		}
	}
}

//通过中序遍历线索化二叉树
void InThread(TBTNode *p, TBTNode *&pre)
{
	if (p != NULL) {
		//递归，左子树线索化
		InThread(p->lchild, pre);
		//建立当前结点的前驱线索
		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}
		//建立当前结点的后驱线索
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		p = p->rchild;
		//递归，右子树线索化
		InThread(p, pre);
	}
}

//通过中序遍历建立中序线索二叉树
void createInThread(TBTNode *root)
{
	TBTNode *pre = NULL;
	if (root != NULL) {
		InThread(root, pre);
		pre->rchild = NULL;
		pre->rtag = NULL;
	}
}

//中序下的第一个结点
TBTNode *First(TBTNode *p)
{
	while (p->ltag == 0) {
		p = p->lchild;
	}
	return p;
}

//中序下的下一个结点
TBTNode *Next(TBTNode *p)
{
	if (p->rtag == 0) {
		return First(p->rchild);
	} else {
		return p->rchild;
	}
}

//中序遍历中序线索二叉树
void Inorder(TBTNode *root)
{
	for (TBTNode *p=First(root); p!=NULL; p=Next(p)) {
		cout << p->data << endl;
	}
}

//前序线索二叉树
void preThread(TBTNode *p, TBTNode *&pre)
{
	if (p != NULL) {
		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild;
			pre->rtag = 1;
		}
		pre = p;
		if (p->ltag == 0) {
			preThread(p->lchild, pre);
		}
		if (p->rtag == 0) {
			preThread(p->rchild, pre);
		}
	}
}

//前序遍历前序线索二叉树
void preorder(TBTNode *root)
{
	if (root != NULL) {
		TBTNode *p = root;
		while (p != NULL) {
			while (p->ltag == 0) {
				cout << p->data << endl;
				p = p->lchild;
			}
			cout << p->data << endl;
			p = p->rchild;
		}
	}
}

//后序线索二叉树
void postThread(TBTNode *p, TBTNode *&pre)
{
	if (p != NULL) {
		postThread(p->lchild, pre);
		postThread(p->lchild, pre);
		//建立当前结点的前驱线索
		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}
		//前驱结点的后继线索
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
	}
}


