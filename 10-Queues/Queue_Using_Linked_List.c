#include <stdio.h>
#include <stdlib.h>

struct  Node {
    int data;
    struct Node *next;
}*first=NULL,*rear=NULL;


void enqueue(int x){
    struct Node *t;
    t=(struct Node *) malloc (sizeof(struct Node));
    if(t==NULL){
        printf("Queue is full\n");
    }
    else{
        t->data=x;
        t->next=NULL;
        if(first==NULL){
            first=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue(){
    struct Node *t;
    int x=-1;
    if(first==NULL){
        printf("Queue is empty\n");
    }
    else{
        x=first->data;
        t=first;
        first=first->next;
        free(t);    
    }
    return x;
}

void display(){
    struct Node *p;
    p=first;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");

}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printf("%d",dequeue());
}