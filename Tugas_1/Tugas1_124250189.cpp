#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Produk{
    char nama[50];
    float harga;
    char kategori[30];
    int stok;
};

Produk arr[100];
int jumlah = 0;

void loadFile(){
    FILE *file = fopen("lelele.csv","r");
    if(file == NULL){
        return;
    }

    while(fscanf(file," %[^,],%f,%[^,],%d",
        arr[jumlah].nama,
        &arr[jumlah].harga,
        arr[jumlah].kategori,
        &arr[jumlah].stok) != EOF){
        jumlah++;
    }
    fclose(file);
}

void saveFile(){
    FILE *file = fopen("lelele.csv","w");
    for(int i=0;i<jumlah;i++){
        fprintf(file,"%s,%.1f,%s,%d",
        arr[i].nama,
        arr[i].harga,
        arr[i].kategori,
        arr[i].stok);
    }
    fclose(file);
}

void tambahProduk(){
    cout<<"Nama produk : "<<endl;
    cin.ignore();
    cin.getline(arr[jumlah].nama,50);
    cout<<"Harga : "<<endl;
    cin>>arr[jumlah].harga;

    do{
        cout<<"Kategori (makanan/minuman) : "<<endl;
        cin>>arr[jumlah].kategori;
        if(strcmp(arr[jumlah].kategori,"makanan")!=0 &&
           strcmp(arr[jumlah].kategori,"minuman")!=0){
            cout<<"Kategorinya harus makanan atau minuman"<<endl;
        }

    }while(strcmp(arr[jumlah].kategori,"makanan")!=0 &&
           strcmp(arr[jumlah].kategori,"minuman")!=0);

			cout<<"Stok : "<<endl;
			cin>>arr[jumlah].stok;
			jumlah++;
			saveFile();
			cout<<"Produk berhasil ditambahkan"<<endl;
}

void tampilProduk(){
    if(jumlah==0){
        cout<<"Data kosong"<<endl;
        return;
    }
    
    cout<<endl;
    cout<<"===== DAFTAR PRODUK ====="<<endl;
    cout<<"--------------------------------"<<endl;

    for(int i=0;i<jumlah;i++){
        cout<<"Nama : "<<arr[i].nama<<endl;
        cout<<"Harga : "<<arr[i].harga<<endl;
        cout<<"Kategori : "<<arr[i].kategori<<endl;
        cout<<"Stok : "<<arr[i].stok<<endl;
        cout<<"--------------------------------"<<endl;
    }
}

void bubbleSortNama(){
    for(int i=0;i<jumlah-1;i++){
        for(int j=0;j<jumlah-i-1;j++){
            if(strcmp(arr[j].nama,arr[j+1].nama)>0){
                Produk temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"Data berhasil diurutkan asendan berdasarkan nama"<<endl;
}

int partition(int low,int high){
    float pivot = arr[high].harga;
    int i = low-1;

    for(int j=low;j<high;j++){
        if(arr[j].harga > pivot){
            i++;
            Produk temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Produk temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quickSort(int low,int high){
    if(low < high){
        int pi = partition(low,high);
        quickSort(low,pi-1);
        quickSort(pi+1,high);
    }
}

void sequentialSearch(){
    char cari[50];

    cout<<"Masukkan nama produk : "<<endl;
    cin.ignore();
    cin.getline(cari,50);

    for(int i=0;i<jumlah;i++){
        if(strcmp(arr[i].nama,cari)==0){
            cout<<"Produk ditemukan!"<<endl;
            cout<<"Nama : "<<arr[i].nama<<endl;
            cout<<"Harga : "<<arr[i].harga<<endl;
            cout<<"Kategori : "<<arr[i].kategori<<endl;
            cout<<"Stok : "<<arr[i].stok<<endl;

            return;
        }
    }
    cout<<"Produk tidak ditemukan!"<<endl;
}

void binarySearch(){
    bubbleSortNama();
    char cari[50];

    cout<<"Masukkan nama produk : "<<endl;
    cin.ignore();
    cin.getline(cari,50);

    int kiri=0;
    int kanan=jumlah-1;

    while(kiri<=kanan){
        int tengah = (kiri+kanan)/2;
        int hasil = strcmp(arr[tengah].nama,cari);

        if(hasil==0){
            cout<<"Produk ditemukan!"<<endl;
            cout<<"Nama : "<<arr[tengah].nama<<endl;
            cout<<"Harga : "<<arr[tengah].harga<<endl;
            cout<<"Kategori : "<<arr[tengah].kategori<<endl;
            cout<<"Stok : "<<arr[tengah].stok<<endl;

            return;
        }
        else if(hasil<0){
            kiri = tengah+1;
        }
        else{
            kanan = tengah-1;
        }
    }
    cout<<"Produk tidak ditemukan!"<<endl;
}

int main(){
	
    int pilihan;
    loadFile();

    do{
		system("cls");
        cout<<endl;
        cout<<"===================================="<<endl;
		cout<<" SISTEM MANAJEMEN PRODUK "<<endl;
		cout<<"===================================="<<endl;
        cout<<"1. Tambah Produk"<<endl;
        cout<<"2. Tampilkan Produk"<<endl;
        cout<<"3. Urutkan Nama (Bubble Sort)"<<endl;
        cout<<"4. Urutkan Harga (Quick Sort)"<<endl;
        cout<<"5. Cari Produk (Sequential Search)"<<endl;
        cout<<"6. Cari Produk (Binary Search)"<<endl;
        cout<<"7. Keluar"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Pilih menu : "<<endl;

        cin>>pilihan;

        switch(pilihan){
            case 1:
                tambahProduk();
                system("pause");
                break;
            case 2:
                tampilProduk();
                system("pause");
                break;
            case 3:
                bubbleSortNama();
                tampilProduk();
                system("pause");
                break;
            case 4:
                quickSort(0,jumlah-1);
                cout<<"Data diurutkan berdasarkan harga"<<endl;
                tampilProduk();
                system("pause");
                break;
            case 5:
                sequentialSearch();
                system("pause");
                break;
            case 6:
                binarySearch();
                system("pause");
                break;
        }

    }while(pilihan!=7);
    cout<<"Program selesai"<<endl;

}
