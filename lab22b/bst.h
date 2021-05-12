#ifndef BST_H_
#define BST_H_

#include <stdio.h>

typedef struct bstnode *bst;

extern bst  bst_new();
extern int  bst_search(bst b, char *key);
extern bst  bst_insert(bst b, char *key);
extern void bst_inorder(bst b, void f(char *key));
extern void bst_preorder(bst b, void f(char *key));
extern bst  bst_delete(bst b, char *key);
extern bst  bst_free(bst b);

#endif
