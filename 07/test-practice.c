#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_ARRAY_LENGTH 79

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL = result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int main(void) {
    char word[MAX_WORDS];
    char *words[MAX_WORD_ARRAY_LENGTH];
    int i;
    int num_words = 0;
    double average = 0;

    while (num_words < MAX_WORD_ARRAY_LENGTH && 1 == scanf("%79s", word)) {
        words[num_words] = emalloc((strlen(word) + 1) * sizeof words[0][0]);
        strcpy(words[num_words], word);
        num_words++
    }

    for (i = 0; i < num_words; i++) {
        average += strlen(words[i]);
    }
    average /= num_words;
    print_array(words, num_words, average);

    return EXIT_SUCCESS;
}

void print_array(char **a, int n, double avg) {
    if(n > 0) {
        if(strlen(*a) > avg) {
            printf("%s\n", *a);
        }
        print_array(a + 1, n - 1, avg);
    }
}