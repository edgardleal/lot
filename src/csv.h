/*! \file csv.h
 * =====================================================================================
 *
 *       Filename:  csv.h
 *       \brief     Load contents to csv files 
 *
 *    Description:  Define functions for csv file proccess
 *
 *        Version:  1.0
 *        Created:  01-03-2017 18:53:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Edgard Leal
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef CSV_H
#define CSV_H
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

extern void split_csv(char *, char**, int);
extern void csv_start_columns(char**, int);
extern void csv_load_from_file(char *, struct Node *);
extern struct Num * csv_new_num_from_string(char *);

#endif
/* vim: set expandtab tabstop=4 :*/
