#include <stdio.h>

int main(void) {
    double s1, s2, s3;
    int n;
    double result;
    double biggest = 0;
    double temp;
    int winnerID = 0;

    printf("Enter competitor's registration number and the three judge's scores\n");
    fflush(stdout);

    while (4 == scanf("%d%lg%lg%lg", &n, &s1, &s2, &s3)) {
        if (s1 < s2 && s1 < s3){
            result = (s2 + s3)/2;
            printf("%f\n", result );
            temp = result;
        } else if (s2 < s1 && s2 < s3){
            result = (s1 + s3)/2;
            printf("%f\n", result );
            temp = result;
        } else {
            result = (s1 + s2)/2;
            printf("%f\n", result );
            temp = result;
        }
        if (temp > biggest) {
            biggest = temp;
            winnerID = n;
        }
    }
    printf("The winner is competitor %d with a score of %f\n", winnerID, biggest);
    
    return 0;
}
