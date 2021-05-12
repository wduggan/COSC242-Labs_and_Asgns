#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define STRING_LEN 80
#define ARRAY_LEN 10000

void insertion_sort(char **a, int n) {
    /* Sorting code goes here */
    /* p = position */
    int i, p;
    char *key;

    for (p = 1; p < n; p++) {
        key = a[p];
        i = p-1;
        
        while (i >= 0 && strcmp(a[i], key) > 0){
            a[i+1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int main(void) {
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    int i;
    clock_t start, end;
    
    printf("Enter some words, then press ctrl+d when done:\n");
    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)) {
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }

    start = clock();
    insertion_sort(wordlist, num_words);
    end = clock();
    
    printf("Sorted arrray:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\n", wordlist[i]);
    }

    for (i = 0; i < num_words; i++) {
        free(wordlist[i]);
    }
    
    fprintf(stderr, "Number of words: %d, Time: %f\n", num_words, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
