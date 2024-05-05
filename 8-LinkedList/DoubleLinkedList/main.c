#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node * prev;
    int data;
    struct node *next;
}*first=NULL;

void creat(int A[], int n){
    struct node * t,*last;
    first=(struct node *) malloc (sizeof(struct node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;


    for(int i=1;i<n;i++){
        t=(struct node *) malloc (sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;

}

void insert(struct node*p,int index,int x){
    struct node *t;

    if(index<0 ||index-1 > length(first))return;

    if(index==0){
        t=(struct node *) malloc (sizeof(struct node));
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){
           p=p->next;
        }
        t=(struct node *) malloc (sizeof(struct node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;

    }
}

int delete(struct node *p,int index){
    int i,x;
    struct node *t;
    if(index<1 || index>length(first))return -1;

    if(index==1){
        p=first;
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        free(p);
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
            x=p->data;
            free(p);
        }
        else{
            p->prev->next=NULL;
            x=p->data;
            free(p);
        }
    }
    return x;
}

void reverse(struct node * p){
    struct node * temp;

    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}
int main()
{
    int A[]={10,20,30,40,50};
    creat(A,5);
    printf("\nlength is: %d\n",length(first));
  //  insert(first,0,5);
   // display(first);
    //printf("\n%d deleted\n",delete(first,5));
    display(first);
    reverse(first);
    display(first);



    return 0;
}
