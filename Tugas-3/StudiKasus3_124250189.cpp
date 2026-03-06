#include <iostream>
using namespace std;

void tampildata(string array[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void bubblesort(string array[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(array[j] > array[j+1])
			{
				string temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void quick_sort(string array[], int awal, int akhir)
{
	int low = awal, high = akhir;
	string pivot = array[(awal + akhir) / 2];

	do
	{
		while(array[low] > pivot)
			low++;

		while(array[high] < pivot)
			high--;

		if(low <= high)
		{
			swap(array[low], array[high]);
			low++;
			high--;
		}

	} while(low <= high);

	if(awal < high)
		quick_sort(array, awal, high);

	if(low < akhir)
		quick_sort(array, low, akhir);
}

int main()
{
	int n, pilihan;

	cout << "Masukkan jumlah mahasiswa: ";
	cin >> n;

	string nama[n];

	cout << "Masukkan nama mahasiswa:" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "Nama ke-" << i+1 << ": ";
		cin >> nama[i];
	}

	cout << "\nData sebelum diurutkan: " << endl;
	tampildata(nama, n);

	cout << "\nMenu Pengurutan:" << endl;
	cout << "1. Ascending - Bubble Sort" << endl;
	cout << "2. Descending - Quick Sort" << endl;
	cout << "Pilih metode: ";
	cin >> pilihan;

	if(pilihan == 1)
	{
		bubblesort(nama, n);
		cout << "\nData setelah diurutkan Ascending (Bubble Sort):" << endl;
		tampildata(nama, n);
	}
	else if(pilihan == 2)
	{
		quick_sort(nama, 0, n-1);
		cout << "\nData setelah diurutkan Descending (Quick Sort):" << endl;
		tampildata(nama, n);
	}
	else
	{
		cout << "Pilihan tidak tersedia." << endl;
	}

	return 0;
}
