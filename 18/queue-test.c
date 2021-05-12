#include <stdio.h>
#include "rbt.h"

static void print_key(char *s) {
    printf("%s\n", s);
}

int main() {
    rbt r = rbt_new();
    r = rbt_insert(r, "hello");
    r = rbt_insert(r, "world");
    r = rbt_insert(r, "five");
    printf("%d\n", rbt_search(r, "hello"));
    printf("%d\n", rbt_search(r, "no"));
    rbt_inorder(r, print_key);
    printf("\n\n");
    rbt_preorder(r, print_key);
    r = rbt_delete(r, "hello");
    printf("\n\n");
    rbt_inorder(r, print_key);
    printf("\n\n");
    rbt_preorder(r, print_key);
    rbt_free(r);
    return 0; 
}