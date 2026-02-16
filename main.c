// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "Node.h"

// #include "Queue.h"

// int main(int argc , char **argv) {
//   NodePtr headPtr=NULL;
//    NodePtr tailPtr=NULL;
// /* For struct Queue
//   Queue  q;
//    q. headPtr=NULL;
//    q.tailPtr=NULL;
//    q.size=0;
// */
//    int i,x;
   

//  for(i=1;i<argc;i++){
//         if(strcmp(argv[i],"x")==0){
//             x=dequeue(&headPtr,&tailPtr);
//             printf("dequeing %d\n",x);
//         }
//         else {
//        enqueue_struct(&headPtr,&tailPtr, atoi(argv[i]));
           
//         }
//  }
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

int main(int argc , char **argv) {
    
    Queue q;
    q.headPtr = NULL;
    q.tailPtr = NULL;
    q.size = 0;

    int i, order_code, qty, price_per_unit, total_price;
    int customer_no = 1;

    for(i = 1; i < argc; i++){
        if(strcmp(argv[i], "x") == 0){
            if(q.size > 0){
                int current_qty = 0;
                order_code = dequeue_struct(&q, &current_qty);
                
                printf("Cutomer no: %d\n", customer_no++); 
                
                switch(order_code){
                    case 1: printf("Ramen\n"); price_per_unit = 100; break;
                    case 2: printf("Somtum\n"); price_per_unit = 20; break;
                    case 3: printf("Fried Chicken\n"); price_per_unit = 50; break;
                    default: printf("No Food\n"); price_per_unit = 0; break;
                }

                if(price_per_unit > 0){
                    total_price = price_per_unit * current_qty;
                    printf("You have to pay %d\n", total_price);
                    
                    int cash = 0;
                    int paid = 0;
                    while(paid < total_price){
                        if(paid == 0) printf(":Cash:"); 
                        else printf("Cash:");
                        
                        scanf("%d", &cash);
                        paid += cash;
                    }
                    
                    printf("Thank you\n");
                    if(paid > total_price){
                        printf("Change is:%d\n", paid - total_price); 
                    }
                }
                printf("==========================================\n");
            } else {
                printf("The queue is empty\n");
            }

        } else {
            int order = atoi(argv[i]);
            if (i+1 < argc && strcmp(argv[i+1], "x") != 0) {
                 i++; 
                 qty = atoi(argv[i]);
            } else {
                 qty = 1; 
            }
            
            enqueue_struct(&q, order, qty);
            printf("My order is %d\n", order);
        }
    }

    printf("There are %d ppl left in the queue\n", q.size);
    

    int temp;
    while(q.size > 0){
        dequeue_struct(&q, &temp);
    }
    return 0;
}