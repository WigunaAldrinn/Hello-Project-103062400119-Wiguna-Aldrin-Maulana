//Nama:Wiguna_Aldrin_Maulana NIM:103062400119
//Tambahan teks Comment
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

//Struktur Node untuk Linked List
struct Barang {
    string nama;
    int jumlah;
    double hargaSatuan;
    double subTotal;
    Barang* next;
};

//Inisialisasi Head dari Linked List
Barang* head = nullptr;

//Fungsi untuk Menambahkan Barang Baru ke Keranjang (Linked List)
void tambahBarang(string nama, int jumlah, double hargaSatuan) {
    Barang* newNode = new Barang;

    newNode->nama = nama;
    newNode->jumlah = jumlah;
    newNode->hargaSatuan = hargaSatuan;
    newNode->subTotal = jumlah * hargaSatuan;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Barang* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//Fungsi untuk Menampilkan Isi Keranjang dan Total Harga
void tampilkanKeranjang() {
    if (head == nullptr) {
        cout << "\nKeranjang belanja kosong." << endl;
        return;
    }

    cout << "\n==============================================" << endl;
    cout << "              ISI KERANJANG BELANJA             " << endl;
    cout << "==============================================" << endl;

    Barang* current = head;
    double totalHargaKeseluruhan = 0.0;


    cout << fixed << setprecision(0);


    while (current != nullptr) {

        cout << current->nama << " (" << current->jumlah << ") - Rp."
             << current->hargaSatuan << " (Subtotal: Rp." << current->subTotal << ")" << endl;

        totalHargaKeseluruhan += current->subTotal;
        current = current->next;
    }

    cout << "----------------------------------------------" << endl;
    cout << "TOTAL HARGA SELURUH BELANJA: Rp." << totalHargaKeseluruhan << endl;
    cout << "==============================================" << endl;
}


void inputBarangManual() {
    string nama;
    int jumlah;
    double hargaSatuan;
    char lanjut;

    cout << "--- MEMASUKKAN DATA KERANJANG BELANJA ---" << endl;

    do {

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nMasukkan Nama Barang: ";
        getline(cin, nama);

        cout << "Masukkan Jumlah (Angka): ";
        while (!(cin >> jumlah) || jumlah <= 0) {
            cout << "Input tidak valid. Masukkan Jumlah (Angka > 0): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Masukkan Harga Satuan (Angka): Rp.";
        while (!(cin >> hargaSatuan) || hargaSatuan <= 0) {
            cout << "Input tidak valid. Masukkan Harga Satuan (Angka > 0): Rp.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        tambahBarang(nama, jumlah, hargaSatuan);
        cout << "Barang'" << nama << "' berhasil ditambahkan." << endl;

        cout << "\nIngin menambahkan barang lain? (y/t): ";

        cin >> lanjut;
        lanjut = tolower(lanjut);

    } while (lanjut == 'y');
}



int main() {

    inputBarangManual();

    tampilkanKeranjang();


    Barang* current = head;
    while (current != nullptr) {
        Barang* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;

    return 0;
}
