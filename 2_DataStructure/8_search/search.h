/**************************************************************************** **
 * Copyright (C) 2001-2020 Inhand Networks, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : search.h
 *     FIRST CREATION DATE    : 2020/10/08
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/10/08
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _SEARCH_H_
#define _SEARCH_H_

/*------------------Macro Definition-------------------------*/
/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
int Search(int a[], int n, int k);
int Bsearch(int R[], int low, int high, int k);
/*------------------End of API Definition--------------------*/

#endif /* End of _SEARCH_H_ */

