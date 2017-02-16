#ifndef TREE_C
#define TREE_C
#include <stdio.h>
#include <stdlib.h>
#include "num.h"
#include "list.h"
#include "strbuffer.h"

static long instances_count = 0;
static unsigned char DEBUG = 1;

extern struct Node *loadFromFile(char *fileName)
{
	struct Node *result = newTree();
	FILE *file = fopen(fileName, "r");
	char c;
	struct StrBuffer *buffer = newBuffer();

	while((c = fgetc(file)) != EOF)
	{
		if(c == '*')
		{

			/* TODO: process buffer */
		} else {
			buffer->cat(buffer, c);
		}
	}

	free(buffer);
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
			this->current->destroy(this->current);
		}
	  free(this);
	}

	instances_count = instances_count - 1;
	if(DEBUG)
	printf("%d instances\n", instances_count);
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
	if(DEBUG)
	printf("%d instances\n", instances_count);
}


static void addNode(struct Node* this, struct Num *num)
{
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
	
	instances_count = instances_count  + 1;
	printf("%d instances\n", instances_count);
	return result;
}
#endif

