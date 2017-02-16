#ifndef TREE
#define TREE

#include "num.h"

struct Node {
	struct Num *current;
	struct Node *next;
	struct Node *previus;

	void (*destroy)(struct Node *this);
	void (*destroyAndClean)(struct Node *this);

	void (*add)    (struct Node *this, struct Num *num);
};

extern struct Node *newTree();
extern struct Node *loadFromFile(char*);
static void destroyTree(struct Node *this);
static void addNode(struct Node* this, struct Num *num);
static void tree_destroy_and_clean(struct Node *this);



#endif
