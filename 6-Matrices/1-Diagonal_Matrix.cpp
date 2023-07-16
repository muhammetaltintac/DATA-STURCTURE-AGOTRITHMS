#include <iostream>
#include <time.h>

using namespace std;

void setDiagonalMatrix(int Arr[],int i,int j,int x){
    if(i==j){
        Arr[i-1]=x;
    }
}

int getDiagonalMatrix(int Arr[],int i, int j){
    if(i==j){
        return Arr[i-1];
    }
    else{
        return 0;
    }
}

void display(int Arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                cout<<Arr[i];
            }
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }

}

int main(){
    int Array[5];
    setDiagonalMatrix(Array,1,1,3);   
    setDiagonalMatrix(Array,2,2,5);
    setDiagonalMatrix(Array,3,3,1);
    setDiagonalMatrix(Array,4,4,8);
    setDiagonalMatrix(Array,5,5,5);
    cout<<getDiagonalMatrix(Array,2,2)<<endl;
    display(Array,5);



}