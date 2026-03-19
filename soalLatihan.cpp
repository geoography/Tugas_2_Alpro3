#include <iostream>
using namespace std;

int main(){
    int jasa, tujuan;
    double berat, kirim;
    string jasaS;

    do {
        cout << "Berat barang(kg): "; 
        cin >> berat; // pertama-tama, input berat badan terlebih dahulu
    } while (berat <= 0);

    do{
        cout << "Pilih pengiriman (1 = dalam kota, 2 = luar kota): ";
        cin >> tujuan; // input tujuan ke dalam atau ke luar kota
    } while (tujuan != 1 && tujuan != 2); // looping agar input tujuan itu valid (hanya 1 atau 2)

    if (tujuan == 1){ // kalau tujuan ke dalam kota, pilihan jasa pengiriman ada 3
        do{
            cout << "Pilih jasa pengiriman: \n";
            cout << "1. JNE\n";
            cout << "2. SiCepat\n";
            cout << "3. Gojek\n";
            cout << "Pilih jasa pengiriman: ";
            cin >> jasa;
        }while (jasa != 1 && jasa != 2 && jasa != 3);

        if (jasa == 1) kirim = 10000 * berat;
        else if (jasa == 2) kirim = 8000 * berat;
        else kirim = 12000 * berat; 
    }else{ // kalau tujuan ke luar kota, pilihan jasa pengiriman ada 2
        do{
            cout << "Pilihan jasa pengiriman: \n";
            cout << "1. JNE\n";
            cout << "2. SiCepat\n";
            cout << "Pilih jasa pengiriman: ";
            cin >> jasa;
        }while (jasa != 1 && jasa != 2);

        if (jasa == 1) kirim = 20000 * berat;
        else if (jasa == 2) kirim = 18000 * berat;
    }

    //  variabel string utk menyimpan nama jasa pengiriman
    if (jasa == 1) jasaS = "JNE"; 
    else if (jasa == 2) jasaS = "SiCepat";
    else jasaS = "Gojek";

    // diskon jika memenuhi syarat tertentu
    if (jasa == 1 && berat > 10){
        kirim /= 2;
    }else if(jasa == 2 && berat > 15){
        kirim = 0;
    }else if(jasa == 3 && berat > 5){
        kirim -= 10000;
    }

    // cout jenis ekspedisi yang dipilih dan total biaya dari pengiriman (sudah dipotong diskon jika memenuhi syarat)
    cout << "Ekspedisi yang dipilih: " << jasaS << endl;
    cout << "Total Biaya: Rp" << kirim;

}
