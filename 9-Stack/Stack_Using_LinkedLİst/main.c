#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int data;
    struct Stack *next;
}*first=NULL;


void push(struct Stack *p,int x){
        struct Stack *temp;
        if(first==NULL){
            first=(struct Stack *) malloc (sizeof(struct Stack));
            first->data=x;
            first->next=NULL;
        }
        else{
            temp=(struct Stack *) malloc (sizeof(struct Stack));
            temp->data=x;
            temp->next=first;
            first=temp;
        }
}

int length(struct Stack *p){
    int len=0;
    if(p==NULL) return len;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
int pop(struct Stack *p){
    int x=-1;
    struct Stack *temp;
    if(first==NULL){
        printf("stack is empty");
    }
    else{
        x=first->data;
        temp=p;
        p=p->next;
        free(temp);
        first=p;
    }
    return x;
}

int isEmpty(struct Stack *p){
     if(first==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(struct Stack *p,int pos){
    int x;
    if(pos<=0 || pos > length(first)){
        printf("invalid position\n");
    }
    else{
        for(int i=1;i<pos;i++){
            p=p->next;
        }
        x=p->data;
    }
    return x;
}
void display(struct Stack *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    push(first,10);
    push(first,20);
    push(first,30);
    push(first,40);
    push(first,50);
    push(first,60);
    push(first,70);
    printf("%d\n",length(first));
    printf("%d\n",peek(first,5));

    display(first);
    printf("%d\n",pop(first));
    printf("%d\n",pop(first));
    printf("%d\n",pop(first));
    printf("%d\n",pop(first));
    printf("%d\n",pop(first));
    printf("%d\n",pop(first));
    printf("%d\n",pop(first));
    printf("%d\n",pop(first));
    display(first);
    isEmpty(first)?printf("Stack is empty"):printf("stack is full");


    return 0;
}
