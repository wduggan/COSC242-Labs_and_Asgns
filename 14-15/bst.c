#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

struct bstnode { /* should live in bst.c */
    char *key;
    bst left;
    bst right;
};
/*returns null node to represent empty new tree*/
bst bst_new() {
    return NULL;
}

int bst_search(bst b, char *key) {
    if (b == NULL) {
        return 0;
    }
    /* strcmp returns 0 if strings are equal, 1 if the current key is bigger than the key being searched, and negative if
     * the current key is less than the key being searched
    */
    /* If the keys are equal, return 1 */
    if (strcmp(b->key, key) == 0) {
        return 1;
    /* If the searched key is greater, search left tree instead */
    } if(strcmp(b->key, key) > 0) {
        return bst_search(b->left, key);
    /* If the searched key is less than, search right tree instead */
    } else if(strcmp(b->key, key) < 0) {
        return bst_search(b->right, key);
    }

}

bst bst_insert(bst b, char *key) {
    /*If an empty tree, we can allocate memory, copy in the key into the node, and return the result. */
    if(b == NULL) {
        b = malloc(sizeof *b);
        b->key = malloc((strlen(key) + 1) * sizeof key[0]);
        b->left = NULL;
        b->right = NULL;
        b->key = strcpy(b->key, key);
        return b;
    }

    /* If the current top node value is greater than key being inserted, then we insert into the left subtree */
    if(strcmp(b -> key, key) > 0) {
        b->left = bst_insert(b->left, key);
    /* else if the current top node value is less than key being inserted, then we insert into the right subtree */
    } else if(strcmp(b -> key, key) < 0) {
        b->right = bst_insert(b->right, key);
    }

    /* return modified tree */
    return b;
}

void bst_inorder(bst b, void f(char *s)) {
    /* if tree is null then return, stopping */
    if(b == NULL) {
        return;
    }
    /* call self on left subtree, traversing recursively */
    bst_inorder(b->left, f);
    /* call print method on current node */
    f(b->key);
    /* call self on right subtree, traversing recursively */
    bst_inorder(b->right, f);
}

void bst_preorder(bst b, void f(char *s)) {
    /* if tree is null then return, stopping */
    if(b == NULL) {
        return;
    }
    /* call print method on current node */
    f(b->key);
    /* call self on left and right, traversing subtree recursively */
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

bst bst_delete(bst b, char *key) {
    char *tmp;
    bst tmp_bst;

    /* if tree is null then return, stopping */
    if(b == NULL) {
        return NULL;
    }
 
    /* 
     * if node to delete matches node found then take out node, 
     *
     * else if nodes value is more than value of node to delete then call delete
     * recursively on left subtree
     * 
     * else if nodes value is less than value of node to delete then call delete 
     * recursively on right subtree
     */
    if(strcmp(b -> key, key) == 0) {
        if(b -> left == NULL) {
            free(b -> key);
            tmp_bst = b -> right;
            free(b);
            b = tmp_bst;
        } else if(b -> right == NULL) {
            free(b -> key);
            tmp_bst = b -> left;
            free(b);
            b = tmp_bst;
        } else {
            tmp_bst  = b -> right;
            while(tmp_bst -> left != NULL) {
                tmp_bst = tmp_bst -> left;
            }
            /* swap node values of node and leftmost node from right subtree,
             * then delete node */
            tmp = b -> key;
            b -> key = tmp_bst -> key;
            tmp_bst -> key = tmp;
            b -> right = bst_delete(b -> right, tmp_bst -> key);
        }
    } else if(strcmp(b -> key, key) > 0) {
        b -> left = bst_delete(b -> left, key);
    } else if(strcmp(b -> key, key) < 0) {
        b -> right = bst_delete(b -> right, key);
    }

    /* return modified tree */
    return b;
}

bst bst_free(bst b) {
    /* if tree is null then return, stopping */
    if(b == NULL) {
        return NULL;
    }

    /* free left and right subtrees recursively */
    bst_free(b -> left);
    bst_free(b -> right);

    /* free node and it's key */
    free(b -> key);
    free(b);
    return NULL;
}
