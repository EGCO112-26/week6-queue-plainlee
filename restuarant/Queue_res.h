#include "Node_res.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	OrderPtr headPtr, tailPtr;
	int size;
} Queue;

void enqueue_struct(Queue* q, int order_num, int quantity){
    OrderPtr new_node = (OrderPtr) malloc(sizeof(order));
    if(new_node){ 
        new_node->order_number = order_num;
        new_node->qty = quantity;
        new_node->nextPtr = NULL;
        if(q->headPtr == NULL) q->headPtr = new_node;
        else q->tailPtr->nextPtr = new_node;
        q->tailPtr = new_node;
        q->size++;
    }
}

int dequeue_struct(Queue *q, int *qty_out){
    OrderPtr t = q->headPtr;
    if(t){
        int value = t->order_number;
        *qty_out = t->qty;
        q->headPtr = t->nextPtr;
        if(q->headPtr == NULL) q->tailPtr = NULL;
        free(t);
        q->size--;
        return value;
    }
    printf("The queue is empty\n");
    return 0;
}