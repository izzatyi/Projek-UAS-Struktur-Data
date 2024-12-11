#include <bits/stdc++.h>
#include "function.cpp"

using namespace std;

int main() {
    system("cls");
    system("color 0A");
    cout << "\n=============================================================" << endl;
    cout << "                  SELAMAT DATANG DI SHOP EASE                " << endl;
    cout << "=============================================================" << endl;
    cout << "  Temukan berbagai produk pilihan dengan mudah dan nyaman!  " << endl;
    cout << "  Kami siap membantu kebutuhan belanja Anda. Selamat belanja!" << endl;
    cout << "=============================================================" << endl;

    cout << "\nTekan ENTER untuk melanjutkan ke menu utama...";
    cin.get(); 

    TokoOnline toko;
    int pilihan;
    do {
        system("cls");
        system("color 5");
        cout << "\n=======================================" << endl;
        cout << "              SHOP EASE                " << endl;
        cout << "=======================================" << endl;
        cout << "|  1. Lihat Produk                    |" << endl;
        cout << "|  2. Cari Produk                     |" << endl;
        cout << "|  3. Tambah Produk ke Keranjang      |" << endl;
        cout << "|  4. Lihat Keranjang                 |" << endl;
        cout << "|  5. Lihat Biaya Pengiriman          |" << endl;
        cout << "|  6. Pembayaran                      |" << endl;
        cout << "|  7. Lihat Riwayat Pembayaran        |" << endl;
        cout << "|  0. Keluar                          |" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (0-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                toko.lihatProduk();
                toko.urutkanProduk();
                break;
            case 2: {
                string idProduk;
                system("cls"); toko.lihatProduk();
                cout << "Masukkan ID Produk yang ingin dicari: ";
                cin >> idProduk;
                toko.tampilkanDetailProduk(idProduk);
                break;
            }
            case 3: {
                string idProduk;
                system("cls"); toko.lihatProduk();
                cout << "Masukkan ID Produk: ";
                cin >> idProduk;
                toko.tambahkanKeKeranjang(idProduk);
                break;
            }
            case 4:
                toko.tampilkanKeranjang();
                break;
            case 5:
                system("cls");
                toko.tampilkanBiayaPengiriman();
                break;
            case 6:
                toko.pembayaran();
                break;
            case 7:
                toko.tampilkanRiwayatPembayaran();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan Shop Ease. Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);
    return 0;
}
