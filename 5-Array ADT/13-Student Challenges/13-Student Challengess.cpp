#include <iostream>
using namespace std;
struct Array {
    int A[10];
    int uzunluk;
    int boyut;
};
int Sum(Array Arr) {
    int s = 0;
    for (int i = 0; i < Arr.uzunluk; i++)
    {
        s = s + Arr.A[i];
    }
    return s;
}
void SingleMissingElementSortedArray(Array Arr) {
    int n, formul;
    n = Arr.A[Arr.uzunluk - 1];
    formul = n * (n + 1) / 2;
    cout << "Missing element is: " << formul - Sum(Arr) << endl;
}
void SingleMissingElementSortedArray2(Array Arr) {
    int fark, n = 0;
    fark = Arr.A[0];
    n = Arr.A[Arr.uzunluk - 1] - fark;
    for (int i = 0; i < Arr.uzunluk; i++) {
        if (fark != Arr.A[i] - i) {
            while (fark < Arr.A[i] - i) {
                cout << "Missing element is: " << i + fark << endl;
                fark++;
            }

        }

    }
    cout << endl;
}
void SingleMissingElementUnsortedArray(Array Arr) {
    int max = 0, * p;

    for (int i = 0; i < Arr.uzunluk; i++) {
        if (max <= Arr.A[i])
            max = Arr.A[i];
    }

    p = new int[max];
    for (int i = 0; i < Arr.uzunluk; i++) {
        int x = 0;
        x = Arr.A[i];
        p[x] = 1;
    }
    for (int i = 0; i < max; i++) {
        if (p[i] != 1 && i != 0)
            cout << "  " << i;
    }
    cout << endl;


}
void FindingDuplicateElements(Array Arr) {
    //1,2,6,6,7,8,11,11,12,12
    int kontrol = 0;
    for (int i = 0; i < Arr.uzunluk-1; i++) {
        if (Arr.A[i] == Arr.A[i + 1] && Arr.A[i] != kontrol)
        {
            cout << " " << Arr.A[i];
            kontrol = Arr.A[i];
        }
    }
    cout << endl;
}
void FindingDuplicateElements2(Array Arr) {
    for (int i = 0; i < Arr.uzunluk - 1; i++) {
        if (Arr.A[i] == Arr.A[i + 1]) {
            int j = i;
            while (Arr.A[i] == Arr.A[j])j++;
            cout << Arr.A[i] << " duplicated " << j - i << " times" << endl;
            i = j - 1;
        }
    }
    cout << endl;
}
void FindingDuplicateElements3(Array Arr) {

    int* p = new int[Arr.A[Arr.uzunluk - 1]];

    for (int i = 0; i <= Arr.A[Arr.uzunluk - 1]; i++)
        p[i] = 0;
    for (int i = 0; i < Arr.uzunluk; i++) {
        p[Arr.A[i]]++;
    }
    cout << endl;
    for (int i = 0; i <= Arr.A[Arr.uzunluk - 1]; i++) {
        if (p[i] > 1)
            cout << i << " duplicated " << p[i] << " times " << endl;
    }
    cout << endl;

}
void FindingDuplicateElements4(Array Arr) {
    int max=0;
    for (int i = 0; i < Arr.uzunluk; i++) {
        if (max <= Arr.A[i])
            max = Arr.A[i];
    }
    int* p = new int[max];
    for (int i = 0; i <= max; i++)
        p[i] = 0;
    for (int i = 0; i < Arr.uzunluk; i++) {
        p[Arr.A[i]]++;
    }
    cout << endl;
    for (int i = 0; i <=max; i++) {
        if (p[i] > 1)
            cout << i << " duplicated " << p[i] << " times " << endl;
    }
    cout << endl;
}
void FindingDuplicateElements5(Array Arr) {
    int sayac ;
    for (int i = 0; i < Arr.uzunluk-1; i++) {
       
        if (Arr.A[i] > 0) {
            sayac = 1;
            for (int j = i + 1; j < Arr.uzunluk; j++) {
                if (Arr.A[i] == Arr.A[j]) {
                    sayac++;
                    Arr.A[j] = -1;
                }
            }
            if (sayac > 1) {
                cout << Arr.A[i] << " duplicated " << sayac << " times " << endl;
            }
            }     
    }
    cout << endl;
}
void FindingApairOfElements(Array Arr, int sum) {
    for (int i = 0; i < Arr.uzunluk - 1; i++) {
        for (int j = i + 1; j < Arr.uzunluk; j++) {
            if (Arr.A[i] + Arr.A[j] == sum)
                cout << Arr.A[i] << " + " << Arr.A[j] << " = " << sum<<endl;
        }
    }
    cout << endl;
}
void FindingApairOfElements2(Array Arr, int sum) {
    int max = 0;
    for (int i = 0; i < Arr.uzunluk; i++) {
        if (max <= Arr.A[i])
            max = Arr.A[i];
    }
    int* p = new int[max];
    for (int i = 0; i <= max; i++)
        p[i] = 0;
    for (int i = 0; i < Arr.uzunluk; i++) {
        p[Arr.A[i]]++;
    }
    for (int i = 0; i < Arr.uzunluk; i++) {
        if(sum-Arr.A[i]>=0 && p[sum-Arr.A[i]]==1)
            cout << Arr.A[i] << " + " << sum-Arr.A[i] << " = " << sum << endl;
        p[Arr.A[i]]++;
    }
    cout << endl;
}
void FindingApairOfElements3(Array Arr, int sum) {
    int i = 0;
    int j = Arr.uzunluk - 1;
    while (i < j)
    {
        if(Arr.A[i]+Arr.A[j]==sum){
            cout << Arr.A[i] << " + " << Arr.A[j] << " = " << sum << endl;
            i++;
            j--;
        }
        else if (Arr.A[i] + Arr.A[j] < sum) {
            i++;
        }
        else {
            j--;
        }

    }
    cout << endl;
}
void FindMinAndMaxElemnts(Array Arr) {
    int min, max;
    min = max = Arr.A[0];
    for (int i = 1; i < Arr.uzunluk; i++) {
        if (Arr.A[i] < min)
            min = Arr.A[i];
        else if (Arr.A[i] > max) 
            max = Arr.A[i];
    }
    cout << "Min: " << min << " Max: " << max << endl;
}
int main()
{
    Array Arr = { {1,2,3,4,5,7,8,9,10,11},10,10 };
    Array Arr1 = { {6,7,9,12,13,15,16,18,20,22},10,10 };
    Array Arr2 = { {2,9,4,3,8,7,10,15,6,11} ,10,10 };
    Array Arr3 = { {1,2,6,6,7,8,11,11,12,12} ,10,10 };
    Array Arr4 = { {11,22,22,6,17,17,11,11,12,12} ,10,10 };
    Array Arr5 = { {11,23,22,6,13,14,10,5,12,2} ,10,10 };
    SingleMissingElementSortedArray(Arr);
    SingleMissingElementSortedArray2(Arr1);
    SingleMissingElementUnsortedArray(Arr2);
    FindingDuplicateElements(Arr3);
    FindingDuplicateElements2(Arr3);
    FindingDuplicateElements3(Arr3);
    FindingDuplicateElements4(Arr4);
    FindingDuplicateElements5(Arr4);
    FindingApairOfElements(Arr5, 17);
    FindingApairOfElements2(Arr5, 19);
    FindingApairOfElements3(Arr, 19);
    FindMinAndMaxElemnts(Arr);
    FindMinAndMaxElemnts(Arr1);
    FindMinAndMaxElemnts(Arr2);
    FindMinAndMaxElemnts(Arr3);
    FindMinAndMaxElemnts(Arr4);
    FindMinAndMaxElemnts(Arr5);
}
