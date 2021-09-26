#ifndef _MYCIRCULARQUEUE_H
#define _MYCIRCULARQUEUE_H
#include <stdbool.h>
typedef struct {
	int head;
	int tail;
	int *buffer;
	int size;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue *obj);
bool myCircularQueueIsFull(MyCircularQueue *obj);
MyCircularQueue *myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue *obj);
int myCircularQueueFront(MyCircularQueue *obj);
int myCircularQueueRear(MyCircularQueue *obj);
void myCircularQueueFree(MyCircularQueue *obj);
#endif //_MYCIRCULARQUEUE_H
