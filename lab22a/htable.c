#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "htable.h"

struct htablerec {
    int capacity;
    int num_keys;
    char *keys;
    int *frequencies;
};

htable htable_new(int capacity) {
    int i;
    
    htable result = emalloc(sizeof *result);
    result -> capacity = 11;
    result -> num_keys = 0;
    /* result -> frequencies = int a[result->capacity]; */
    result -> frequencies = emalloc(result->capacity * sizeof result->frequencies[0]);
    result -> keys = emalloc(result->capacity * sizeof result->keys[0]);

    for (i = 0; i <= result->capacity; i++){
        result -> keys[i] = NULL;
        result -> frequencies[i] = 0;
    }
    
    return result;
}

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
        
    while (*word != ’\0’) {
        result = (*word++ + 31 * result);
    }
    return result;
}

int htable_insert(htable h, char *str) {
    int i = htable_word_to_int(str) % h->capacity;
    int same = 0;
    int pass = 0;

    if (h->keys[i] == NULL) {
        strcpy(h->keys[i], str);
        h->frequencies[i] = 1;
        h->num_keys++;
        return 1;
    } else if(strcmp(h -> keys[i], str) == 0) {
        h -> frequencies[i]++;
        return h -> frequencies[i];

    } else {
        /* loop until empty position found or hash table is found to be full */
        while(h -> keys[i] != NULL && pass < 2) {
            /* if already exists in hash table then break loop */
            if(strcmp(str, h -> keys[i]) == 0) {
                same = 1;
                break;
            }
            /* 
             * if reached end of table so loop back to start of table
             */
            if(i == h -> capacity) {
                i = 0;
                pass++;
            }
        }

        /* if value already exists in table, increment it's frequency
         *
         * else if table is full and value does not exist in table, then return
         * with error
         *
         * else add value to empty position in table
         */
        if(same == 1) {
            h->frequencies[i]++;
            return h->frequencies[i];

        } else if(pass == 2) {
            return 0;

        } else {
            strcpy(h->keys[i], str);
            h->frequencies[i] = 1;
            h->num_keys++;
        }
    }
    return 1;
}

void htable_print(htable h, FILE *stream) {
    int i;
    /* print each key and it's respective frequency while key is not empty */
    for(i = 0; i < h->num_keys; i++) {
        if(h->keys[i] != NULL) {
            fprintf(stream, "%d%s\n", h->frequencies[i], h->keys[i]);
        }
    }
}

void htable_free(htable h) {
    /* free the memory associated with the hashtable */
    int i;
    free(h -> frequencies);
    /* free each key in the hashtable */
    for(i = 0; i < h->num_keys; i++) {
        free(h->keys[i]);
    }

    free(h->keys);
    free(h);
}
