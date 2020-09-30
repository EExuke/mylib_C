/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : string.cpp
 *     FIRST CREATION DATE    : 2020/09/30
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/09/30
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <iostream>
#include "string.h"

using namespace std;

//赋值操作
int strassign(pStr& str, char* ch)
{
	if (str.ch) {
		free(str.ch);
	}
	int len = 0;
	char *c = ch;

	while (*c) {
		++len;
		++c;
	}

	if (len == 0) {
		str.ch = NULL;
		str.length = 0;
		return 1;
	} else {
		str.ch = (char *)malloc(sizeof(char) * (len+1));    //多1位存'\0'
		if (str.ch == NULL) {
			return 0;
		} else {
			c = ch;
			for (int i=0; i<=len; i++, c++) {    //连带'\0'一同复制
				str.ch[i] = *c;
			}
			str.length = len;
			return 1;
		}
	}
}

//串比较
int strcompare(pStr s1, pStr s2)
{
	for (int i=0; i<s1.length && i<s2.length; i++) {
		if (s1.ch[i] != s2.ch[i]) {
			return s1.ch[i] - s2.ch[i];
		}
	}
	return (s1.length - s2.length);
}

//串连接
int concat(pStr& str, pStr str1, pStr str2)
{
	if (str.ch) {
		free(str.ch);
		str.ch = NULL;
	}
	str.ch = (char*)malloc(sizeof(char) * (str1.length+str2.length+1));
	if (str.ch == NULL) {
		return 0;
	}

	int i = 0;
	while (i < str1.length) {
		str.ch[i] = str1.ch[i];
		++i;
	}
	int j = 0;
	while (j <= str2.length) {    //连带结束符复制
		str.ch[i+j] = str2.ch[j];
		++j;
	}
	str.length = str1.length+str2.length;
	return 1;
}

//求子串
int substring(pStr& substr, pStr str, int pos, int len)
{
	if (pos < 0 || pos >= str.length || len < 0 || len > (str.length - pos)) {
		return 0;
	}
	if (substr.ch) {
		free(substr.ch);
		substr.ch = NULL;
	}

	if (len == 0) {
		substr.ch = NULL;
		substr.length = 0;
		return 1;
	} else {
		substr.ch = (char*)malloc(sizeof(char)*len+1);
		int i = pos;
		int j = 0;
		while (i < pos+len) {
			substr.ch[j] = str.ch[i];
			++i;
			++j;
		}
		substr.ch[j] = '\0';
		substr.length = len;
		return 1;
	}
}

//串清空
int clearstring(pStr& str)
{
	if (str.ch) {
		free(str.ch);
		str.ch = NULL;
	}
	str.length = 0;
	return 1;
}

