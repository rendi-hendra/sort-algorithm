#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void countingSort(vector<int>& arr) {
    // Mencari elemen maksimum dan minimum dalam array
    int maxElement = arr[0];
    int minElement = arr[0];

    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > maxElement)
            maxElement = arr[i];
        if (arr[i] < minElement)
            minElement = arr[i];
    }

    // Menghitung rentang nilai dalam array
    int range = maxElement - minElement + 1;
    
    // Membuat array count dan output
    vector<int> count(range, 0);
    vector<int> output(arr.size());

    // Menghitung jumlah kemunculan setiap elemen dalam array
    for (size_t i = 0; i < arr.size(); i++)
        count[arr[i] - minElement]++;

    // Mengubah count[i] sehingga count[i] berisi posisi elemen ini dalam array output
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Membuat array output
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    // Menyalin elemen yang sudah diurutkan dari array output ke array asli
    for (size_t i = 0; i < arr.size(); i++)
        arr[i] = output[i];
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
        arr.push_back(number); // Menambahkan angka ke vector
    }

    // Menampilkan isi vector
    cout << "Isi array: ";
    printArray(arr);

    // Mengurutkan array
    countingSort(arr);

    // Menampilkan array yang sudah diurutkan
    cout << "Array yang sudah diurutkan: ";
    printArray(arr);

    return 0;
}

