/*! \file list.h
 * =====================================================================================
 *
 *       Filename:  list.h
 *          \brief Implements a linked list of Num
 *
 *    Description:  Implements a linked list of structs Num
 *
 *        Version:  1.0
 *        Created:  01-03-2017 18:53:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Edgard Leal <edgardleal@gmail.com>
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef TREE
#define TREE

#include "num.h"

/* \struct 
 * Represents a single node of a linked list. Every node has a link to next and previus node, 
 * if this node is the first of the list, the point in previus field is NULL. If this is the last
 * node in this list, the fild next if NULL.
     *
 */
struct Node {
	struct Num *current;
	struct Node *next;
	struct Node *previus;

	void (*destroy)(struct Node *this);
	void (*destroyAndClean)(struct Node *this);

	void (*add)    (struct Node *this, struct Num *num);
};

extern struct Node *newTree();
extern struct Node *list_loadFromFile(char *);
static void destroyTree(struct Node *this);
static void addNode(struct Node* this, struct Num *num);
static void tree_destroy_and_clean(struct Node *this);



#endif
