#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num.h"
#include "list.h"

/**
 *
 *
 */
int main() 
{
    struct Num  *num  = newNum();
    struct Node *tree = loadFromFile("numbers");
    unsigned int i = 0, diff = 0;
    tree->current->print(tree->current);
    while(i < 3000000) 
    {
        /* num->print(num); */
        diff = num->compare(num, tree->current);
        if(diff < 8) {
            num->print(num);
        }
        num->inc(num);
        i = i + 1;
    }

    num->destroy(num);
    tree->destroyAndClean(tree);

    return 0;
}
