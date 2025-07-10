#include <iostream>
#include <fstream>
using namespace std;

struct Data{
    string no, judul, penulis;
    int stok;
};

class Perpus{
    private:
    string inPenulis;
    string inJudul;
    int inStok;
    Data dataBuku[100];
    int jumlahData = 0;
    public:

    void ambilData(){
        ifstream out;
        out.open("data.txt");
        while (out >> dataBuku[jumlahData].no >> dataBuku[jumlahData].judul >> dataBuku[jumlahData].penulis >> dataBuku[jumlahData].stok )
        {
            jumlahData++;
        }
        out.close();
        
    }

    void cariJudul(){
        ofstream in;
        in.open("hasil_cari_penulis.txt", ios::app);
        in << endl;
        cout << "-------------------------------------------" << endl;
        bool ada = false ;
        cout << "\nMencari judul buku berdasarkan penulisnya" << endl;
        cout <<"Masukkan nama penulisnya: ";
        cin >> inPenulis;

        for (int i = 0; i < jumlahData; i++)
        {
            if (inPenulis == dataBuku[i].penulis)
            {
                cout << "Judul buku: " << dataBuku[i].judul << endl;
                ada = true;
                in << "Penulis buku: " << dataBuku[i].penulis << endl;
                cout << "-------------------------------------------" << endl;
            }
        }
        if (!ada)
        {
            cout << "Tidak ada judul buku dengan penulis " << inPenulis << endl;
        }
        in.close();
        cout << "Hasil pencarian telah disimpan di file hasil_cari_penulis.txt" << endl;
    }

    void cariData(){
        ofstream in;
        in.open("hasil_cari_judul.txt", ios::app);
        in << "-------------------------------------------" << endl;
        bool ada = false ;
        cout << "\nMencari Data buku berdasarkan judulnya" << endl;
        cout <<"Masukkan nama judul buku: ";
        cin >> inJudul;

        for (int i = 0; i < jumlahData; i++)
        {
            if (inJudul == dataBuku[i].judul)
            {
                cout << "Nomor buku: " << dataBuku[i].no << endl;
                cout << "Judul buku: " << dataBuku[i].judul << endl;
                cout << "Penulis buku: " << dataBuku[i].penulis << endl;
                cout << "Stok buku: " << dataBuku[i].stok << endl;
                cout << "-------------------------------------------" << endl;
                ada = true;
                in << "Judul buku: " << dataBuku[i].judul << endl;
                in << "-------------------------------------------" << endl;
            }
        }
        if (!ada)
        {
            cout << "Tidak ada Data buku dengan judul " << inJudul << endl;
        }
        in.close();
        cout << "Hasil pencarian telah disimpan di file hasil_cari_judul.txt" << endl;
    }

    void cariStok(){
        bool ada = false ;
        cout << "\nMencari Data buku berdasarkan stok kurang dari " << endl;
        cout <<"Masukkan stok: ";
        cin >> inStok;

        for (int i = 0; i < jumlahData; i++)
        {
            if (inStok >= dataBuku[i].stok)
            {
                cout << "Nomor buku: " << dataBuku[i].no << endl;
                cout << "Judul buku: " << dataBuku[i].judul << endl;
                cout << "Penulis buku: " << dataBuku[i].penulis << endl;
                cout << "Stok buku: " << dataBuku[i].stok << endl;
                cout << "-------------------------------------------" << endl;
                ada = true;
            }
        }
        if (!ada)
        {
            cout << "Tidak ada Data buku berdasarkan stok " << inStok << endl;
        }
    }

    void cariIndex(){
        int temp;
        int max = 0;
        cout << "\nMencari Data buku berdasarkan index" << endl;
        for (int i = 0; i < jumlahData; i++)
        {
            if (max < dataBuku[i].stok)
            {
                max = dataBuku[i].stok;
                temp = i;
            }
        }
                cout << "Nomor buku: " << dataBuku[temp].no << endl;
                cout << "Judul buku: " << dataBuku[temp].judul << endl;
                cout << "Penulis buku: " << dataBuku[temp].penulis << endl;
                cout << "Stok buku: " << dataBuku[temp].stok << endl;
    }

    void ascending(){
        cout << "Data buku telah diurutkan berdasarkan Judul buku secara ascending." << endl;
        cout << "-------------------------------------------" << endl;
        for (int i = 0; i < jumlahData - 1; i++)
        {
            for (int j = i + 1; j < jumlahData; j++)
            {
                if (dataBuku[i].judul > dataBuku[j].judul)
                {
                    swap(dataBuku[i], dataBuku[j]);
                }
            }
        }
        
        for (int i = 0; i < jumlahData; i++)
        {
            cout << "Nomor buku: " << dataBuku[i].no << endl;
            cout << "Judul buku: " << dataBuku[i].judul << endl;
            cout << "Penulis buku: " << dataBuku[i].penulis << endl;
            cout << "Stok buku: " << dataBuku[i].stok << endl;
            cout << "-------------------------------------------" << endl;
        }
    }

    void descending(){
        cout << "Data buku telah diurutkan berdasarkan Judul buku secara descending." << endl;
        cout << "-------------------------------------------" << endl;
        for (int i = 0; i < jumlahData - 1; i++)
        {
            for (int j = i + 1; j < jumlahData; j++)
            {
                if (dataBuku[i].judul < dataBuku[j].judul)
                {
                    swap(dataBuku[i], dataBuku[j]);
                }
            }
        }
        
        for (int i = 0; i < jumlahData; i++)
        {
            cout << "Nomor buku: " << dataBuku[i].no << endl;
            cout << "Judul buku: " << dataBuku[i].judul << endl;
            cout << "Penulis buku: " << dataBuku[i].penulis << endl;
            cout << "Stok buku: " << dataBuku[i].stok << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    
    void alur(){
        int pilihan;
        do
        {
        cout << "Investaris Perpustakaan" << endl;
        cout << "========================" << endl;
        cout << "1. Mencari Judul Buku Berdasarkan Penulis" << endl;
        cout << "2. Mencari Data Buku Berdasarkan Judul" << endl;
        cout << "3. Mencari Data Buku Berdasarkan Stok" << endl;
        cout << "4. Mencari Data Buku Berdasarkan Index" << endl;
        cout << "5. Mengurutkan Data Buku secara a-z" << endl; 
        cout << "6. Mengurutkan Data Buku secara z-a" << endl;
        cout << "7. Keluar" << endl;
        cout << "========================" << endl;
            cout << "Masukkan pilihan: ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                cariJudul();
                break;
            case 2:
                cariData();
                break;
            case 3:
                cariStok();
                break;
            case 4:
                cariIndex();
                break;
            case 5:
                ascending();
                break;
            case 6:
                descending();
                break;
            case 7:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
            }
        } while (pilihan != 7);
    }
};

int main() {
    Perpus perpustakaan;
    perpustakaan.ambilData();
    perpustakaan.alur();
    cout << endl;
    cout << "Program selesai." << endl;

    return 0;
}

