/** \file test.h
 *  \brief Aggregate all unit tests
 *
 *    Description:  Aggregate all unit tests 
 *
 *        Version:  1.0
 *        Created:  04-03-2017 20:35:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Edgard Leal(), 
 *   Organization:  
 *
 */
#ifndef TEST_H
#define TEST_H
#include "num.h"
#include "csv.h"

void check_balls(struct Num*);
void test_compare(void);
void test_init(void);
void test_all(void);
void test_reset(void);
void test_load_string(void);
void test_line_count(void);
void test_strcpy(void);

#endif
