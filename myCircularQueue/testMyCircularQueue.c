#include <stdio.h>
#include "myCircularQueue.h"

int main(int argc, char *argv[])
{
    MyCircularQueue *queue;
    queue = myCircularQueueCreate(2);
    myCircularQueueEnQueue(queue, 1);
    myCircularQueueEnQueue(queue, 2);
    myCircularQueueDeQueue(queue);
    myCircularQueueEnQueue(queue, 3);
    myCircularQueueDeQueue(queue);
    myCircularQueueEnQueue(queue, 3);
    myCircularQueueDeQueue(queue);
    myCircularQueueEnQueue(queue, 3);
    myCircularQueueDeQueue(queue);
    myCircularQueueFront(queue);


    

    myCircularQueueFree(queue);

}
