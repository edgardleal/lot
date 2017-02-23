#ifndef TREE_C
#define TREE_C
#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "num.h"
#include "list.h"
#include "strbuffer.h"

static long instances_count = 0;
static unsigned char DEBUG = 1;

extern struct Node *loadFromFile(char *fileName)
{
    struct Node *result = newTree();
    FILE *file = fopen(fileName, "r");
    struct Num *num;
    unsigned char line[80];
    
    while((fgets(line, 80, file)) != NULL)
    {
        if(line[0] == '*') {
            continue;
        }
        num = newNum();
        num->load_string(num, line);
        result->add(result, num);
    }

    free(num);
    fclose(file);
    return result;
}

static void tree_destroy_and_clean(struct Node *this)
{
    if(this->next != NULL)
    {
        this->next->previus = NULL;
        tree_destroy_and_clean(this->next);
    }

    if(this->previus != NULL) 
    {
        this->previus->next = NULL;
        tree_destroy_and_clean(this->previus);
    }

    if(this)
    {
        if(this->current != NULL)
        {
            free(this->current);
            this->current = NULL;
        }
        free(this);
    }

    instances_count = instances_count - 1;
    debug("%ld instances\n", instances_count);
}

static void destroyTree(struct Node *this)
{
    if(this->next != NULL)
    {
        this->next->previus = NULL;
        destroyTree(this->next);
    }

    if(this->previus != NULL) 
    {
        this->previus->next = NULL;
        destroyTree(this->previus);
    }

    if(this)
        free(this);
    instances_count = instances_count - 1;
    debug("%ld instances\n", instances_count);
}


static void addNode(struct Node* this, struct Num *num)
{
    if(this->current == NULL) {
        this->current = num;
    } else 
    if(this->next)
    {
        this->next->add(this->next, num);
    } 
    else 
    {
        struct Node *new = newTree();
        new->previus = this;
        new->current = num;
        this->next = new;
    }    
}


extern struct Node *newTree()
{
    struct Node *result = (struct Node*)malloc(sizeof(struct Node));
    result->destroy = &destroyTree;
    result->add     = &addNode;
    result->destroyAndClean = &tree_destroy_and_clean;
    result->current = NULL;
    result->next    = NULL;
    result->previus = NULL;
    
    instances_count = instances_count  + 1;
    debug("%ld instances\n", instances_count);
    return result;
}
#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
