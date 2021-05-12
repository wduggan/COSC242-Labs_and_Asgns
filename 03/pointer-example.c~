#include <stdio.h>

int main(void) {
    double s1, s2, s3;

    printf("This program will read in three judges scores and print out the final score\n");
    fflush(stdout);

    printf("Enter first score:\n");
    scanf("%lg", &s1);
    printf("Enter second score:\n");
    scanf("%lg", &s2);
    printf("Enter third score:\n");
    scanf("%lg", &s3);

    if (s1 < s2 && s1 < s3){
        printf("%f\n", (s2 + s3)/2 );
    } else if (s2 < s1 && s2 < s3){
        printf("%f\n", (s1 + s3)/2 );
    } else {
        printf("%f\n", (s1 + s2)/2 );
    }
    
    return 0;
}
