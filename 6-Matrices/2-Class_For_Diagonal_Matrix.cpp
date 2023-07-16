#include <iostream>

using namespace std;

class Diagonal{
private:
    int n;
    int *Arr;
public:
    Diagonal(int n){
        this->n=n;
        Arr=new int[n];
    }
    void setDiagonal(int i,int j,int x);
    int getDiagonal(int i,int j);
    void display();
    ~Diagonal();
};

int main(){
    Diagonal Matrix(5);
    Matrix.setDiagonal(1,1,2); Matrix.setDiagonal(2,2,3); Matrix.setDiagonal(3,3,8); Matrix.setDiagonal(4,4,5);Matrix.setDiagonal(5,5,7);
    Matrix.setDiagonal(1,1,9);
    Matrix.display();
    cout<<Matrix.getDiagonal(3,3);



}

void Diagonal::setDiagonal(int i,int j,int x){
    if(i==j){
        Arr[i-1]=x;
    }
}

int Diagonal::getDiagonal(int i,int j){
    if(i==j){
        return Arr[i-1];
    }
    else{
        return 0;
    }
}
void Diagonal::display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                cout<<Arr[i-1];
            }
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }
}
Diagonal::~Diagonal(){
    delete []Arr;
}
