#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * next;
}*head;

void creat(int A[],int n){
    int i;
    struct node *t,* last;
    head=(struct node *) malloc(sizeof(struct node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++){
        t=(struct node *) malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct node *h){
    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
    printf("\n");
}

void Rdisplay(struct node *h){
    static flag =0;
    if(h!=head || flag==0){
        flag=1;
        printf("%d ",h->data);
        Rdisplay(h->next);
    }
    flag =0;

}

int length(struct node *p)
{
    int len=0;
    do{
        len++;
        p=p->next;

    }while(p!=head);
    return len;
}

void insert(struct node *p,int ind,int x){
    struct node *t,*last,q;
    t=head;
    if(ind > length(head) || ind < 0){
        return;
    }

    if(ind ==0){
        t=(struct node* )malloc (sizeof(struct node ));
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }
        else{
            while(p->next!= head)p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }

    }
    else{
        for(int i=0;i<ind-1;i++)p=p->next;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}

int delete(struct node *p, int index){
    struct node *t;
    int x;
    if(index < 0 || index>length(head))return;
    if(index==1){
        while(p->next!=head)p=p->next;
        x=head->data;
        if(p==head){
            free(head);
            head=NULL;
        }
        else{
        p->next=head->next;
        free(head);
        head=p->next;
        }
        }
    else{
        for(int i=0;i<index-2;i++)
        {
            t=p;
            p=p->next;
        }
        t->next=p->next;
        x=p->data;
        free(p);
    }
    return x;

}

int main()
{
    int A[]={1,2,3,4,5,6};
    creat(A,6);
    display(head);
   // Rdisplay(head);
    // printf("%d",length(head));
   // insert(head,3,7);
    delete(head,1);
    display(head);
    delete(head,1);
    display(head);
    delete(head,1);
    display(head);
    delete(head,1);
    display(head);
    delete(head,1);
    display(head);

    printf(" %d silinen değer",delete(head,1));
    display(head);

    return 0;
}
