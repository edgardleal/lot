/*! \file Main
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main entry point of application
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include "num.h"
#include "list.h"
#include "args.h"

void generate_numbers(void);
void print_report(void);

/** \fn Main entry point of this application.
 */
int main(int argc, char **argv) 
{
    args_default();
    argp_parse(&argp, argc, argv, 0, 0, &config);
    if(config.PRINT_REPORT)
    {
        print_report();
    }
    else
    {
        generate_numbers();
    }

    return 0;
}

/** \fn
 *  \brief Print report for ~/.lot/results.csv
 *
 *  Print a colored statistic report for historical results in the file 
 *  ~/.lot/results.csv.
 */
void print_report()
{
    struct Node *result = newTree();
    csv_load_from_file(config.RESULT_PATH, result);

    result->destroyAndClean(result);
}

/** \fn 
 *  \brief Generate number 
 *
 *  Generate numbers based on option passed to this program 
 *  by command line, and print these numbers on default output.
 *
 */
void generate_numbers()
{
    struct Num  *num  = newNum();
    struct Node *tree = loadFromFile(config.MY_NUMBERS_FILE_NAME);
    unsigned long i = 0;
    int equal = 0;
    tree->current->print(tree->current);

    struct Node *node = NULL;
    while(i < config.LIMIT) 
    {
        node = tree;
        int maxEqual = 0;
        while(node != NULL && node->current != NULL)
        {
            /* */
            equal = num->compare(num, node->current);
            if(equal > maxEqual)
            {
                maxEqual = equal;
            }

            if(node->next != NULL)
            {
                node = node->next;
            } else {
                node = NULL;
            }
        }
        if(maxEqual <= config.SIMILARITY) {
            if(num_line(num, 1) >= config.LINE_LIMIT)
            if(num_line(num, 2) >= config.LINE_LIMIT)
            if(num_line(num, 3) >= config.LINE_LIMIT)
            if(num_line(num, 4) >= config.LINE_LIMIT)
            if(num_line(num, 5) >= config.LINE_LIMIT)
            {
                debug("# Equal: %d\n", maxEqual);
                num->print(num);
                tree->add(tree, num->clone(num));
            }
        }
        num->inc(num);
        i = i + 1;
    }

    tree->destroyAndClean(tree);
}
