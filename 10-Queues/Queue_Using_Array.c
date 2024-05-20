#include <stdio.h>
#include <stdlib.h>


struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void creat(struct Queue *q, int size){
    q->front=q->rear=-1;
    q->size=size;
    q->Q=(int *)malloc(q->size*sizeof(int));

}

void enqueue(int x,struct Queue *q){
    if(q->rear==q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

void dequeue(struct Queue *q){
    if(q->front==q->rear){
        printf("Queue is empty");
    }
    else{
        printf("%d" ,q->Q[q->front]);
        q->front++;
    }
}

void display(struct Queue *q){
    for(int i=q->front+1;i<q->size;i++){
        printf("%d ",q->Q[i]);
    }
}

int main(){
    struct Queue q;
    creat(&q,5);
    enqueue(10,&q);
    enqueue(20,&q);
    enqueue(30,&q);
    enqueue(40,&q);
    enqueue(50,&q);
    display(&q);
    

    return 0;
}