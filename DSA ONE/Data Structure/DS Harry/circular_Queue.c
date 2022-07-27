#include <stdio.h>
#include <stdlib.h>
#define size 10

struct Queue
{
    int front;
    int rear;
    int *queue;
} q;

int isFull()
{
    if (q.front == (q.rear + 1) % size)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (q.front == -1)
        return 1;
    else
        return 0;
}

int enqueue(int element)
{
    if (isFull())
    {
        printf("\nQueue is Overflow!");
    }
    else
    {
        if (q.front == -1)
        {
            q.front = 0;
            q.rear = 0;
        }
        else
        {
            q.rear = (q.rear + 1) % size;
        }
        q.queue[q.rear] = element;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue is Underflow!");
    }
    else
    {
        printf("\n%d is deleted", q.queue[q.front]);
        if (q.front == q.rear)
        {
            q.front = -1;
            q.rear = -1;
        }
        else
        {
            q.front = (q.front + 1) % size;
        }
    }
}

int display()
{
    int i;
    printf("\nFront : %d\nRear : %d", q.front, q.rear);
    if (isEmpty())
    {
        printf("\nQueue is Empty!");
    }
    else
    {
        for (i = q.front; i != q.rear; i = (i + 1) % size)
            printf("\nindex : %d -> %d", i, q.queue[i]);
        printf("\nindex : %d -> %d", i, q.queue[i]);
    }
}

int main()
{
    q.front = -1;
    q.rear = -1;
    q.queue = (int *)malloc(size * sizeof(int));
    int manue = 0, element;

    printf("\t0) Exit\n\t1) Insert\n\t2) Delete\n\t3) Display\n");

start:
    printf("\n--> ");
    scanf("%d", &manue);
    switch (manue)
    {
    case 0:
        goto end;
    case 1:
        printf("Enter Element : ");
        scanf("%d", &element);
        enqueue(element);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    default:
        printf("\nEnter valid number");
        break;
    }
    goto start;
end:

    return 0;
}