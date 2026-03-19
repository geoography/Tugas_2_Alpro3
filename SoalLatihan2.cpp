#include <iostream>
using namespace std;

int main() {
    double berat;
    int tujuan; // 1 = dalam kota, 2 = luar kota

    cout << "Masukkan berat barang (kg): ";
    cin >> berat;

    cout << "Tujuan pengiriman (1 = dalam kota, 2 = luar kota): ";
    cin >> tujuan;

    // ================= JNE =================
    double biaya_jne;
    if (tujuan == 1) {
        biaya_jne = 10000 * berat; // dalam kota
    } else {
        biaya_jne = 20000 * berat; // luar kota
    }

    // diskon 50% jika > 10 kg
    if (berat > 10) {
        biaya_jne *= 0.5;
    }

    // ================= SiCepat =================
    double biaya_sicepat;
    if (berat > 15) {
        biaya_sicepat = 0; // gratis ongkir
    } else {
        if (tujuan == 1) {
            biaya_sicepat = 8000 * berat;
        } else {
            biaya_sicepat = 18000 * berat;
        }
    }

    double biaya_gojek;
    if (tujuan == 2) {
        biaya_gojek = -1; // tidak tersedia untuk luar kota
    } else {
        biaya_gojek = 12000 * berat;

        // diskon 10.000 jika > 5 kg
        if (berat > 5) {
            biaya_gojek -= 10000;
        }

        // jaga-jaga kalau jadi negatif
        if (biaya_gojek < 0) biaya_gojek = 0;
    }

    cout << "\n=== Rincian Biaya ===\n";
    cout << "JNE      : Rp " << biaya_jne << endl;
    cout << "SiCepat  : Rp " << biaya_sicepat << endl;

    if (biaya_gojek == -1) {
        cout << "Gojek    : Tidak tersedia (luar kota)\n";
    } else {
        cout << "Gojek    : Rp " << biaya_gojek << endl;
    }

    double min_biaya = biaya_jne;
    string ekspedisi = "JNE";

    if (biaya_sicepat < min_biaya) {
        min_biaya = biaya_sicepat;
        ekspedisi = "SiCepat";
    }

    if (biaya_gojek != -1 && biaya_gojek < min_biaya) {
        min_biaya = biaya_gojek;
        ekspedisi = "Gojek";
    }

    cout << "\nEkspedisi termurah: " << ekspedisi
         << " (Rp " << min_biaya << ")" << endl;

    return 0;
}
