#include <iostream>
using namespace std;

int toplama(int a, int b) {   //PASS BY VALUE 
    int toplam;               //BUrada yapacağımız parametler üzerindeki  değişiklikler sadece bu fonk skobu içinde  kaılır ve maine iletilmez 
    toplam = a + b;
    return toplam;
}
void swapp(int* x, int* y) {  //CALL BY ADRESS
    int temp;                 //BURADA POINTER TANIMLAMAMIZ GEREKKKİYOR ÇÜNKÜ ACTUAL PARAMETLERIN ADRESLERİNİ SWAPP FONKUNA 
    temp = *x;                // GONDERİYORUZ ADRESLERDE İŞLEM YAPABİLMEMİZ İÇİN OİNTERA İHTİYACIMIZ VAR 
    *x = *y;                  // ADRESSLERDE YAPACAĞIMIZ TÜM İŞLEMLER ACTUAL PARAMETLERE DE İŞLER  
    *y = temp;
}

void swapp(int& x, int& y) { //CALL BY REFERERNCE
    int temp;                //CALLL BY REFERENCE EN KONFORLUSUDUR BURADE SADECE & ISARETİ KULLANMANMIZ YETERLİ OLACAKTIR
    temp = x;                //REFERENCE SAYESİNDE BİZ FORMAL PARAMETLERİ ACTUAL PARAMETLERİN NİCKNAME YAPARIZ
    x = y;                   //KISACA BU İKİ PARAMETLEYİ BİR YAPARIZ BOYLECE HERHANGİ BİR DEĞİŞKLİK DİREK ACTUAL PARAMETLERE İŞŞLER
    y = temp;
}
int main()
{
    int num1,num2,sonuc;
    num1 = 12;
    num2 = 14;
    sonuc = toplama(num1, num2);
    cout << sonuc << endl;

    int a, b;
    a = 10;
    b = 20;
    swapp(&a, &b);  //BURADA ADRESS GONDERMEK ZORUNDAYIZ
    cout << a << "---" << b << endl;

    int r1, r2;
    r1 = 20;
    r2 = 30;
    swapp(r1, r2);
    cout << r1 << "---" << r2 << endl;

    
}
