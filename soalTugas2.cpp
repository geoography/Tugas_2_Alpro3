#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Ambil tiap digit
    int d1 = n / 1000;
    int d2 = (n / 100) % 10;
    int d3 = (n / 10) % 10;
    int d4 = n % 10;

    // Cek alfa (monoton naik atau turun)
    bool naik = (d1 < d2 && d2 < d3 && d3 < d4);
    bool turun = (d1 > d2 && d2 > d3 && d3 > d4);
    bool alfa = naik || turun;

    // Cek beta
    int duaDepan = d1 * 10 + d2;
    int duaBelakang = d3 * 10 + d4;
    bool beta = abs(duaDepan - duaBelakang) >= 30;

    // Klasifikasi
    if (alfa && beta) {
        cout << "gamma";
    } else if (alfa) {
        cout << "alfa";
    } else if (beta) {
        cout << "beta";
    } else {
        cout << "delta";
    }

    return 0;
}
