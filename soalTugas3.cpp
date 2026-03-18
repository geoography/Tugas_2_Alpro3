#include <iostream>
using namespace std;

int main() {
    float ip;
    long long gaji;
    cout << "Input IP: "; // input IP 
    cin >> ip;
    cout << "Input gaji orang tua: Rp"; // input gaji orang tua
    cin >> gaji;

    if (ip >= 3.5) { // jika IP >= 3.5 sudah pasti kategori 4
        cout << "Kategori 4";
    } 
    else if (gaji < 1000000 && ip < 3.5) { // jika gaji orang tua lebih kecil dari 1jt dan ip di bawah 3.5 berhak mendapat beasiswa kategori 1
        cout << "Kategori 1";
    } 
    else if (gaji >= 1000000 && gaji <= 5000000 && ip < 3.5) { // rentang gaji orang tua dari 1jt sampai 5jt dan ip di bawah 3.5 berhak mendapat beasiswa kategori 2 atau 3
        if (ip >= 2.0) { 
            cout << "Kategori 3"; // ip lebih besar sama dengan 2 berhak mendapat beasiswa kategori 3
        } else {
            cout << "Kategori 2"; // ip di bawah 2 berhak mendapat beasiswa kategori 2
        }
    } 
    else { // selain dari semua syarat di atas tidak berhak mendapat beasiswa
        cout << "Tidak berhak mendapatkan beasiswa";
    }

    return 0;
}
