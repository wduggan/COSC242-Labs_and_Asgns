#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

void multiply_by_3(int *a, int n) { /* note: pass int *a rather than int a[] */
    int i;
    for (i = 0; i < n; i++) {
        a[i] *= 3; /* note: can still use [] notation */
    }
}

int main(void) {
    int my_array[ARRAY_SIZE];
    int counter = 0;
    int i;

    /*while counter is less than the array size, and while scan input is still taking in
      1 value at a time (until you press ctrl+d to stop input), then add 1 to counter*/
    printf("Enter some numbers, then press ctrl+d when done:\n");
    while (counter < ARRAY_SIZE && 1 == scanf("%d", &my_array[counter])) {
        counter++;
    }
    
    multiply_by_3(my_array, counter);
    printf("New array multiplied by 3:\n");
    for (i = 0; i < counter; i++) {
        printf("%d\n", my_array[i]);
    }
    return EXIT_SUCCESS;
}
