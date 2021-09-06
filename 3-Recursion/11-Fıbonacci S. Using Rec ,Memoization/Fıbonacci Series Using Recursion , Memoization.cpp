#include <iostream>
using namespace std;
int fibLoop(int n) {    // fibonacci döngü ile hesaplanması
    int i, s, t0 = 0, t1 = 1;
    if (n <= 1)
        return n; // ilk iki terim için ön koşul

    for (i = 2; i <= n; i++) {
        s = t0 + t1;  //burada onceki iki terim toplanıyor
        t0 = t1;// burada kaydırma işlemi gerçekleşiyor
        t1 = s; // buradada kaydırma işemi gerçekleşiyor yani s=8 olsun burada 8 değeri t1 eşitlendi oncede t0 a t1 i atadık böylce güncel son iki değeri kaydetmiş olmud
        
    }
    return s;
}
int fibRec(int n) {
    if (n <= 1)return n;  // burada ilk iki teim için değer döndürü 0 için 0 1 için biri gönderir 
    return fibRec(n - 2) + fibRec(n - 1); // burada fonk çağrısı 0 ile 1 olana kadar fonk kendşnş çağırır ve en sonunda alttan yukarıya toplama yaprak sonucu döndürür

   //ancak bu işlemde fonk çağrısı çok yüksektir zaman açısından çok dezzavantajlıdır
}
int Array[10]; //burada arrayı tanımlamamızın nesdeni arraydeki değerleri katdetmek istememizdir 10 değeride de bize bağlı herhangi bi koşul  yok onun için
int fibMem(int n) {
  
    if (n <= 1) { //burada arrayin ilk indexine 0 ikinci indexine 1 i yerleştiriyoruz
        Array[n] = n;
        return n;
    }
    else
    {
    if (Array[n - 2] == -1)      //burada arrain o şndexi boşmu kontrolu yapıyoruz eğer boşsa değeri o indexe kaydediyoruz
        Array[n - 2] = fibMem(n - 2);
    if (Array[n - 1] == -1)   //aynı işlemi burada da yapıyoruz
        Array[n - 1] = fibMem(n - 1);
    return  Array[n - 2] + Array[n - 1];
    //burada ki amaç arayin ihtiyacımız olan yerleri doldurduktan sonra fonk çağrısı yaptığımızda gereksiz yere kendini recursive etmesin diyedir
    }
    
}
int main()
{
    cout<<"Loop: "<<fibLoop(7)<<endl;
    cout <<"Recursive: "<<fibRec(7)<<endl;
    for (int i = 0; i < 10; i++)
        Array[i] = -1;
    cout << "Memoization: "<<fibMem(7);
}

