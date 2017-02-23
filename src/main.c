#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include "num.h"
#include "list.h"
#include "args.h"

#define MAX_EQUAL 6


/**
 *
 */
int main(int argc, char *argv[]) 
{
    struct config config;
    args_default(&config);
    argp_parse(&argp, argc, argv, 0, 0, &config);

    struct Num  *num  = newNum();
    struct Node *tree = loadFromFile("numbers");
    unsigned long i = 0, equal = 0;
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
        /* num->print(num); 
        equal = num->compare(num, tree->current);
        * */
        if(maxEqual <= MAX_EQUAL) {
            if(num_line(num, 1) >= 3)
            if(num_line(num, 2) >= 3)
            if(num_line(num, 3) >= 3)
            if(num_line(num, 4) >= 3)
            if(num_line(num, 5) >= 3)
            {
                debug("# Equal: %d\n", maxEqual);
                num->print(num);
                tree->add(tree, num->clone(num));
            }
        }
        num->inc(num);
        i = i + 1;
    }

    num->destroy(num);
    tree->destroyAndClean(tree);

    return 0;
}
