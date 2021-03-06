/** \file main.c
 *  \brief Main entry point for application
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
 */
#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include "report.h"
#include "args.h"
#include "app.h"
#include "csv.h"
#include "number/simulation.h"

void better_numbers(void);
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
    else if (config.SIMULATION)
    {
        simulation_report();
    }
    else if (config.BETTER)
    {
        better_numbers();
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
    struct MostUsed *data = newMostUsed();
    csv_load_from_file(config.RESULT_PATH, result);

    fill_most_used(result, data);
    print_most_used(data);

    free(data);
    result->destroyAndClean(result);
}

int columns_fit(struct Num *num, int limit)
{
    return num->cols[0] >= limit 
        && num->cols[1] >= limit
        && num->cols[2] >= limit
        && num->cols[3] >= limit
        && num->cols[4] >= limit;

}

/**
 * \fn better_numbers
 * \brief choose the numbers with better result
 *
 */
void better_numbers(void)
{
    struct Node *tree = newTree();
    struct Num *num  = newNum();

    out("Tree is filled: %d", tree != NULL);
    out("loading csv result file ...\n");
    csv_load_from_file(config.RESULT_PATH, tree);
    out("csv loaded!");
    struct Node *tmp = tree;
    num->reset(num);

    int i = 0,
        inner_limit = 0,
        difference = 0;
    char number_buffer[30];
    out("starting the loop...");
    while(i < config.LIMIT)
    {
        tmp = tree;
        difference = 0;
        while(tmp != NULL && inner_limit < 200)
        {
            difference += tmp->current->compare(tmp->current, num);
            tmp = tmp->next;
            inner_limit++;
        }
        num->toString(num, number_buffer);
        out("%10d - %s", difference);
        num->inc(num);
        i++;
        tmp = tmp->next;
    }

    num->destroy(num);
    tree->destroyAndClean(tree);
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
    FILE *appendFile;
    char appendBuffer[30];
    struct Num *num  = newNum();
    num->reset(num);
    debug("Loading numbers from file...");
    struct Node *tree = list_loadFromFile(config.MY_NUMBERS_FILE_NAME);
    unsigned long i = 0;
    int equal = 0;
    tree->current->print(tree->current);

    if (config.APPEND) 
    {
        appendFile = fopen(config.MY_NUMBERS_FILE_NAME, "a");
    }


    struct Node *node = tree->next;
    while(node != NULL)
    {
        node->current->print(node->current);
        node = node->next;
    }
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

            if(node->next != NULL) /* useless comparation */
            {
                node = node->next;
            } else {
                node = NULL;
            }
        }
        if(maxEqual <= config.SIMILARITY) {
            if(columns_fit(num, config.COLUMN_LIMIT))
            if(num_line(num, 1) >= config.LINE_LIMIT)
            if(num_line(num, 2) >= config.LINE_LIMIT)
            if(num_line(num, 3) >= config.LINE_LIMIT)
            if(num_line(num, 4) >= config.LINE_LIMIT)
            if(num_line(num, 5) >= config.LINE_LIMIT)
            {
                debug("# Equal: %d\n", maxEqual);
                num->print(num);
                if (config.APPEND)
                {
                    output_num_simple(num, appendBuffer);
                    fprintf(appendFile, appendBuffer);
                }
                tree->add(tree, num->clone(num));
            }
        }
        num->inc(num);
        i = i + 1;
    }

    if (config.APPEND) 
    {
        fclose(appendFile);
    }

    free(num);
    tree->destroyAndClean(tree);
}
