#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num.h"
#include "list.h"

int main() 
{
    struct Num  *num  = newNum();
    num->write_to_file(num, "saida.txt");
    struct Node *tree = newTree();
    tree->current = num;
    int i = 0;
    while(i < 252) 
    {
        num->print(num);
        num->inc(num);
        i = i + 1;
            tree->add(tree, num->clone(num));
    }
    struct Node *tmp = tree->next;

    tree->destroyAndClean(tree);

    return 0;
}
