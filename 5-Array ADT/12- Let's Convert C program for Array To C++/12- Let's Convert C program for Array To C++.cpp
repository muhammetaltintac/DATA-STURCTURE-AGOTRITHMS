#include "12-Let's Convert C Program for Array To C++.h"


int main() {
    Array* Arr1,*Arr3;
    int secim, byt;
    int eleman, index,x;
    printf("Dizi icin boyut giriniz: ");
    std::cin >> byt;
    Arr1 = new Array[byt];
    Array* Arr2 = new Array[5];
    Arr2->Append(5); Arr2->Append(4); Arr2->Append(-2); Arr2->Append(-25); Arr2->Append(8); Arr2->Append(3);
    do {
        cout << "\n\nMenu" << endl;
        cout << "1.  Sirali Ekleme" << endl;
        cout << "2.  Indexe Gore Ekleme" << endl;
        cout << "3.  Silme" << endl;
        cout << "4.  Arama " << endl;
        cout << "5.  Transposition Arama" << endl;
        cout << "6.  MoveToHead Arama" << endl;
        cout << "7.  Binary Arama " << endl;
        cout << "8.  Ekrana Bastirma" << endl;
        cout << "9.  Alma" << endl;
        cout << "10  Kurma" << endl;
        cout << "11  Max" << endl;
        cout << "12  Min" << endl;
        cout << "13. Toplam" << endl;
        cout << "14. Baslangic Indexine Gore Toplam" << endl;
        cout << "15. Ortalama" << endl;
        cout << "16. Ters Cevirme" << endl;
        cout << "17. Ters Cevirme 2" << endl;
        cout << "18. Sola Kaydırma " << endl;
        cout << "19. Bastan Sona Kaydirma" << endl;
        cout << "20. Saga Kaydirma" << endl;
        cout << "21. Sondan Basa Kaydirma " << endl;
        cout << "22. Sirali mi Kontrolu" << endl;
        cout << "23. Negatif Sola Pozitif Saga " << endl;
        cout << "24. Dizi Birlestirme" << endl;
        cout << "25. Birlesim " << endl;
        cout << "26. Birlesim Sirasiz " << endl;
        cout << "27. Kesisim " << endl;
        cout << "28. Kesisim Sirasiz " << endl;
        cout << "29. Fark " << endl;
        cout << "30. Fark Sirasiz " << endl;
        cout << "Seciminizi yapiniz: ";
        std::cin >> secim;
        switch (secim)
        {
        case 1:

            printf("Eleman giriniz: ");
            cin >> eleman;
            Arr1->Append(eleman);
            Arr1->Display();
            break;
        case 2:
            cout << "index ve eleman giriniz: ";
            cin >> index >> eleman;
            Arr1->Insert(eleman);
            Arr1->Display();
            break;
        case 3:
            printf("Silmek istedigininz Indexi giriniz: ");
            int index; std::cin >> index;
            eleman = Arr1->Delete(index);
            printf("Silinen eleman: %d\n", eleman);
            Arr1->Display();
            break;
        case 4:
            cout << "Aramak istediginiz elemani giriniz: ";
            cin >> eleman;
            index = Arr1->LinearSearch(eleman);
            printf("Elemanin inedxi: %d\n", index);
            Arr1->Display();
            break;
        case 5:
            cout << "Aramak istediginiz elemani giriniz: ";
            cin >> eleman;
            index = Arr1->LinearSearchTransposition(eleman);
            printf("Elemanin inedxi: %d\n", index);
            Arr1->Display();
            break;
        case 6:
            printf("Aramak istediginiz elemani giriniz: ");
            cin >> eleman;
            index = Arr1->LinearSearchMoveToHead(eleman);
            printf("Elemanin inedxi: %d\n", index);
            Arr1->Display();
            break;
        case 7:
            printf("Aramak istediginiz elemani giriniz: ");
            cin >> eleman;
            index = Arr1->BinarySearch(eleman);
            printf("Elemanin inedxi: %d\n", index);
            Arr1->Display();
            break;
        case 8:
            Arr1->Display();
            cout << endl;
            break;
        case 9:
            cout << "Almak istediginiz indexi giriniz: ";
            cin >> index;
            cout << Arr1->get(index);
            break;
        case 10:
            cout << "Eleman ve Kurmak istediginiz indexi giriniz: ";
            cin >> index, eleman;
            Arr1->set(index, eleman);
            Arr1->Display();
            break;
        case 11:
            cout << Arr1->max();
            break;
        case 12:
            cout << Arr1->min();
            break;
        case 13:
            cout << Arr1->sum();
            break;
        case 14:
            cout << "Baslatmak istediginiz indexi giriniz: ";
            cin >> index;
            cout << Arr1->sum2(index);
            break;
        case 15:
            cout << Arr1->avg();
            break;
        case 16:
            Arr1->reverse();
            Arr1->Display();
            break;
        case 17:
            Arr1->reverse2();
            Arr1->Display();
            break;
        case 18:
            Arr1->leftShift();
            Arr1->Display();
            break;
        case 19:
            Arr1->leftRotate();
            Arr1->Display();
            break;
        case 20:
            Arr1->rightShift();
            Arr1->Display();
            break;
        case 21:
            Arr1->rightRotate();
            Arr1->Display();
            break;
        case 22:
            if (Arr1->AlgorithmIsSorted(byt))
                cout << "sirali" << endl;
            else
                cout << "Karisik" << endl;
        case 23:
            Arr1->NleftPright();
            Arr1->Display();
            break;
        case 24:
            Arr3 = Arr1->Merging(*Arr2);
            Arr3->Display();
            break;
        case 25:
            Arr3 = Arr1->UnionSorted(*Arr2);
            Arr3->Display();
            break;
        case 26:
            Arr3 = Arr1->IntensectionSorted(*Arr2);
            Arr3->Display();
            break;
        case 27:
             Arr3 = Arr1->DiffrenceSorted(*Arr2);
            Arr3->Display();
            break;
        case 28:
            Arr3 = Arr1->UnionUnsorted(*Arr2);
            Arr3->Display();
            break;
        case 29:
            Arr3 = Arr1->IntensectionUnsorted(*Arr2);
            Arr3->Display();
            break;
        case 30:
            Arr3 = Arr1->DiffrenceUnsorted(*Arr2);
            Arr3->Display();
            break;
        }
        } while (secim < 31);
    }
