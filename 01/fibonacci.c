#include <stdio.h>
int main(void) {
    int f = 0;
    int g = 1;
    int i = 0;
    int temp = 0;
    for (i = 0; i < 40; i++) {
        printf("%d\n", g);
        temp = g;
        g = g+f;
        f = temp;
        if (i % 5 == 0){
            printf("\n");
        }
    }
    printf("Finished.\n");
    return 0;
}
