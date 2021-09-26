#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myCircularQueue.h"
bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
	if (obj->head == obj->tail && obj->head == -1)
		return true;
	else
		return false;
}
bool myCircularQueueIsFull(MyCircularQueue *obj)
{

	if ((obj->tail + 1) % obj->size == obj->head)
	{
		return true;
	}
	else
		return false;
}
MyCircularQueue *myCircularQueueCreate(int k)
{
	MyCircularQueue *my_queue_instance = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	if (my_queue_instance == NULL)
	{
		//printf("mem malloc fail\n");
		return NULL;
	}
	my_queue_instance->buffer = (int *)malloc(k*sizeof(int));
	if (my_queue_instance->buffer == NULL)
	{
		//printf("mem buffer malloc fail\n");
		free(my_queue_instance);
		return NULL;
	}

	//printf("create the circular queue successful\n");
	my_queue_instance->head = -1;
	my_queue_instance->tail = -1;
	my_queue_instance->size = k;
	return my_queue_instance;


}
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		//printf("the queue is full\n");
		return false;
	}
	else {
		if (myCircularQueueIsEmpty(obj))
			obj->head = 0;
		obj->tail = (obj->tail + 1) % obj->size;
		obj->buffer[obj->tail] = value;
		//printf("enqueue successful\n");
		return true;
	}
}
bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		//printf("queue is empty\n");
		return false;
	}
	else {
		if (obj->head == obj->tail)
		{
			obj->head = obj->tail = -1;
			return true;
		}
	//	obj->head = obj->head + 1 % obj->size;
		obj->head = (obj->head + 1) % obj->size;
		return true;
	}
}
int myCircularQueueFront(MyCircularQueue *obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		//printf("queue is empty\n");
		return -1;
	}
	else
		return obj->buffer[obj->head];
}
int myCircularQueueRear(MyCircularQueue *obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		//printf("queue is empty\n");
		return -1;
	}
	else return obj->buffer[obj->tail];
}
void myCircularQueueFree(MyCircularQueue *obj)
{
	free(obj->buffer);
	free(obj);
}
