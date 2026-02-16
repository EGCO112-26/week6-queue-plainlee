#ifndef Node_h
#define Node_h

struct node
{
    int order_number;
    int qty;
    struct node *nextPtr;
};

typedef struct node order;
typedef struct node* OrderPtr;

#endif