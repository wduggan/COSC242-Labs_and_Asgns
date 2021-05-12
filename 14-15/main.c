#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void print_key(char *s) {
    printf("%s\n", s);
}

int main() {
    /*
    bst b = bst_new();

    b = bst_insert(b, "hello");
    b = bst_insert(b, "world");
    
    printf("%d\n", bst_search(b, "hello"));
    printf("%d\n", bst_search(b, "no"));
    
    bst_inorder(b, print_key);
    printf("\n\n");
    bst_preorder(b, print_key);
    printf("\n\n");

    return 0; 
    */
    bst b = bst_new();
    b = bst_insert(b, "hello");
    b = bst_insert(b, "world");
    b = bst_insert(b, "five");
    printf("%d\n", bst_search(b, "hello"));
    printf("%d\n", bst_search(b, "no"));
    bst_inorder(b, print_key);
    printf("\n\n");
    bst_preorder(b, print_key);
    b = bst_delete(b, "hello");
    printf("\n\n");
    bst_inorder(b, print_key);
    printf("\n\n");
    bst_preorder(b, print_key);
    bst_free(b);
    return 0; 
}
