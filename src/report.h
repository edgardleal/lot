/** \file report.h
 *  \brief Funcionalities to generate reports 
 *
 *    Description: Funcionalities to generate report  
 *
 *        Version:  1.0
 *        Created:  04-03-2017 20:14:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Edgard Leal(), 
 *   Organization:  
 *
 */
#ifndef REPORT_H
#define REPORT_H
#include "list.h"
#include "color.h"

/** \struct MostUsed 
 *  \brief Store statistics for most used number 
 *
 *  This should inform what is the most appeared number in all results.
 */
struct MostUsed {
    int max;
    int min;
    int balls[25];
    int cols[5];
    int lines[5];
};

extern struct MostUsed *newMostUsed(void);
void fill_most_used(struct Node*, struct MostUsed*);
char *color_for_ratio(int, int, int);
void print_most_used(struct MostUsed*);

#endif
