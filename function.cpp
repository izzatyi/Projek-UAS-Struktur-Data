#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Produk {
    string id, nama, kategori;
    double harga;
};
struct KeranjangItem {
    Produk produk;
    int quantity;
};

class TokoOnline {
    private:
        vector<Produk> daftarProduk;
        unordered_map<string, Produk *> produkMap;
        vector<KeranjangItem> keranjang;
        vector<tuple<unordered_map<string, tuple<string, int, double>>, double, double, double, string>> riwayatPembayaran;
        vector<Produk> produkDibayar;
    public:
        TokoOnline()
        {
            // Elektronik
        daftarProduk.push_back({"1", "Smartphone Samsung Galaxy S23", "Elektronik", 12000000});
        daftarProduk.push_back({"2", "Laptop ASUS ROG Zephyrus G14", "Elektronik", 25000000});
        daftarProduk.push_back({"3", "TV LED LG 43 Inch", "Elektronik", 6500000});
        daftarProduk.push_back({"4", "Earbuds Apple AirPods Pro", "Elektronik", 3500000});
        daftarProduk.push_back({"5", "Kamera DSLR Canon EOS 90D", "Elektronik", 17000000});

        // Fitness
        daftarProduk.push_back({"6", "Sepeda MTB Polygon", "Fitness", 5000000});
        daftarProduk.push_back({"7", "Dumbbell 5kg", "Fitness", 200000});
        daftarProduk.push_back({"8", "Matras Yoga", "Fitness", 250000});
        daftarProduk.push_back({"9", "Mesin Elliptical", "Fitness", 7500000});
        daftarProduk.push_back({"10", "Resistance Band", "Fitness", 100000});

        // Kecantikan
        daftarProduk.push_back({"11", "Serum Wajah Vitamin C", "Kecantikan", 150000});
        daftarProduk.push_back({"12", "Masker Wajah Aloe Vera", "Kecantikan", 75000});
        daftarProduk.push_back({"13", "Lipstik Matte L'Oréal", "Kecantikan", 120000});
        daftarProduk.push_back({"14", "Parfum Chanel", "Kecantikan", 2500000});
        daftarProduk.push_back({"15", "Sabun Cuci Muka Himalaya", "Kecantikan", 35000});

        // Konsumsi
        daftarProduk.push_back({"16", "Roti Tawar", "Konsumsi", 15000});
        daftarProduk.push_back({"17", "Kopi Arabica 100g", "Konsumsi", 50000});
        daftarProduk.push_back({"18", "Mie Instan", "Konsumsi", 5000});
        daftarProduk.push_back({"19", "Susu UHT Indomilk 1 Liter", "Konsumsi", 18000});
        daftarProduk.push_back({"20", "Teh Kotak Sosro 500ml", "Konsumsi", 7500});

            for (auto &produk : daftarProduk)
            {
                produkMap[produk.id] = &produk;
            }
        }
        Produk *cariProdukBerdasarkanID(const string &idProduk)
        {
            auto it = produkMap.find(idProduk);
            if (it != produkMap.end())
            {
                return it->second;
            }
            return nullptr;
        }
        void tampilkanDetailProduk(const string &idProduk) {
            system("cls");
            Produk *produk = cariProdukBerdasarkanID(idProduk);
            if (produk != nullptr)
            {
                cout << string(50, '=') << endl;
                cout << "|                 DETAIL PRODUK                  |" << endl;
                cout << string(50, '-') << endl;
                cout << left << setw(20) << "Informasi Keterangan : " << endl;
                cout << string(50, '-') << endl;
                cout << left << setw(20) << "ID Produk   : " << produk->id << endl;
                cout << left << setw(20) << "Nama Produk : " << produk->nama << endl;
                cout << left << setw(20) << "Kategori    : " << produk->kategori << endl;
                cout << left << setw(20) << "Harga       : Rp " << fixed << setprecision(2) << produk->harga << endl;
                cout << string(50, '=') << endl;
            }
            else
            {
                cout << "Produk dengan ID " << idProduk << " tidak ditemukan." << endl;
            }

            cout << "\n0. Kembali" << endl;
            int pilihan;
            cout << "Pilih Menu: ";
            cin >> pilihan;
        }
        void lihatProduk()
        {
            system("cls");
            cout << "\n===========================================================================" << endl;
            cout << "                            DAFTAR SEMUA PRODUK                            " << endl;
            cout << "===========================================================================" << endl;
            cout << left
                << setw(8) << "| ID   " << setw(6)
                << setw(32) << "| Nama Produk "
                << setw(17) << "| Kategori "
                << setw(17) << "| Harga " << "|" << endl;
            cout << string(75, '=') << endl;
            for (const auto &produk : daftarProduk)
            {
                cout << left
                    << "| " << setw(6) << produk.id
                    << "| " << setw(30) << produk.nama
                    << "| " << setw(15) << produk.kategori
                    << setw(5) << "| Rp " << fixed << setprecision(2) << setw(11) << produk.harga << " |" << endl;
            }
            cout << string(75, '=') << endl;
        }
        void urutkanProduk()
        {
            cout << "1. Sortir Produk Berdasarkan Kategori" << endl;
            cout << "2. Sortir Produk Berdasarkan Harga" << endl;
            cout << "0. Kembali" << endl;

            int pilihan;
            cout << "\nPilih menu: ";
            cin >> pilihan;
            if (pilihan == 1)
            {
                sortirProdukBerdasarkanKategori();
            }
            else if (pilihan == 2)
            {
                sortirProdukBerdasarkanHarga();
            }
        }
        void sortirProdukBerdasarkanKategori() {
            unordered_map<string, vector<Produk>> kategoriProduk;
            for (const auto &produk : daftarProduk) {
                kategoriProduk[produk.kategori].push_back(produk);
            }

            int pilihanKategori;
            do {
                system("cls");
                cout << "\n============================================" << endl;
                cout << "|     SORTIR PRODUK BERDASARKAN KATEGORI   |" << endl;
                cout << "============================================" << endl;
                cout << "|1. Elektronik                             |" << endl;
                cout << "|2. Fitness                                |" << endl;
                cout << "|3. Kecantikan                             |" << endl;
                cout << "|4. Konsumsi                               |" << endl;
                cout << "|0. Kembali                                |" << endl;
                cout << "============================================" << endl;
                cout << "Pilih kategori (0-4): ";
                cin >> pilihanKategori;

                string kategoriDipilih;
                switch (pilihanKategori) {
                    case 1:
                        kategoriDipilih = "Elektronik";
                        break;
                    case 2:
                        kategoriDipilih = "Fitness";
                        break;
                    case 3:
                        kategoriDipilih = "Kecantikan";
                        break;
                    case 4:
                        kategoriDipilih = "Konsumsi";
                        break;
                    case 0:
                        return;
                    default:
                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                        system("pause");
                        continue;
                }

                system("cls");
                if (kategoriProduk.find(kategoriDipilih) != kategoriProduk.end()) {
                    vector<Produk> &produkList = kategoriProduk[kategoriDipilih];

                    cout << "\n===========================================================================" << endl;
                    cout << "                       PRODUK DALAM KATEGORI: " << kategoriDipilih << "           " << endl;
                    cout << "===========================================================================" << endl;
                    cout << left
                << setw(8) << "| ID   " << setw(6)
                << setw(32) << "| Nama Produk "
                << setw(17) << "| Kategori "
                << setw(17) << "| Harga " << "|" << endl;
            cout << string(75, '=') << endl;
            for (const auto &produk : daftarProduk)
            {
                cout << left
                    << "| " << setw(6) << produk.id
                    << "| " << setw(30) << produk.nama
                    << "| " << setw(15) << produk.kategori
                    << setw(5) << "| Rp " << fixed << setprecision(2) << setw(11) << produk.harga << " |" << endl;
            }
            cout << string(75, '=') << endl;
                } else {
                    cout << "Tidak ada produk dalam kategori ini." << endl;
                }

                cout << "\nTekan ENTER untuk kembali ke menu kategori...";
                cin.ignore();
                cin.get();
            } while (pilihanKategori != 0);
        }
        void sortirProdukBerdasarkanHarga() {
            int pilihanUrutan;
            do {
                system("cls");
                cout << "\n============================================" << endl;
                cout << "|     SORTIR PRODUK BERDASARKAN HARGA      |" << endl;
                cout << "============================================" << endl;
                cout << "|1. Dari harga terendah ke tertinggi       |" << endl;
                cout << "|2. Dari harga tertinggi ke terendah       |" << endl;
                cout << "|0. Kembali                                |" << endl;
                cout << "============================================" << endl;
                cout << "Pilih metode sortir (0-2): ";
                cin >> pilihanUrutan;

                system("cls");
                vector<Produk> semuaProduk = daftarProduk;
                if (pilihanUrutan == 1) {
                    sort(semuaProduk.begin(), semuaProduk.end(), [](const Produk &a, const Produk &b)
                        { return a.harga < b.harga; });
                } else if (pilihanUrutan == 2) {
                    sort(semuaProduk.begin(), semuaProduk.end(), [](const Produk &a, const Produk &b)
                        { return a.harga > b.harga; });
                } else if (pilihanUrutan == 0) {
                    return;
                } else {
                    cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                    system("pause");
                    continue;
                }

                    cout << "\n===========================================================================" << endl;
                    cout << "                       DAFTAR PRODUK BERDASARKAN HARGA                     " << endl;
                    cout << "===========================================================================" << endl;
                cout << left
                    << setw(8) << "| ID   " << setw(6)
                    << setw(32) << "| Nama Produk "
                    << setw(17) << "| Kategori "
                    << setw(17) << "| Harga " << "|" << endl;
                cout << string(75, '=') << endl;

                for (const auto &produk : semuaProduk) {
                    cout << left
                        << "| " << setw(6) << produk.id
                        << "| " << setw(30) << produk.nama
                        << "| " << setw(15) << produk.kategori
                        << setw(5) << "| Rp " << fixed << setprecision(2) << setw(11) << produk.harga << " |" << endl;
                }
                cout << string(75, '=') << endl;
                cout << "\nTekan ENTER untuk kembali ke menu sortir...";
                cin.ignore();
                cin.get();
            } while (pilihanUrutan != 0);
        }
        void tambahkanKeKeranjang(const string &idProduk) {
            auto it = find_if(daftarProduk.begin(), daftarProduk.end(),
                            [&idProduk](const Produk &p)
                            { return p.id == idProduk; });

            if (it != daftarProduk.end()) {
                int quantity;
                cout << "Masukkan jumlah untuk produk \"" << it->nama << "\": ";
                cin >> quantity;

                if (quantity <= 0) {
                    cout << "Jumlah harus lebih dari 0. Coba lagi." << endl;
                    return;
                }

                auto keranjangIt = find_if(keranjang.begin(), keranjang.end(),
                                        [&idProduk](const KeranjangItem &item)
                                        {
                                            return item.produk.id == idProduk;
                                        });

                if (keranjangIt != keranjang.end()) {
                    keranjangIt->quantity += quantity;
                } else {
                    keranjang.push_back({*it, quantity});
                }

                cout << "Produk \"" << it->nama << "\" sebanyak " << quantity
                    << " berhasil ditambahkan ke keranjang." << endl;
            } else{
                cout << "Produk dengan ID " << idProduk << " tidak ditemukan." << endl;
            }

            cout << "\n1. Tambah Produk Lain\n0. Kembali" << endl;
            int pilihan;
            cout << "Pilih menu: ";
            cin >> pilihan;
            if (pilihan == 1) {
                string idLain;
                cout << "Masukkan ID Produk: ";
                cin >> idLain;
                tambahkanKeKeranjang(idLain);
            }
        }
        // Tampilkan isi keranjang
        void tampilkanKeranjang() {
            system("cls");
            if (keranjang.empty()) {
                cout << string(75, '=') << endl;
                cout << "                          Isi Keranjang                          " << endl;
                cout << string(75, '=') << endl;
                cout << "Keranjang Anda kosong." << endl;
            } else {
                double totalHarga = 0.0;
                cout << string(75, '=') << endl;
                cout << "                          Isi Keranjang                          " << endl;
                cout << string(75, '=') << endl;
                cout << left
                    << setw(10) << "ID"
                    << setw(32) << "Nama Produk"
                    << setw(15) << "Quantity"
                    << "Harga Total" << endl;
                cout << string(75, '-') << endl;

                for (const auto &item : keranjang) {
                    double hargaTotal = item.produk.harga * item.quantity;
                    cout << left
                        << setw(10) << item.produk.id
                        << setw(32) << item.produk.nama
                        << setw(15) << item.quantity
                        << "Rp " << fixed << setprecision(2) << hargaTotal << endl;
                    totalHarga += hargaTotal;
                }

                cout << string(75, '-') << endl;
                cout << "Total Harga: Rp " << fixed << setprecision(2) << totalHarga << endl;
            }

            cout << "\n1. Hapus Produk\n0. Kembali" << endl;
            int pilihan;
            cout << "Pilih Menu: ";
            cin >> pilihan;
            switch (pilihan) {
                case 1:
                    tampilkanMenuHapus();
                    break;
                case 0:
                    return;
                default:
                    cout << "Pilihan tidak valid." << endl;
            }
        }
        void tampilkanMenuHapus() {
            cout << "\n1. Hapus Satu Produk" << endl;
            cout << "2. Hapus Semua Produk" << endl;
            cout << "0. Kembali" << endl;

            int pilihan;
            cout << "Pilih Menu: ";
            cin >> pilihan;

            string idProduk;
            switch (pilihan) {
                case 1:
                    cout << "Masukkan ID Produk: ";
                    cin >> idProduk;
                    hapusDariKeranjang(idProduk);
                    tampilkanKeranjang();
                    break;
                case 2:
                    hapusSemuaDariKeranjang();
                    tampilkanKeranjang();
                    break;
                case 0:
                    return;
                default:
                    cout << "Pilihan tidak valid." << endl;
            }
        }
        void hapusDariKeranjang(const string &idProduk) {
            auto it = remove_if(keranjang.begin(), keranjang.end(),
                                [&idProduk](const KeranjangItem &item)
                                {
                                    return item.produk.id == idProduk;
                                });

            if (it != keranjang.end()) {
                keranjang.erase(it, keranjang.end());
                cout << "Produk dengan ID " << idProduk << " berhasil dihapus dari keranjang." << endl;
            } else {
                cout << "Produk dengan ID " << idProduk << " tidak ditemukan di keranjang." << endl;
            }
        }
        void hapusSemuaDariKeranjang() {
            keranjang.clear();
            cout << "Semua produk berhasil dihapus dari keranjang." << endl;
        }
        int hitungBiayaPengiriman(vector<vector<pii>> &graph, int start, int tujuan, int biayaPerKm) {
            int n = graph.size();
            vector<int> jarak(n, INT_MAX);
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            jarak[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                int currentDistance = pq.top().first;
                int currentNode = pq.top().second;
                pq.pop();

                if (currentDistance > jarak[currentNode])
                    continue;
                for (auto &neighbor : graph[currentNode]) {
                    int nextNode = neighbor.first;
                    int weight = neighbor.second;
                    int distance = currentDistance + weight;
                    if (distance < jarak[nextNode])
                    {
                        jarak[nextNode] = distance;
                        pq.push({distance, nextNode});
                    }
                }
            }
            return (jarak[tujuan] == INT_MAX) ? -1 : jarak[tujuan] * biayaPerKm;
        }
        vector<vector<pii>> buatGraph() {
            vector<vector<pii>> graph(10);
            graph[0] = {{3, 4}, {8, 5}, {2, 7}, {6, 4}};
            graph[2] = {{1, 5}};
            graph[4] = {{7, 7}};
            graph[5] = {{4, 9}, {7, 8}, {9, 3}};
            graph[6] = {{5, 11}, {4, 2}, {1, 4}};
            graph[9] = {{7, 4}};
            return graph;
        }
        void biayaPengiriman() {
            vector<vector<pii>> graph = buatGraph();
            int start = 0;
            int biayaPerKm = 3000;
            int tujuan;

            do {
                cout << "Masukkan titik tujuan (0-9): ";
                cin >> tujuan;
                if (tujuan < 0 || tujuan >= graph.size())
                {
                    cout << "Tujuan tidak valid. Masukkan angka antara 0-9." << endl;
                    continue;
                }
                int biaya = hitungBiayaPengiriman(graph, start, tujuan, biayaPerKm);
                if (biaya != -1)
                {
                    cout << "Biaya pengiriman dari " << start << " ke " << tujuan
                        << " adalah Rp " << biaya << endl;
                }
                else
                {
                    cout << "Tidak ada jalur dari " << start << " ke " << tujuan << endl;
                }
            } while (true);
        }
        //tanya tujuan masih ngga dipake
        void tanyatujuan()
        {
            char pilihanLagi;
            cout << "Apakah Anda ingin memasukkan tujuan lain? (y/n): ";
            cin >> pilihanLagi;

            if (tolower(pilihanLagi) == 'n')
            {
                return;
            }
            else if (tolower(pilihanLagi) == 'y')
            {
                biayaPengiriman();
            }
            else
            {
                cout << "\nUNVALID";
            }
        }
        void tampilkanBiayaPengiriman() {
            vector<vector<pii>> graph = buatGraph();
            int start = 0; // Titik awal pengiriman
            int biayaPerKm = 3000;

            cout << "\n===================================" << endl;
            cout << "|  BIAYA PENGIRIMAN DARI TITIK 0  |" << endl;
            cout << "===================================" << endl;
            cout << left << setw(10) << "| Tujuan |" << "    Biaya Pengiriman    |" << endl;
            cout << string(35, '-') << endl;

            for (int tujuan = 0; tujuan < graph.size(); ++tujuan)
            {
                int biaya = hitungBiayaPengiriman(graph, start, tujuan, biayaPerKm);
                if (biaya != -1)
                {
                    cout << left << "|   " << setw(5) << tujuan << "|       " << "Rp " << setw(7) << biaya  << "       |" << endl;
                }
                else
                {
                    cout << left << setw(10) << tujuan << "Tidak Ada Jalur" << endl;
                }
            }

            cout << string(35, '-') << endl;
            cout << "\nTekan ENTER untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
        }
        void pembayaran() {
            system("cls");
            if (keranjang.empty())
            {
                cout << "Keranjang Anda kosong. Tidak ada yang perlu dibayar.\n"
                    << "Tekan ENTER untuk kembali ke menu kategori...";
                cin.ignore();
                cin.get();
                return;
            }

            vector<vector<pii>> graph = buatGraph();
            int start = 0; // Asumsi lokasi pengirim selalu di titik 0
            int biayaPerKm = 3000;
            int tujuan;

            // Tampilkan isi keranjang
            double totalHarga = 0.0;
            cout << "\n===========================================================================" << endl;
            cout << "                               PEMBAYARAN                                  " << endl;
            cout << "===========================================================================" << endl;
            cout << left 
                 << setw(10) << "ID" 
                 << setw(32) << "Nama Produk"
                 << setw(15) << "Quantity" 
                 << "Harga Total" << endl;
            cout << string(75, '-') << endl;

            for (const auto &item : keranjang)
            {
                double hargaTotal = item.produk.harga * item.quantity;
                cout << left 
                     << setw(10) << item.produk.id
                     << setw(32) << item.produk.nama
                     << setw(15) << item.quantity
                     << "Rp " << fixed << setprecision(2) << hargaTotal << endl;
                totalHarga += hargaTotal;
            }

            cout << string(75, '-') << endl;
            cout << "Total Harga Produk: Rp " << fixed << setprecision(2) << totalHarga << endl;

            // Input tujuan pengiriman
            cout << "\nMasukkan tujuan pengiriman (0-9): ";
            cin >> tujuan;
            if (tujuan < 0 || tujuan >= graph.size())
            {
                cout << "Tujuan tidak valid. Pembayaran dibatalkan.\n";
                cin.ignore();
                cin.get();
                return;
            }

            // Hitung biaya pengiriman
            int ongkosKirim = hitungBiayaPengiriman(graph, start, tujuan, biayaPerKm);
            if (ongkosKirim == -1)
            {
                cout << "Tidak ada jalur pengiriman ke tujuan ini. Pembayaran dibatalkan.\n";
                cin.ignore();
                cin.get();
                return;
            }

            cout << "Biaya Pengiriman: Rp " << ongkosKirim << endl;

            // Total pembayaran
            double totalPembayaran = totalHarga + ongkosKirim;
            cout << "Total Pembayaran (Produk + Biaya Pengiriman): Rp " << fixed << setprecision(2) << totalPembayaran << endl;

            // Konfirmasi pembayaran
            char konfirmasi;
            cout << "\nApakah Anda ingin melanjutkan pembayaran? (y/n): ";
            cin >> konfirmasi;

            if (konfirmasi == 'y' || konfirmasi == 'Y'){
                // Salin keranjang ke riwayat pembayaran
                vector<KeranjangItem> keranjangCopy = keranjang; // Salin detail keranjang
                keranjang.clear();                               // Kosongkan keranjang setelah pembayaran

                // Simpan detail pembayaran ke riwayat dengan memanggil fungsi tambahRiwayatPembayaran
                tambahRiwayatPembayaran(keranjangCopy, totalHarga, ongkosKirim, totalPembayaran, to_string(tujuan));

                cout << "\nPembayaran berhasil. Terima kasih telah berbelanja!" << endl;
            }
            else{
                cout << "\nPembayaran dibatalkan." << endl;
            }

            cout << "Tekan ENTER untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
        }
        void tambahRiwayatPembayaran(vector<KeranjangItem> produkList, double totalHarga, double biayaPengiriman, double totalPembayaran, string tujuan) {
            unordered_map<string, tuple<string, int, double>> detailPembayaran;

            // Mengisi detailPembayaran dengan data yang relevan
            for (const auto& produk : produkList) {
                detailPembayaran[produk.produk.nama] = make_tuple(produk.produk.id, produk.quantity, produk.produk.harga);
            }

            // Menambahkan detail pembayaran ke riwayat
            riwayatPembayaran.push_back(make_tuple(detailPembayaran, totalHarga, biayaPengiriman, totalPembayaran, tujuan));
        }
        void tampilkanRiwayatPembayaran() {
            system("cls");
            cout << string(75, '=') << endl;
            cout << "                      RIWAYAT PEMBAYARAN                         " << endl;
            cout << string(75, '=') << endl;

            int noPembayaran = 1;
            for (const auto &item : riwayatPembayaran) {
                double totalHarga = get<1>(item);
                string tujuan = get<4>(item);
                cout << "Pembayaran #" << noPembayaran++ << ":" << endl;
                cout << "Total Pembayaran   : Rp " << fixed << setprecision(2) << totalHarga << endl;
                cout << "Tujuan Pengiriman  : " << tujuan << endl;
                cout << "[Lihat Detail]" << endl;
                cout << endl;
            }

            cout << string(75, '=') << endl;
            cout << "Masukkan nomor pembayaran yang ingin dilihat detailnya,\natau tekan 0 untuk kembali ke menu utama: ";
            int pilihan;
            cin >> pilihan;

            if (pilihan > 0 && pilihan <= riwayatPembayaran.size()) {
                tampilkanDetailPembayaran(pilihan - 1);  // Menampilkan detail pembayaran yang dipilih
            } else if (pilihan == 0) {
                return;  // Kembali ke menu utama
            } else {
                cout << "Pilihan tidak valid." << endl;
            }
        }
        void tampilkanDetailPembayaran(int index) {
            const auto &item = riwayatPembayaran[index];
            unordered_map<string, tuple<string, int, double>> detailPembayaran = get<0>(item);
            double totalHarga = get<1>(item);
            double biayaPengiriman = get<2>(item);
            double totalPembayaran = get<3>(item);
            string tujuan = get<4>(item);

            system("cls");
            cout << string(75, '=') << endl;
            cout << "                           DETAIL PEMBAYARAN                              " << endl;
            cout << string(75, '=') << endl;
            cout << left 
                << setw(10) << "ID" 
                << setw(32) << "Nama Produk"
                << setw(15) << "Quantity" 
                << "Harga Satuan" << endl;
            cout << string(75, '-') << endl;

            // Menampilkan detail pembayaran dari unordered_map
            for (const auto &produk : detailPembayaran) {
                string namaProduk = produk.first;
                string id = get<0>(produk.second);
                int quantity = get<1>(produk.second);
                double harga = get<2>(produk.second);
                
                cout << left 
                    << setw(10) << id 
                    << setw(32) << namaProduk
                    << setw(15) << quantity 
                    << "Rp " << fixed << setprecision(2) << harga << endl;
            }

            cout << string(75, '-') << endl;
            cout << "Total Pembayaran   : Rp " << fixed << setprecision(2) << totalPembayaran << endl;
            cout << "Biaya Pengiriman   : Rp " << fixed << setprecision(2) << biayaPengiriman << endl;
            cout << "Tujuan Pengiriman  : " << tujuan << endl;
            cout << string(75, '=') << endl;
            cout << "Tekan ENTER untuk kembali ke Riwayat Pembayaran..." << endl;
            cin.ignore();
            cin.get();
            tampilkanRiwayatPembayaran();
        }
};