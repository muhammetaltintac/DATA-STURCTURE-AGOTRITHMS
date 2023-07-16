#include <iostream>
using namespace std;

struct Matrix{
    int *Arr;
    int n;
};

void setMatrix(struct Matrix *m,int i,int j,int x){ 
    if(j>=i){
        m->Arr[ (j*(j-1)/2)+ (i-1)]=x;
    }
    
}
int getMatrix(struct Matrix *m, int i,int j){
    if(j>=i)
        return m->Arr[ (j*(j-1)/2)+ (i-1)];
    else
        return 0;
}

void display(struct Matrix *m){
    for(int i=1;i<m->n+1;i++){
        for(int j=1;j<m->n+1;j++){
            if(j>=i){
                cout<<m->Arr[ (j*(j-1)/2)+ (i-1)];
            }
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }

}

int main(){
    Matrix m;
    m.n=5;
    m.Arr=new int[(m.n*(m.n+1)/2)];  // işimize yarayan veri boyutu

    setMatrix(&m,1,1,4);setMatrix(&m,1,2,8);setMatrix(&m,1,3,9);setMatrix(&m,1,4,4);setMatrix(&m,1,5,8);    
    setMatrix(&m,2,2,2);setMatrix(&m,2,3,9);setMatrix(&m,2,4,4);setMatrix(&m,2,5,3);setMatrix(&m,3,3,9);
    setMatrix(&m,3,4,5);setMatrix(&m,3,5,7);setMatrix(&m,4,4,6);setMatrix(&m,4,5,7);setMatrix(&m,5,5,5);
    display(&m);
    cout<<getMatrix(&m,3,5);

}