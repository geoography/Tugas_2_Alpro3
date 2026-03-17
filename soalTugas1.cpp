#include <iostream>
using namespace std;

// deklarasi variabel global yang digunakan
int datang, pulang;
int biaya, total_biaya = 0;

// function untuk mengecek harga moda transportasi termurah yang ada di jam tersebut, sekaligus untuk mengecek apakah ada moda transportasi pada jam yang diinput
int cek_murah(int a){
    if ((a >= 6 && a <= 8) || (a >= 15 && a <= 17)) return 0; // return harga 0 jika menggunakan bus Linus
    else if (a >= 7 && a <= 18) return 5000; // return harga 5000 jika menggunakan bus Hijau
    else return -1; // return -1 jika tidak ada moda transportasi yang tersedia pada jam yang diinput
}

// function untuk mengecek apakah jam yang diinput itu valid atau tidak
int input_jam(string pesan){
    int x;
    do{
        cout << pesan;
        cin >> x;
        if (x < 1 || x > 24) cout << "Jam tidak valid!\n";
    } while (x < 1 || x > 24);
    return x;
}

int main(){

    datang = input_jam("Jam keberangkatan (1-24): ");
    pulang = input_jam("Jam kepulangan (1-24): ");

    // keberangkatan
    biaya = cek_murah(datang);
    if (biaya != -1){
        total_biaya += biaya;
        cout << "Moda transportasi untuk keberangkatan: "
             << (biaya == 0 ? "Bus Linus" : "Bus Hijau") // ternary utk cout jenis moda transportasi yg digunakan
             << " (Rp" << biaya << ",00)\n";
    } else {
        cout << "Tidak ada moda transportasi untuk keberangkatan\n"; // cout untuk memeberi tahu bahwa tdk ada moda transportasi yg tersedia di jam yang diinput
    }

    // kepulangan
    biaya = cek_murah(pulang);
    if (biaya != -1){
        total_biaya += biaya;
        cout << "Moda transportasi untuk kepulangan: " 
             << (biaya == 0 ? "Bus Linus" : "Bus Hijau") // ternary utk cout jenis moda transportasi yg digunakan
             << " (Rp" << biaya << ",00)\n";
    } else {
        cout << "Tidak ada moda transportasi untuk kepulangan\n"; // cout untuk memeberi tahu bahwa tdk ada moda transportasi yg tersedia di jam yang diinput
    }

    // cout total biaya pulang dan pergi
    cout << "Total biaya berangkat-pulang: Rp" << total_biaya << ",00\n";

    return 0;
}
