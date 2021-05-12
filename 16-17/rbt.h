#ifndef BST_H_
#define BST_H_

#include <stdio.h>

typedef struct rbt_node *rbt;
typedef enum { RED, BLACK } rbt_colour;

extern rbt  rbt_new();
extern int  rbt_search(rbt r, char *key);
extern rbt  rbt_insert(rbt r, char *key);
extern void rbt_inorder(rbt r, void f(char *key));
extern void rbt_preorder(rbt r, void f(char *key));
extern rbt  rbt_delete(rbt r, char *key);
extern rbt  rbt_free(rbt r);

extern rbt  right_rotate(rbt r);
extern rbt  left_rotate(rbt r);
extern rbt  rbt_fix (rbt r);

#endif
