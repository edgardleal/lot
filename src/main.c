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
    unsigned long i = 0, diff = 0;
    tree->current->print(tree->current);
    while(i < MAX_NUMBER) 
    {
         /* num->print(num); */
        diff = num->compare(num, tree->current);
        if(diff < 7) {
            if(num_line(num, 1) >= 3)
            if(num_line(num, 2) >= 3)
            if(num_line(num, 3) >= 3)
            if(num_line(num, 4) >= 3)
            if(num_line(num, 5) >= 3)
				    {
                printf("# Equal: %d\n", diff);
                num->print(num);
				    }
        }
        num->inc(num);
        i = i + 1;
    }

    num->destroy(num);
    tree->destroyAndClean(tree);

    return 0;
}
