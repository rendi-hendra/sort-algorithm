#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    // Menghitung ukuran dari dua subarray yang akan digabungkan
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Membuat array sementara untuk menampung subarray kiri dan kanan
    vector<int> L(n1);
    vector<int> R(n2);
    
    // Menyalin data ke array sementara L[] dan R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
        
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // Menggabungkan array sementara kembali ke array asli
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Menyalin sisa elemen dari L[], jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Menyalin sisa elemen dari R[], jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int begin, int end) {
    if (begin < end) {
        // Mencari titik tengah untuk membagi array menjadi dua bagian
        int mid = begin + (end - begin) / 2;
        
        // Memanggil mergeSort untuk setiap bagian
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        
        // Menggabungkan dua bagian yang telah diurutkan
        merge(arr, begin, mid, end);
    }
}

void printArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    string input;

    cout << "Masukkan angka (Setiap memasukan angka tambahkan Spasi. Enter untuk selesai): ";

    // Membaca satu baris input
    getline(cin, input);

    // Menggunakan stringstream untuk memisahkan angka-angka
    stringstream ss(input);
    int number;

    while (ss >> number) {
        arr.push_back(number); // Menambahkan angka ke arr
    }

    // Menampilkan isi array
    cout << "Isi array: ";
    printArray(arr);

    // Mengurutkan array
    mergeSort(arr, 0, arr.size() - 1);

    // Menampilkan array yang sudah diurutkan
    cout << "Array yang sudah diurutkan: ";
    printArray(arr);

    return 0;
}

