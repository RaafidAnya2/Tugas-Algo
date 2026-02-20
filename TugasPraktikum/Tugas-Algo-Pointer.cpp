#include <iostream>
using namespace std;

//Tugas 1 Algo Struktur Data
//Buat array integer dengan panjang bebas dan nilai bebas!
//Cetak semua elemen dalam array menggunakan pointer tanpa index
//Cari nilai maximum dan minimum dari array tersebut tanpa index
//cari jumlah dan rata-rata array tersebut tanpa index
int main() {
    int n;  
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    int angka[n]; 
    int *ptr = angka; 
    
    // user menginput nilai
    cout << "Masukkan nilai array:\n";
    for(int i = 0; i < n; i++) {
        cin >> *ptr;
        ptr++;       
    }

    // balikin array ke awal
    ptr = angka;
    int max = *ptr;
    int min = *ptr;
    int sum = 0;

    cout << "Isi array: " << endl;

    //proses pointer tanpa index
    for(int i = 0; i < n; i++) {
        cout << *ptr << " ";

        if(*ptr > max)
            max = *ptr;

        if(*ptr < min)
            min = *ptr;
            
        sum += *ptr;
        ptr++;
    }

    float avg = (float)sum / n;

    // Output 
    cout << "\nNilai maksimum = " << max << endl;
    cout << "Nilai minimum = " << min << endl;
    cout << "Jumlah = " << sum << endl;
    cout << "Rata-rata = " << avg << endl;

    return 0;
}