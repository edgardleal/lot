#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num.h"
#include "list.h"

#define MAX_EQUAL 6

/**
 *
 *
 */
int main() 
{
    struct Num  *num  = newNum();
    struct Node *tree = loadFromFile("numbers");
    unsigned long i = 0, equal = 0;
    tree->current->print(tree->current);

		struct Node *node = NULL;
		int maxEqual = -1;
    while(i < MAX_NUMBER) 
    {
			node = tree;
			maxEqual = 0;
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
                printf("# Equal: %d\n", maxEqual);
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
