#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
    int data;
    struct node * next;
}*first=NULL,*second=NULL,*third=NULL;

void creat(int A[],int n){
    int i;
    struct node *t,*last;
    first= (struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
        }
}

void creat_2(int A[],int n){
    int i;
    struct node *t,*last;
    second= (struct node*)malloc(sizeof(struct node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
        }
}

void display( struct node *p){
    while(p!=NULL){
        printf("%d=>",p->data);
        p=p->next;
    }
  //  printf("%d",p->data);
}

void Rdisplay( struct node *p){
    if(p!=NULL){
        Rdisplay( p->next);
        printf("%d=>",p->data);
        }

  //  printf("%d",p->data);
}

int count (struct node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

int Rcount(struct node *p){
    if(p){
        return Rcount(p->next)+1;
    }
    else{
        return 0;
    }
}

int Sum(struct node *p){
    int sum=0;
    while(p){
       sum+= p->data;
       p=p->next;
    }
    return sum;
}

int RSum(struct node *p){
    if(p){
       return RSum(p->next)+p->data;
    }
    else{
        return 0;
    }

}

int max(struct node *p){
    int max=-32768;
    while(p){
        if(p->data>=max)
            max=p->data;
        p=p->next;
    }
    return max;
}
int Rmax(struct node *p){
    int max=-32768;
    if(p==NULL){
        return max;
    }
    else{
        max=Rmax(p->next);
        if(max>p->data){
            return max;
        }
        else{
            return p->data;
        }
    return p->data;
}
}

node * search(struct node *p, int key){
    struct node * q =NULL;


  while(p){
    if(p->data==key){
        q->next=p->next;
        p->next=first;
        first=p;
    }
    q=p;
    p=p->next;
  }
}

void insert(struct node *p,int pos , int x){

    struct node * q;


    if(pos<0 ||pos > count(p))
        return;
    q=(struct node *) malloc (sizeof(struct node));
    q->data=x;
    if(pos==0)
    {
        q->next=first;
        first=q;
    }
    else
    {
        for(int i=0;i<pos-1; i++){
            p=p->next;
        }
        q->next=p->next;
        p->next=q;
    }
}

void SortedInsert(struct node *p , int x){

    struct node *t,*q=NULL;
    t=(struct node *) malloc (sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=t;
    }
    else{
        while( p->data <x && p){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
           t->next=q->next;
           q->next=t;
        }
    }
}


void deletedDuplicate(struct node * p){

    struct node * q;
    p=first;
    q=first->next;

    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }






}

int Delete( struct node *p, int pos){

    struct node *q=NULL;
    int x=-1;

    if(pos<1 || pos>count(p))
        return -1;


    if(pos==1){
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    }
    else{
        p=first;
        q=NULL;
        for(int i=0;i<pos-1 ;i++){
            q=p;
            p=p->next;
        }
        if(p){
            x=p->data;
            q->next=p->next;
            delete p;
            return x;
        }
    }
}

bool isSorted(struct node *p ){
    int x=-32768;
    p=first;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}


void revers(struct node *p){
    int *Arr= new int[count(p)];
    p=first;
    int i=0;
    while(p!=NULL){
        Arr[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p!=NULL){
        p->data=Arr[i];
        p=p->next;
        i--;
    }
}

void revers_1(struct node *p){
    struct node *q,*r;
    p=first;
    q=NULL;
    r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void merge(struct node *p , struct node *q){
    struct node * last = NULL;
    if(first->data<second->data){
        third=last=first;
        first=first->next;
        last->next=NULL;
    }
    else{
        third=last=second;
        second=second->next;
        last->next=NULL;
    }
    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else{
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first!=NULL)last->next=first;
    else last->next=second;

}

bool isLoop(struct node *f){
    struct node *q ,*p;
    q=p=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(q&&p && p!=q);
    if(q==p)return true;
    else false;
}

int main()
{
    /*
    cout << "Hello world!" << endl;
    int A[]={2,3,5,7,95,1,6,7,33};
    creat(A,9);
    display(first);
    printf("\n");
    Rdisplay(first);
    printf("\n");
    printf("size: %d",count(first));
    printf("\n");
    printf("R-size: %d",Rcount(first));
    printf("\n");
    printf("total: %d",Sum(first));
    printf("\n");
    printf("R-total: %d",RSum(first));
    printf("\n");
    printf("Max: %d",max(first));
    printf("\n");
    printf("Rmax: %d",Rmax(first));
    printf("\n");
    search(first,95);
    display(first);
    printf("\n");
    insert(first,9,65);
    display(first);
*/

/*
    insert(first,0,0);
    display(first);
    printf("\n");
    insert(first,1,5);
    display(first);
    printf("\n");
    insert(first,2,10);
    display(first);
    printf("\n");
    insert(first,3,15);
    display(first);
    printf("\n");
    insert(first,4,20);
    display(first);
    printf("\n");
    insert(first,5,25);
    display(first);
    printf("\n");
    SortedInsert(first,17);
    display(first);
    printf("\n");
    printf("%d deleted \n" ,Delete(first,5));
    display(first);

    if(isSorted(first)){
        printf("\nyour linked list is sorted\n" );
    }
    else{
        printf("\nyour linked list is unsorted\n" );
    }
    insert(first,5,2);
    insert(first,5,2);
    insert(first,5,2);
    insert(first,5,2);
    insert(first,5,2);
    insert(first,5,2);

    if(isSorted(first)){
        printf("\nyour linked list is sorted\n" );
    }
    else{
        printf("\nyour linked list is unsorted\n" );
    }
    printf("\n\n");

        display(first);
printf("\n\n");
    deletedDuplicate(first);
    display(first);

    */

/*
    int A[]={10,20,30,40};
    creat(A,4);
    display(first);
    printf("\n\n");
    revers(first);
    display(first);
    printf("\n\n");
    revers_1(first);
    display(first);
    printf("\n\n");
*/
/*

    int A[]={10,20,30,40};
    creat(A,4);

    int B[]={15,25,35,45};
    creat_2(B,4);

    cout<<endl;
    merge(first,second);
    display(third);
 */

    struct node *t1,*t2;

    int A[]={10,20,30,40,50};
    creat(A,5);

    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    cout<<endl;
    cout<<isLoop(first);






    return 0;
}
