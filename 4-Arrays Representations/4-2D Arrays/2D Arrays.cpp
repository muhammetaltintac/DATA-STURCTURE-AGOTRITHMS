#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int ArrayStatic[3][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };
    
    
    int* ArraySh[3];     //ilk önce bir pointer dizisi oluşturur ve bu dizideki pointerlardan heapte bellekten yer ayırırız
    ArraySh[0] = (int*)malloc(4 * sizeof(int));
    ArraySh[1] = (int*)malloc(4 * sizeof(int));
    ArraySh[2] = (int*)malloc(4 * sizeof(int));
   
    
    
    int** ArrayHeap;  //burada da ilk önce stacte sadece basit bir  pointer oluşturur ardından bu pointer sayesnde heapte bir poinrter dizisi oluştup o dizideki pointerlardan da yine heaplte bir bellek ayırma işlemi yaparız
    ArrayHeap = (int**)malloc(3*sizeof(int*));
    ArrayHeap[0] = (int*)malloc(4 * sizeof(int));
    ArrayHeap[1] = (int*)malloc(4 * sizeof(int));
    ArrayHeap[2] = (int*)malloc(4 * sizeof(int));
    cout << "array static: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %d ", ArrayStatic[i][j]);
        }
        printf("\n");
    }
    cout << "array sh: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %u ", ArraySh[i][j]);
        }
        printf("\n");
    }
    cout << "array heap: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %u ", ArrayHeap[i][j]);
        }
        printf("\n");
    }

}

