#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r=a;   // referance ataması bu şekilde olur eğer sadece int &r yaparsak hata alırız
    cout << r << "---" << &r << endl; //eğer sadece r yaparsak direk a nın değerini dondürür eğer &r yaparsak a nın  adresini döndürür
    int b = 13;
    r = b;
    cout << r << "---" << a;

    
}

//referance ı biz parameter passingte kullanacağız 
//reference bir nickname gibidir bu yüzden herhangi biirinde yapılacak değişiklik diğerindede yapılmış olur
// reference bir pointer değildir
//reference sadece bir değerin nickname ı olabilir