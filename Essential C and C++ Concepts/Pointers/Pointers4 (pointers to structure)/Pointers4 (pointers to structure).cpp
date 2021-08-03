#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct dikdortgen { //c++ için 
    int boy;
    int en;
}d;
struct kare { //c için
    int boy;
    int en;
};

int main()
{
    struct dikdortgen* p;
    p = &d;
    (*p).boy = 15;
     p->en = 10;  //c++ struct içindeki üyelere bu şekilde erişebiliriz

     struct kare* k;
     k = (struct kare*)malloc(sizeof(struct kare));
     k->boy = 15;
     (*k).en = 10;

     //not structlarda pointer dinamik bellekle yapılır
}

