/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : string.h
 *     FIRST CREATION DATE    : 2020/09/30
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/30
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _STRING_H_
#define _STRING_H_

#include <stdio.h>
#include <stdlib.h>

/*------------------Macro Definition-------------------------*/
#define maxSize    100
/*------------------End of Macro Definition------------------*/
//定长顺序存储串
typedef struct {
	char str[maxSize];
	int length;
}Str;

//变长分配存储串
typedef struct {
	char *ch;
	int length;
}pStr;

/*------------------API Definition---------------------------*/
int strassign(pStr& str, char* ch);
int strcompare(pStr s1, pStr s2);
int concat(pStr& str, pStr str1, pStr str2);
int substring(pStr& substr, pStr str, int pos, int len);
int clearstring(pStr& str);
/*------------------End of API Definition--------------------*/

#endif /* End of _STRING_H_ */

