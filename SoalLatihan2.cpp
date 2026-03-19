#include <iostream>
#include <iomanip>
using namespace std;

// fungsi untuk menghitung biaya awal (sebelum diskon)
double hitungBiaya(int jasa, int tujuan, double berat){
    if (jasa == 1){ // JNE
        return (tujuan == 1 ? 10000 : 20000) * berat;
    }
    else if (jasa == 2){ // SiCepat
        return (tujuan == 1 ? 8000 : 18000) * berat;
    }
    else{ // Gojek (hanya dalam kota)
        return 12000 * berat;
    }
}

// fungsi untuk potong diskon
double potongDiskon(int jasa, double berat, double biaya){
    if (jasa == 1 && berat > 10){
        biaya *= 0.5;
    }
    else if (jasa == 2 && berat > 15){
        biaya = 0;
    }
    else if (jasa == 3 && berat > 5){
        biaya -= 10000;
    }
    return biaya;
}

// fungsi untuk nama jasa
string getNamaJasa(int jasa){
    if (jasa == 1) return "JNE";
    else if (jasa == 2) return "SiCepat";
    else return "Gojek";
}

int main(){
    int jasa, tujuan;
    double berat;

    // input berat
    do {
        cout << "Berat barang(kg): ";
        cin >> berat;
    } while (berat <= 0); // ulang sampai berat diatas 0 kg

    // input tujuan
    do{
        cout << "Pilih pengiriman (1 = dalam kota, 2 = luar kota): ";
        cin >> tujuan;
    } while (tujuan != 1 && tujuan != 2); // ulang sampai tujuan = 1 atau tujuan = 2

    // input jasa
    if (tujuan == 1){
        do{
            cout << "Pilih jasa pengiriman:\n";
            cout << "1. JNE\n2. SiCepat\n3. Gojek\n";
            cout << "Pilih: ";
            cin >> jasa;
        } while (jasa < 1 || jasa > 3);
    } else {
        do{
            cout << "Pilih jasa pengiriman:\n";
            cout << "1. JNE\n2. SiCepat\n";
            cout << "Pilih: ";
            cin >> jasa;
        } while (jasa < 1 || jasa > 2);
    }

    // hitung biaya lalu langsung dipotong diskon
    double biaya = hitungBiaya(jasa, tujuan, berat);
    biaya = potongDiskon(jasa, berat, biaya);

    // output
    cout << fixed << setprecision(0); // batasi supaya tidak ada angka di belakang koma
    cout << "Ekspedisi yang dipilih: " << getNamaJasa(jasa) << endl; // cout nama jasa
    cout << "Total Biaya: Rp" << biaya << endl; // cout total biaya (setelah dipotong diskon)

    return 0;
}
