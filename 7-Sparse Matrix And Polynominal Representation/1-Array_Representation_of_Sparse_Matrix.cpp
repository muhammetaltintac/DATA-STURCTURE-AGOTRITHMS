#include <iostream>
using namespace std;

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int n;
    int m;
    int num;
    struct Element *e;
};

void create(struct Sparse *s){
    int i;
    cout<<"Boyut Giriniz:";
    cin>>s->m>>s->n;
    cout<<"Element sayisini giriniz";
    cin>>s->num;

    s->e = new Element[s->num];

    cout<<"Butun elemanları giriniz: ";
    for(int i=0;i<s->num;i++){
        cin>>s->e[i].i>>s->e[i].j>>s->e[i].x;
    }
}

void display(struct Sparse s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(i==s.e[k].i && j==s.e[k].j){
                cout<<s.e[k++].x;
            }
            else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
}

int main(){
    struct Sparse s;
    create(&s);
    display(s);
}