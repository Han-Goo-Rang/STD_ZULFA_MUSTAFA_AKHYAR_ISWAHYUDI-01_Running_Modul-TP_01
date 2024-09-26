
#include <iostream>
using namespace std;

//Inisiasi float-nya
int main() {
   float angka1, angka2;
   cout << "Input angka1 : " ;
   cin >> angka1;

   cout << "Input angka2 : " ;
   cin >> angka2;


   //Proses rumus
   float jmlh = angka1 + angka2;
   float kurang = angka1 - angka2;
   float kali = angka1 * angka2;
   float bagi = angka1 / angka2;

   //Hasil
   if (angka2 != 0) {
    bagi = angka1 / angka2;
    cout << "Hasil baginya = " << bagi << endl;
   } else {
       cout << "ga bisa kalo pembaginya nol (0)" << endl;
   }

   cout << "Hasil jumlah = " << jmlh << endl;
   cout << "Hasil kurang = " << kurang << endl;
   cout << "Hasil kali = " << kali << endl;

   return 0;
}
