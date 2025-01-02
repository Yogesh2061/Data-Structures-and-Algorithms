#include<stdio.h>

#define MAX 5
struct CircularQueue{
    int FRONT;
    int REAR;
    int DATA[MAX];
};

typedef struct CircularQueue CQ;

void enqueue(CQ *Q, int element){
    if(Q->FRONT == (Q->REAR + 1)%MAX)
    {
        printf("Queue is FULL.");
    }
    else{
        Q->DATA[Q->REAR] = element;
        Q->REAR = (Q->REAR + 1)%MAX;
        printf("%d was ENQUEUED.\n",element);
    }

}

int dequeue(CQ *Q){
    int element = -1;
    if(Q->FRONT == Q->REAR)
    {
        printf("Queue is empty.");
    }
    else{
        element = Q->DATA[Q->FRONT];
        Q->FRONT = (Q->FRONT + 1)%MAX;
    }
}

int main()
{
    int choice, data;
    // CQ Q;
    // Q.FRONT = 0;
    // Q.REAR = 0;
    CQ Q={0,0};
    do{
        printf("1. ENQUEUE\n2.DEQUEUE\n3.EXIT\n");
        printf("Choice? ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Element?");
            scanf("%d",&data);
            enqueue(&Q, data);
            break;
        case 2:
            data=dequeue(&Q);
            if(data!=-1)
            {
                printf("Dequeued element is %d\n",data);
            }
            break;
        case 3:
            printf("BYE!\n");
            break;
        }
    }while (choice!=3);
    
}