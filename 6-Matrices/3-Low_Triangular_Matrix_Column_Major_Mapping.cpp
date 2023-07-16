#include <iostream>
using namespace std;

struct Matrix{
    int *Arr;
    int n;
};

void setMatrix(struct Matrix *m,int i,int j,int x){ 
    if(i>=j){
        m->Arr[((i*(i-1))/2)+j-1]=x;
    }
}
int getMatrix(struct Matrix *m, int i,int j){
    if(i>=j)
        return m->Arr[((i*(i-1))/2)+j-1];
    else
        return 0;
}

void display(struct Matrix *m){
    for(int i=1;i<m->n+1;i++){
        for(int j=1;j<m->n+1;j++){
            if(i>=j){
                cout<<m->Arr[((i*(i-1))/2)+j-1];
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

    setMatrix(&m,1,1,1);setMatrix(&m,2,1,4);setMatrix(&m,2,2,2);setMatrix(&m,3,1,1);setMatrix(&m,3,2,6);    
    setMatrix(&m,3,3,3);setMatrix(&m,4,1,9);setMatrix(&m,4,2,4);setMatrix(&m,4,3,3);setMatrix(&m,4,4,9);
    setMatrix(&m,5,1,5);setMatrix(&m,5,2,7);setMatrix(&m,5,3,6);setMatrix(&m,5,4,7);setMatrix(&m,5,5,5);
    display(&m);
    cout<<getMatrix(&m,5,5);

}