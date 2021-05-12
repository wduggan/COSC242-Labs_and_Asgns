#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

#define MAX 50

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

queue queue_new() {
    queue q = emalloc(sizeof *q);
    q -> capacity = MAX;
    q -> num_items = 0;
    q -> head = 0;
    q -> items = emalloc(q->capacity * sizeof q->items[0]);
    
    return q;
}

/**
 * Adds value to the tail of the queue, basically insertion, follows FIFO
 * @param q - queue to insert into
 * @param item - item to be inserted at positon
 */
void enqueue(queue q, double item){
    int position = (q->head + q->num_items) % q->capacity;
    
    if (q->num_items < q->capacity) {
        q->items[position] = item;
        q->num_items++;
    }
}

/* Removes value from the head of the queue, basically deletion, follows FIFO */
double dequeue(queue q){
    double item;

    /*if queue is greater than 0 (not empty) then dequeue, else quit program if it is empty*/
    if(q->num_items > 0) {
        item = q->items[q->head];
    } else {
        exit(1);
    }

    /*
     * if head index has reached end of array, loop back to zero, else increment
     * it
     */
    if(q -> head == q -> capacity - 1) {
        q -> head = 0; 
    } else {
        q -> head++;
    }

    q -> num_items--;
    
    return item;
}

void queue_print(queue q){
    int i;
    int count = 0;
    
    /* Print out the items in the queue, one per line, from the head to tail (capacity) */
    for(i = q->head; i < q->capacity; i++) {
        /* if printed all items in queue before reaching capacity, do exit function */
        count++;
        if (count > g->num_items) {
            return;
        }
        printf("%f\n", q->items[i]);
    }
}

int queue_size(queue q){
    return q->num_items;
}

queue queue_free(queue q) {
    /* free the memory associated with the queue */
    int i;
    /* free each item in the queue */
    for(i = 0; i < q->num_items; i++) {
        free(q->items[i]);
    }
    free(q->items);
    free(q);
}
