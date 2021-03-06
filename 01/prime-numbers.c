#include <stdio.h>

int is_prime(int candidate){
    int i = 0;
    for (i = 2; i < candidate; i++){
        if (candidate % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int candidate = 2;
    int num_printed = 0;
    while (num_printed < 100) {
        if (is_prime(candidate)) {
            printf("%d\n", candidate);
            num_printed++;
        }
        candidate++;
    }
    return 0;
}
