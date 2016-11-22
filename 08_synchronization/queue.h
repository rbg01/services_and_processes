//
//  queue.h
//  
//
//  Created by Roberto Betés on 2/11/16.
//
//



#ifndef __queue_h__
#define __queue_h__

#include <pthread.h>


#define NMAX 0x100
#define QMAX 0x10000

typedef struct TProduct {
    char name[NMAX];
    int id;
    double price;
    double off;
} Product;

typedef struct TQueue {
    
    char name[NMAX];
    Product data[QMAX];
    int init;
    int summit;
    pthread_mutex_t mutex; //mutex q dice si la cola está bloker o no
    
} Queue;

#ifdef __cplusplus
extern "C" {
#endif
    //operaciones en la cola
    extern void init(Queue *q);//iniciarla
    extern void push(Queue *q, Product p);//meter product
    extern Product shift(Queue *p);//Sacar Product
    
#ifdef __cplusplus
}
#endif

#endif
