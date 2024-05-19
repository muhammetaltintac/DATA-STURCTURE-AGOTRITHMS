#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *s;
};

void creat(struct stack *st){
    printf("enter size of stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *) malloc (st->size * sizeof(int));

}
void display(struct stack st){
    for(int i=st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    }
    printf("\n");
}

void push(struct stack *st,int x){
        if( st->top == st->size-1 ){
            printf("stack is full\n");
        }
        else{
            st->top++;
            st->s[st->top]=x;
        }
}
int pop(struct stack *st){
    int x=-1;
    if(st->top < 0){
        printf("stack is undefined");
        return -1;
    }
    else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
int peak(struct stack st,int pos){
    if((st.top-pos+1)<0){
        printf("%d is  ivvalid positon",pos);
    }
    else{
        return st.s[st.top-pos+1];
    }
}

void isFull(struct stack st){
    if(st.top==st.size-1)printf("stack is full\n");
    else printf("stack is  not full\n");
}
void isEmpty(struct stack st){
    if(st.top==-1)printf("stack is empty\n");
    else printf("stack is  not empty\n");
}
int main()
{
    struct stack st;
    creat(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    isFull(st);
    printf("position value is %d \n",peak(st,1));

    display(st);
    printf("%d was deleted\n",pop(&st));
    printf("%d was deleted\n",pop(&st));
    printf("%d was deleted\n",pop(&st));
    printf("%d was deleted\n",pop(&st));
    printf("%d was deleted\n",pop(&st));
    isEmpty(st);


    return 0;
}
