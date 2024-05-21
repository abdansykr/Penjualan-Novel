#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#include "089.h"
#include "115.h"
#include "117.h"
#include "array1d.h"
#include "bestseller.h"
#include "binary.h"
#include "binaryrekomen.h"
#include "dll.h"
#include "dll_pegawai.h"
#include "dll_pelanggan.h"
#include "dll_penjualan.h"
#include "dll_transaksi.h"
#include "ktp.h"
#include "novel.h"
#include "pelanggan.h"
//#include "riwayatplg.h"
#include "kurir.h"
#include "penjualan.h"
// #include "rekomendasinvl.h"
#include "sll.h"
#include "transaksi.h"

class APP {
  friend ostream &operator<<(ostream &, const APP &);
  friend istream &operator>>(istream &, APP &);

public:
  DoublyLinkedListPegawai<PEGAWAI> *pegawai;
  DoublyLinkedListPelanggan<PELANGGAN> *pelanggan;
  DoublyLinkedList<Novel> *novel = NULL;
  DoublyLinkedListPenjualan<PENJUALAN> *penjualan = NULL;
  DoublyLinkedListTransaksi<TRANSAKSI> *transaksi = NULL;
  BinarySearchTree riwayatpelanggan;
  BinarySearchTreeRekomen rekomenNovel;

  // TRANSAKSI tf[100];
  Novel data[100];
  bool isLogin = false;
  bool isAdmin = false;
  bool isKasir = false;

  void adminTambahPegawai();
  void adminLihatPegawai();
  void adminTambahNovel();
  void adminLihatNovel();
  void adminTambahPenjualan();
  void adminLihatPenjualan();
  void adminCatatTransaksi();
  void adminLihatTransaksi();
  void adminSortingNovelByIdOrPrice();
  void adminSortingNovelByNameOrPenerbit();
  void adminDiskon();
  void adminBestSeller();

  void kasirTambahPelanggan();
  void kasirLihatPelanggan();
  void kasirTambahTransaksi();
  void kasirLihatTransaksi();
  void kasirTambahNovel();
  void kasirLihatNovel();
  void kasirTambahRekomendasi();
  void kasirLihatRekomendasi();
  void kasirLihatRiwayatPelanggan();
  void kasirTambahPenjualan();
  void kasirCatatTransaksi();
  void kasirLihatPenjualan();
  void kasirSortingNovelByIdOrPrice();
  void kasirSortingNovelByNameOrPenerbit();
  void kasirDiskon();
  void kasirBestSeller();
};

void APP::adminTambahPegawai() {
  PEGAWAI p;
  int jumlah;
  string nikpeg;
  string nama;
  string divisi;
  string usia;
  cout << "Banyak Data : ";
  cin >> jumlah;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              INPUT DATA PEGAWAI          |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jumlah; i++) {
    cout << "  Masukkan NIK         : ";
    cin >> nikpeg;
    cout << "  Masukkan Nama        : ";
    cin >> nama;
    cout << "  Masukkan Divisi      : ";
    cin >> divisi;
    cout << "  Masukkan Usia        : ";
    cin >> usia;
    p.setAll(nikpeg, nama, divisi, usia);
    pegawai->add(p);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              INPUT DATA PEGAWAI          |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::adminLihatPegawai() {
  int plh = 10;
  int pilih;
  while (plh != 0) {
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              ADMIN - DATA PEGAWAI        |" << endl;
    cout << "+==========================================+" << endl;
    cout << "Data Pegawai : " << pegawai->getLen() << endl;
    pegawai->cetakMaju();
    cout << endl << endl;

    cout << "+=========================================+" << endl;
    cout << "|              Menu Sorting               |" << endl;
    cout << "+=========================================+" << endl;
    cout << "| 1. Sorting berdasarkan ID Asc           |" << endl;
    cout << "| 2. Sorting berdasarkan ID Desc          |" << endl;
    cout << "| 3. Sorting berdasarkan Usia Asc         |" << endl;
    cout << "| 4. Sorting berdasarkan Usia Desc        |" << endl;
    cout << "| 5. Kembali ke menu awal                 |" << endl;
    cout << "+=========================================+" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1) {
      pegawai->sortByIdAsc();
      pegawai->cetakMaju();
    } else if (pilih == 2) {
      pegawai->sortByIdDesc();
      pegawai->cetakMaju();
    } else if (pilih == 3) {
      pegawai->sortByUsiaAsc();
      pegawai->cetakMaju();
    } else if (pilih == 4) {
      pegawai->sortByUsiaDesc();
      pegawai->cetakMaju();
    } else if (pilih == 5) {
      system("clear");
      return;
    }
    cout << endl;
  }
}

void APP::adminTambahNovel() {
  Novel n;
  int jumlah;
  string idNovel;
  string namaNovel;
  string harga;
  string namaPenerbit;
  string namaPengarang;
  cout << "Banyak Data : ";
  cin >> jumlah;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|          ADMIN - INPUT DATA NOVEL        |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jumlah; i++) {
    cout << "  Masukkan ID Novel          : ";
    cin >> idNovel;
    cout << "  Masukkan Nama Novel        : ";
    cin >> namaNovel;
    cout << "  Masukkan Harga             : ";
    cin >> harga;
    cout << "  Masukkan Nama Penerbit     : ";
    cin >> namaPenerbit;
    cout << "  Masukkan Nama Pengarang    : ";
    cin >> namaPengarang;
    n.setAll(idNovel, namaNovel, harga, namaPenerbit, namaPengarang);
    novel->add(n);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|         ADMIN - INPUT DATA NOVEL         |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::adminLihatNovel() {
  int plh = 10;
  int pilih;
  while (plh != 0) {
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              ADMIN - DATA NOVEL          |" << endl;
    cout << "+==========================================+" << endl;
    cout << "Data Novel : " << novel->getLen() << endl;
    novel->cetakMaju();
    cout << endl << endl;

    cout << "+=========================================+" << endl;
    cout << "|              Menu Sorting               |" << endl;
    cout << "+=========================================+" << endl;
    cout << "| 1. Sorting berdasarkan ID Asc           |" << endl;
    cout << "| 2. Sorting berdasarkan ID Desc          |" << endl;
    cout << "| 3. Sorting berdasarkan harga Asc        |" << endl;
    cout << "| 4. Sorting berdasarkan harga Desc       |" << endl;
    cout << "| 5. Kembali ke menu awal                 |" << endl;
    cout << "+=========================================+" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1) {
      novel->sortByIdAsc();
      novel->cetakMaju();
    } else if (pilih == 2) {
      novel->sortByIdDesc();
      novel->cetakMaju();
    } else if (pilih == 3) {
      novel->sortByHargaAsc();
      novel->cetakMaju();
    } else if (pilih == 4) {
      novel->sortByHargaDesc();
      novel->cetakMaju();
    } else if (pilih == 5) {
      system("clear");
      return;
    }
  }

  cout << endl;
}

void APP::adminTambahPenjualan() {
  PENJUALAN p;
  string id;
  string nama;
  string jumlah;
  string total;
  int jml;
  cout << "Banyak Data : ";
  cin >> jml;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              INPUT DATA PENJUALAN        |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jml; i++) {
    cout << "  Masukkan ID          : ";
    cin >> id;
    cout << "  Masukkan Nama        : ";
    cin >> nama;
    cout << "  Masukkan Jumlah      : ";
    cin >> jumlah;
    cout << "  Masukkan Total       : ";
    cin >> total;
    p.setAll(id, nama, jumlah, total);
    penjualan->add(p);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              INPUT DATA PENJUALAN        |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::adminLihatPenjualan() {
  system("clear");
  int plh = 10;
  int pilih;
  while (plh != 0) {
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|          KASIR - DATA PENJUALAN          |" << endl;
    cout << "+==========================================+" << endl;
    cout << "Data penjualan : " << penjualan->getLen() << endl;
    penjualan->cetakMaju();
    cout << endl << endl;

    cout << "+=========================================+" << endl;
    cout << "|              Menu Sorting               |" << endl;
    cout << "+=========================================+" << endl;
    cout << "| 1. Sorting berdasarkan Nama Asc         |" << endl;
    cout << "| 2. Sorting berdasarkan Nama Desc        |" << endl;
    cout << "| 3. Sorting berdasarkan total Asc        |" << endl;
    cout << "| 4. Sorting berdasarkan total Desc       |" << endl;
    cout << "| 5. Kembali ke menu awal                 |" << endl;
    cout << "+=========================================+" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1) {
      penjualan->sortByNamaAsc();
      penjualan->cetakMaju();
    } else if (pilih == 2) {
      penjualan->sortByNamaDesc();
      penjualan->cetakMaju();
    } else if (pilih == 3) {
      penjualan->sortByTotalAsc();
      penjualan->cetakMaju();
    } else if (pilih == 4) {
      penjualan->sortByTotalDesc();
      penjualan->cetakMaju();
    } else if (pilih == 5) {
      system("clear");
      return;
    }
  }
}

void APP::adminCatatTransaksi() {
  TRANSAKSI p;
  int jml;
  string id;
  string nama;
  string jumlah;
  cout << "Banyak Data : ";
  cin >> jml;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              CATAT DATA TRANSAKSI        |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jml; i++) {
    cout << "  Masukkan ID          : ";
    cin >> id;
    cout << "  Masukkan Nama        : ";
    cin >> nama;
    cout << "  Masukkan Jumlah      : ";
    cin >> jumlah;
    p.setAll(id, nama, jumlah);
    transaksi->add(p);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              CATAT DATA TRANSAKSI        |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::adminLihatTransaksi() {
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              DATA TRANSAKSI              |" << endl;
  cout << "+==========================================+" << endl;

  for (int i = transaksi->getLen(); i > 0; i--) {
    transaksi->cetakMaju();
  }
}

void APP::adminSortingNovelByIdOrPrice() {
  int b;
  Novel dataNovel;

  cout << "Berapa Novel yang Ingin Dijual : ";
  cin >> b;
  for (int i = 0; i < b; i++) {
    cout << "+=======================================+" << endl;
    cout << "| Masukkan Data novel yang Ingin Dijual |" << endl;
    cout << "+=======================================+" << endl;
    cout << "ID Novel       : ";
    cin >> data[i].idNovel;
    cout << "Nama Novel     : ";
    cin >> data[i].namaNovel;
    cout << "Harga Novel    : ";
    cin >> data[i].harga;
    cout << "Nama Penerbit  : ";
    cin >> data[i].namaPenerbit;
    cout << "Nama Pengarang : ";
    cin >> data[i].namaPengarang;
    cout << endl;
  }
  cout << endl;
  int pilih;
  string idNovel_temp, namaNovel_temp, harga_temp, namaPenerbit_temp,
      namaPengarang_temp;
  SORTING dataSORTING;

  cout << "+==============================+" << endl;
  cout << "|         Menu Sorting         |" << endl;
  cout << "+==============================+" << endl;
  cout << "| 1. Sorting berdasarkan ID    |" << endl;
  cout << "| 2. Sorting berdasarkan harga |" << endl;
  cout << "+==============================+" << endl;
  cout << "Masukkan Pilihan Anda : ";
  cin >> pilih;

  if (pilih == 1) {
    for (int i = 0; i < b; i++) {
      for (int j = 0; j < b - 1; j++) {
        if (data[j].idNovel > data[j + 1].idNovel) {
          idNovel_temp = data[j].idNovel;
          namaNovel_temp = data[j].namaNovel;
          harga_temp = data[j].harga;
          namaPenerbit_temp = data[j].namaPenerbit;
          namaPengarang_temp = data[j].namaPengarang;

          data[j].idNovel = data[j + 1].idNovel;
          data[j].namaNovel = data[j + 1].namaNovel;
          data[j].harga = data[j + 1].harga;
          data[j].namaPenerbit = data[j + 1].namaPenerbit;
          data[j].namaPengarang = data[j + 1].namaPengarang;

          data[j + 1].idNovel = idNovel_temp;
          data[j + 1].namaNovel = namaNovel_temp;
          data[j + 1].harga = harga_temp;
          data[j + 1].namaPenerbit = namaPenerbit_temp;
          data[j + 1].namaPengarang = namaPengarang_temp;
        }
      }
    }
  } else if (pilih == 2) {
    for (int i = 0; i < b; i++) {
      for (int j = 0; j < b - 1; j++) {
        if (data[j].harga > data[j + 1].harga) {
          idNovel_temp = data[j].idNovel;
          namaNovel_temp = data[j].namaNovel;
          harga_temp = data[j].harga;
          namaPenerbit_temp = data[j].namaPenerbit;
          namaPengarang_temp = data[j].namaPengarang;

          data[j].idNovel = data[j + 1].idNovel;
          data[j].namaNovel = data[j + 1].namaNovel;
          data[j].harga = data[j + 1].harga;
          data[j].namaPenerbit = data[j + 1].namaPenerbit;
          data[j].namaPengarang = data[j + 1].namaPengarang;

          data[j + 1].idNovel = idNovel_temp;
          data[j + 1].namaNovel = namaNovel_temp;
          data[j + 1].harga = harga_temp;
          data[j + 1].namaPenerbit = namaPenerbit_temp;
          data[j + 1].namaPengarang = namaPengarang_temp;
        }
      }
    }
  }
  cout << endl;
  DoublyLinkedList<Novel> list;
  Novel buffer;
  char pilih2;
  cout << "Cetak dengan" << endl;
  cout << "1. Array 1D Dinamis" << endl;
  cout << "2. Doubly Linked List" << endl;
  cout << "Pilih : ";
  cin >> pilih2;
  cout << "+================================================================="
          "=====+"
       << endl;
  cout << "|                            Hasil Sorting                        "
          "     |"
       << endl;
  cout << "+================================================================="
          "=====+"
       << endl;
  cout << "| ID Novel | Nama Novel | Harga Novel | Nama Penerbit | Nama "
          "Pengarang |"
       << endl;
  cout << "+================================================================="
          "=====+"
       << endl;
  switch (pilih2) {
  case '1':
    for (int i = 0; i < b; i++) {
      cout << data[i].idNovel << "         " << data[i].namaNovel << "         "
           << data[i].harga << "        " << data[i].namaPenerbit
           << "          " << data[i].namaPengarang << "         " << endl;
      cout << "+============================================================="
              "=========+"
           << endl;
    }
    break;
  case '2':
    for (int i = 0; i < b; i++) {
      buffer.setAll(data[i].idNovel, data[i].namaNovel, data[i].harga,
                    data[i].namaPenerbit, data[i].namaPengarang);
      list.add(buffer);
    }
    list.cetakMundur();
    break;
  default:
    cout << "Tidak tersedia" << endl;
    exit(1);
  }
}

void APP::adminSortingNovelByNameOrPenerbit() {
  int b = 0;
  int pilih = 0;
  cout << "\n+========================================+" << endl;
  cout << "|             Menu Searching             |" << endl;
  cout << "+========================================+" << endl;
  cout << "| 1. Searching Berdasarkan Nama Novel    |" << endl;
  cout << "| 2. Searching Berdasarkan Nama Penerbit |" << endl;
  cout << "+========================================+" << endl;
  cout << "Masukkan Pilihan Anda : ";
  cin >> pilih;
  if (pilih == 1) {
    string namaNovel;
    cout << "Masukkan Nama Novel yang Ingin Dicari : ";
    cin >> namaNovel;
    cout << endl;
    for (int i = 0; i < b; i++) {
      if (data[i].namaNovel == namaNovel) {
        cout << "Novel Ditemukan!!!" << endl;
        cout << "Nama Novel : " << data[i].namaNovel << endl;
        cout << "ID Novel : " << data[i].idNovel << endl;
        cout << "Harga Novel : " << data[i].harga << endl;
        cout << "Nama Penerbit : " << data[i].namaPenerbit << endl;
        cout << "Nama Pengarang : " << data[i].namaPengarang << endl;

        break;
      }
    }
  } else if (pilih == 2) {
    string namaPenerbit;
    cout << "Masukkan Nama Penerbit : ";
    cin.ignore();
    getline(cin, namaPenerbit);
    for (int i = 0; i < b; i++) {
      if (data[i].namaPenerbit == namaPenerbit) {
        cout << "Buku Ditemukan!!!" << endl;
        cout << "Nama Penerbit : " << data[i].namaPenerbit << endl;
        cout << "Nama Novel : " << data[i].namaNovel << endl;
        cout << "ID Novel : " << data[i].idNovel << endl;
        cout << "Harga Novel : " << data[i].harga << endl;
        cout << "Nama Pengarang : " << data[i].namaPengarang << endl;

        break;
      }
    }
    cout << endl;
  }

  char pil;
  cout << "\n==================";
  cout << " Cetak Struk ? (Y) ";
  cout << "===================" << endl;
  cout << "Masukkan pilihan : ";
  cin >> pil;
  if (pil == 'Y')
    ;

  ofstream cetak;
  cetak.open("StrukHarga.txt");
  cetak << "+================================================================"
           "===+"
        << endl;
  cetak << "|                          Struk Pembelian                       "
           "   |"
        << endl;
  cetak << "+================================================================"
           "===+"
        << endl;
  cetak << "| ID Buku | Nama Buku | Harga Buku | Nama Penerbit | Nama "
           "Pengarang |"
        << endl;
  cetak << "+================================================================"
           "===+"
        << endl;
  for (int i = 0; i < b; i++) {
    cetak << data[i].idNovel << "        " << data[i].namaNovel << "        "
          << data[i].harga << "        " << data[i].namaPenerbit << "        "
          << data[i].namaPengarang << "        " << endl;
  }
  cout << endl;
}

void APP::adminDiskon() {
  int total_belanja, harga_akhir;
  DISKON dataDISKON;

  cout << "\n=========================================" << endl;
  cout << "##     VOUCHER DISKON BELANJA NOVEL    ##" << endl;
  cout << "=========================================" << endl;
  cout << endl;

  cout << "Total Belanja: Rp.";
  cin >> total_belanja;
  cout << endl;

  if ((total_belanja >= 10000) && (total_belanja < 50000)) {
    harga_akhir = total_belanja - (0.1 * total_belanja);
    cout << "Selamat, anda mendapat diskon 10%" << endl;
  } else if ((total_belanja >= 50000) && (total_belanja < 100000)) {
    harga_akhir = total_belanja - (0.2 * total_belanja);
    cout << "Selamat, anda mendapat diskon 20%" << endl;
  } else if (total_belanja >= 100000) {
    harga_akhir = total_belanja - (0.3 * total_belanja);
    cout << "Selamat, anda mendapat diskon 25%" << endl;
  } else {
    harga_akhir = total_belanja;
  }

  cout << "Total bayar: Rp." << harga_akhir << endl;
}

void APP::adminBestSeller() {
  BESTSELLER dataBESSELLER;
  char nama[15], jenis[15];
  int novel, stock, harga, total, jumbel, barang;

  cout << ("-------------------------------------") << endl;
  cout << (" TOKO NOVEL ");
  cout << ("-------------------------------------");
  cout << (" KODE BARANG ");
  cout << ("-------------------------------------");
  cout << ("1. Novel Tere Liye RP.100000 ");
  cout << ("2. Novel Anak Singkong RP.99000 ");
  cout << ("3.This Time Tomorrow RP.80000 ");
  cout << ("4.Laut Bercerita  RP.110000 ");
  cout << ("-------------------------------------");
  cout << ("Input Jenis Novel : ");
  cin >> novel;
  cout << ("Input Stock Barang: ");
  cin >> stock;
  cout << "Input Harga Barang : ";
  cin >> harga;
  switch (novel) {
  case 1:
    cout << (jenis, "Novel Tere Liye");
    harga = 100000;
    break;
  case 2:
    cout << (jenis, "Novel Anak Singkong");
    harga = 99000;
    break;
  case 3:
    cout << (jenis, "This Time Tomorrow");
    harga = 80000;
    break;
  case 4:
    cout << (jenis, "Laut Bercerita");
    harga = 110000;
    break;
  default:
    cout << (jenis, "Anda Salah Kode");
    harga = 10;
    break;
  }
  // harga=stockharga;
  cout << "===============================" << endl;
  cout << " STOCK DAN HARGA BARANG " << endl;
  cout << "Nama Pembeli : " << nama << endl;
  cout << "Nama Barang : " << barang << endl;
  cout << "Harga Barang : " << harga << endl;

  cout << "jumlah Stock Barang : " << jumbel << endl;
  cout << "Total : " << total;
}

void APP::kasirTambahPelanggan() {
  PELANGGAN p;
  int jumlah;
  string id;
  string nama;
  string alamat;
  string usia;
  cout << "Banyak Data : ";
  cin >> jumlah;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              INPUT DATA PELANGGAN        |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jumlah; i++) {
    cout << "  Masukkan ID          : ";
    cin >> id;
    cout << "  Masukkan Nama        : ";
    cin >> nama;
    cout << "  Masukkan Alamat      : ";
    cin >> alamat;
    cout << "  Masukkan Usia        : ";
    cin >> usia;
    p.setAll(id, nama, alamat, usia);
    pelanggan->add(p);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              INPUT DATA PELANGGAN        |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::kasirLihatPelanggan() {
  system("clear");
  int plh = 10;
  int pilih;
  while (plh != 0) {
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|          KASIR - DATA PELANGGAN          |" << endl;
    cout << "+==========================================+" << endl;
    cout << "Data Pelanggan : " << pelanggan->getLen() << endl;
    pelanggan->cetakMaju();
    cout << endl << endl;

    cout << "+=========================================+" << endl;
    cout << "|              Menu Sorting               |" << endl;
    cout << "+=========================================+" << endl;
    cout << "| 1. Sorting berdasarkan ID Asc           |" << endl;
    cout << "| 2. Sorting berdasarkan ID Desc          |" << endl;
    cout << "| 3. Sorting berdasarkan nama Asc         |" << endl;
    cout << "| 4. Sorting berdasarkan nama Desc        |" << endl;
    cout << "| 5. Kembali ke menu awal                 |" << endl;
    cout << "+=========================================+" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1) {
      pelanggan->sortByIdAsc();
      pelanggan->cetakMaju();
    } else if (pilih == 2) {
      pelanggan->sortByIdDesc();
      pelanggan->cetakMaju();
    } else if (pilih == 3) {
      pelanggan->sortByNamaAsc();
      pelanggan->cetakMaju();
    } else if (pilih == 4) {
      pelanggan->sortByNamaDesc();
      pelanggan->cetakMaju();
    } else if (pilih == 5) {
      system("clear");
      return;
    }
  }
}

void APP::kasirTambahNovel() {
  Novel n;
  int jumlah;
  string idNovel;
  string namaNovel;
  string harga;
  string namaPenerbit;
  string namaPengarang;
  cout << "Banyak Data : ";
  cin >> jumlah;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|         KASIR - INPUT DATA NOVEL         |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jumlah; i++) {
    cout << "  Masukkan ID Novel          : ";
    cin >> idNovel;
    cout << "  Masukkan Nama Novel        : ";
    cin >> namaNovel;
    cout << "  Masukkan Harga             : ";
    cin >> harga;
    cout << "  Masukkan Nama Penerbit     : ";
    cin >> namaPenerbit;
    cout << "  Masukkan Nama Pengarang    : ";
    cin >> namaPengarang;
    n.setAll(idNovel, namaNovel, harga, namaPenerbit, namaPengarang);
    novel->add(n);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|         KASIR - INPUT DATA NOVEL         |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::kasirLihatNovel() {
  int plh = 10;
  int pilih;
  while (plh != 0) {
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              KASIR - DATA NOVEL          |" << endl;
    cout << "+==========================================+" << endl;
    cout << "Data Novel : " << novel->getLen() << endl;
    novel->cetakMaju();
    cout << endl << endl;

    cout << "+=========================================+" << endl;
    cout << "|              Menu Sorting               |" << endl;
    cout << "+=========================================+" << endl;
    cout << "| 1. Sorting berdasarkan ID Asc           |" << endl;
    cout << "| 2. Sorting berdasarkan ID Desc          |" << endl;
    cout << "| 3. Sorting berdasarkan harga Asc        |" << endl;
    cout << "| 4. Sorting berdasarkan harga Desc       |" << endl;
    cout << "| 5. Kembali ke menu awal                 |" << endl;
    cout << "+=========================================+" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1) {
      novel->sortByIdAsc();
      novel->cetakMaju();
    } else if (pilih == 2) {
      novel->sortByIdDesc();
      novel->cetakMaju();
    } else if (pilih == 3) {
      novel->sortByHargaAsc();
      novel->cetakMaju();
    } else if (pilih == 4) {
      novel->sortByHargaDesc();
      novel->cetakMaju();
    } else if (pilih == 5) {
      system("clear");
      return;
    }
  }

  cout << endl;
}

void APP::kasirTambahRekomendasi() {
  Novel n;
  int jumlah;
  string idNovel;
  string namaNovel;
  string harga;
  string namaPenerbit;
  string namaPengarang;
  cout << "Banyak Data : ";
  cin >> jumlah;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|         KASIR - INPUT DATA NOVEL         |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jumlah; i++) {
    cout << "  Masukkan ID Novel          : ";
    cin >> idNovel;
    cout << "  Masukkan Nama Novel        : ";
    cin >> namaNovel;
    cout << "  Masukkan Harga             : ";
    cin >> harga;
    cout << "  Masukkan Nama Penerbit     : ";
    cin >> namaPenerbit;
    cout << "  Masukkan Nama Pengarang    : ";
    cin >> namaPengarang;
    n.setAll(idNovel, namaNovel, harga, namaPenerbit, namaPengarang);
    rekomenNovel.add(n);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|         KASIR - INPUT DATA NOVEL         |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::kasirLihatRekomendasi() { rekomenNovel.printPreOrder(); }

void APP::kasirLihatRiwayatPelanggan() { riwayatpelanggan.printPreOrder(); }

void APP::kasirTambahPenjualan() {
  PENJUALAN p;
  string id;
  string nama;
  string alamat;
  string usia;
  string jumlah;
  string total;
  PELANGGAN pel;
  int jml;
  int total_belanja, harga_akhir;
  DISKON dataDISKON;
  cout << "Banyak Data : ";
  cin >> jml;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              INPUT DATA PENJUALAN        |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jml; i++) {
    cout << "  Masukkan ID                   : ";
    cin >> id;
    cout << "  Masukkan Nama                 : ";
    cin >> nama;
    cout << "  Masukkan Alamat Pelanggan     : ";
    cin >> alamat;
    cout << "  Masukkan Usia Pelanggan       : ";
    cin >> usia;
    cout << "  Masukkan Jumlah               : ";
    cin >> jumlah;
    cout << "  Masukkan Total                : ";
    cin >> total;

    pel.setAll(id, nama, alamat, usia);
    p.setAll(id, nama, jumlah, total);
    penjualan->add(p);
    riwayatpelanggan.add(pel);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              INPUT DATA PENJUALAN        |" << endl;
    cout << "+==========================================+" << endl;
  }
  cout << "\n=========================================" << endl;
  cout << "##     VOUCHER DISKON BELANJA NOVEL    ##" << endl;
  cout << "=========================================" << endl;
  cout << endl;

  cout << "Total Belanja: Rp. ";
  cin >> total_belanja;
  cout << endl;
  cout << "Total bayar: Rp." << harga_akhir << endl;
  system("clear");

  if ((total_belanja >= 10000) && (total_belanja < 50000)) {
    harga_akhir = total_belanja - (0.1 * total_belanja);
    cout << "Selamat, anda mendapat diskon 10%" << endl;
  } else if ((total_belanja >= 50000) && (total_belanja < 100000)) {
    harga_akhir = total_belanja - (0.2 * total_belanja);
    cout << "Selamat, anda mendapat diskon 20%" << endl;
  } else if (total_belanja >= 100000) {
    harga_akhir = total_belanja - (0.3 * total_belanja);
    cout << "Selamat, anda mendapat diskon 25%" << endl;
  } else {
    harga_akhir = total_belanja;
  }

  // cout << "Total bayar: Rp." << harga_akhir << endl;
}

void APP::kasirLihatPenjualan() {
  system("clear");
  int plh = 10;
  int pilih;
  while (plh != 0) {
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|          KASIR - DATA PENJUALAN          |" << endl;
    cout << "+==========================================+" << endl;
    cout << "Data penjualan : " << penjualan->getLen() << endl;
    penjualan->cetakMaju();
    cout << endl << endl;

    cout << "+=========================================+" << endl;
    cout << "|              Menu Sorting               |" << endl;
    cout << "+=========================================+" << endl;
    cout << "| 1. Sorting berdasarkan Nama Asc         |" << endl;
    cout << "| 2. Sorting berdasarkan Nama Desc        |" << endl;
    cout << "| 3. Sorting berdasarkan total Asc        |" << endl;
    cout << "| 4. Sorting berdasarkan total Desc       |" << endl;
    cout << "| 5. Kembali ke menu awal                 |" << endl;
    cout << "+=========================================+" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1) {
      penjualan->sortByNamaAsc();
      penjualan->cetakMaju();
    } else if (pilih == 2) {
      penjualan->sortByNamaDesc();
      penjualan->cetakMaju();
    } else if (pilih == 3) {
      penjualan->sortByTotalAsc();
      penjualan->cetakMaju();
    } else if (pilih == 4) {
      penjualan->sortByTotalDesc();
      penjualan->cetakMaju();
    } else if (pilih == 5) {
      system("clear");
      return;
    }
  }
}

void APP::kasirCatatTransaksi() {
  TRANSAKSI p;
  int jml;
  string id;
  string nama;
  string jumlah;
  cout << "Banyak Data : ";
  cin >> jml;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              CATAT DATA TRANSAKSI        |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jml; i++) {
    cout << "  Masukkan ID          : ";
    cin >> id;
    cout << "  Masukkan Nama        : ";
    cin >> nama;
    cout << "  Masukkan Jumlah      : ";
    cin >> jumlah;
    p.setAll(id, nama, jumlah);
    transaksi->add(p);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              CATAT DATA TRANSAKSI        |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::kasirLihatTransaksi() {
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              DATA TRANSAKSI              |" << endl;
  cout << "+==========================================+" << endl;

  for (int i = transaksi->getLen(); i > 0; i--) {
    transaksi->cetakMaju();
  }
}

void APP::kasirTambahTransaksi() {
  TRANSAKSI p;
  int jml;
  string id;
  string nama;
  string jumlah;
  cout << "Banyak Data : ";
  cin >> jml;
  system("clear");
  cout << "+==========================================+" << endl;
  cout << "|              INPUT DATA TRANSAKSI        |" << endl;
  cout << "+==========================================+" << endl;
  for (int i = 0; i < jml; i++) {
    cout << "  Masukkan ID          : ";
    cin >> id;
    cout << "  Masukkan Nama        : ";
    cin >> nama;
    cout << "  Masukkan Jumlah      : ";
    cin >> jumlah;
    p.setAll(id, nama, jumlah);
    transaksi->add(p);
    system("clear");
    cout << "+==========================================+" << endl;
    cout << "|              INPUT DATA TRANSAKSI        |" << endl;
    cout << "+==========================================+" << endl;
  }
}

void APP::kasirSortingNovelByIdOrPrice() {
  int b;
  Novel dataNovel;

  cout << "Berapa Novel yang Ingin Dijual : ";
  cin >> b;
  for (int i = 0; i < b; i++) {
    cout << "+=======================================+" << endl;
    cout << "| Masukkan Data novel yang Ingin Dijual |" << endl;
    cout << "+=======================================+" << endl;
    cout << "ID Novel       : ";
    cin >> data[i].idNovel;
    cout << "Nama Novel     : ";
    cin >> data[i].namaNovel;
    cout << "Harga Novel    : ";
    cin >> data[i].harga;
    cout << "Nama Penerbit  : ";
    cin >> data[i].namaPenerbit;
    cout << "Nama Pengarang : ";
    cin >> data[i].namaPengarang;
    cout << endl;
  }
  cout << endl;
  int pilih;
  string idNovel_temp, namaNovel_temp, harga_temp, namaPenerbit_temp,
      namaPengarang_temp;
  SORTING dataSORTING;

  cout << "+==============================+" << endl;
  cout << "|         Menu Sorting         |" << endl;
  cout << "+==============================+" << endl;
  cout << "| 1. Sorting berdasarkan ID    |" << endl;
  cout << "| 2. Sorting berdasarkan harga |" << endl;
  cout << "+==============================+" << endl;
  cout << "Masukkan Pilihan Anda : ";
  cin >> pilih;

  if (pilih == 1) {
    for (int i = 0; i < b; i++) {
      for (int j = 0; j < b - 1; j++) {
        if (data[j].idNovel > data[j + 1].idNovel) {
          idNovel_temp = data[j].idNovel;
          namaNovel_temp = data[j].namaNovel;
          harga_temp = data[j].harga;
          namaPenerbit_temp = data[j].namaPenerbit;
          namaPengarang_temp = data[j].namaPengarang;

          data[j].idNovel = data[j + 1].idNovel;
          data[j].namaNovel = data[j + 1].namaNovel;
          data[j].harga = data[j + 1].harga;
          data[j].namaPenerbit = data[j + 1].namaPenerbit;
          data[j].namaPengarang = data[j + 1].namaPengarang;

          data[j + 1].idNovel = idNovel_temp;
          data[j + 1].namaNovel = namaNovel_temp;
          data[j + 1].harga = harga_temp;
          data[j + 1].namaPenerbit = namaPenerbit_temp;
          data[j + 1].namaPengarang = namaPengarang_temp;
        }
      }
    }
  } else if (pilih == 2) {
    for (int i = 0; i < b; i++) {
      for (int j = 0; j < b - 1; j++) {
        if (data[j].harga > data[j + 1].harga) {
          idNovel_temp = data[j].idNovel;
          namaNovel_temp = data[j].namaNovel;
          harga_temp = data[j].harga;
          namaPenerbit_temp = data[j].namaPenerbit;
          namaPengarang_temp = data[j].namaPengarang;

          data[j].idNovel = data[j + 1].idNovel;
          data[j].namaNovel = data[j + 1].namaNovel;
          data[j].harga = data[j + 1].harga;
          data[j].namaPenerbit = data[j + 1].namaPenerbit;
          data[j].namaPengarang = data[j + 1].namaPengarang;

          data[j + 1].idNovel = idNovel_temp;
          data[j + 1].namaNovel = namaNovel_temp;
          data[j + 1].harga = harga_temp;
          data[j + 1].namaPenerbit = namaPenerbit_temp;
          data[j + 1].namaPengarang = namaPengarang_temp;
        }
      }
    }
  }
  cout << endl;
  DoublyLinkedList<Novel> list;
  Novel buffer;
  char pilih2;
  cout << "Cetak dengan" << endl;
  cout << "1. Array 1D Dinamis" << endl;
  cout << "2. Doubly Linked List" << endl;
  cout << "Pilih : ";
  cin >> pilih2;
  cout << "+================================================================="
          "=====+"
       << endl;
  cout << "|                            Hasil Sorting                        "
          "     |"
       << endl;
  cout << "+================================================================="
          "=====+"
       << endl;
  cout << "| ID Novel | Nama Novel | Harga Novel | Nama Penerbit | Nama "
          "Pengarang |"
       << endl;
  cout << "+================================================================="
          "=====+"
       << endl;
  switch (pilih2) {
  case '1':
    for (int i = 0; i < b; i++) {
      cout << data[i].idNovel << "         " << data[i].namaNovel << "         "
           << data[i].harga << "        " << data[i].namaPenerbit
           << "          " << data[i].namaPengarang << "         " << endl;
      cout << "+============================================================="
              "=========+"
           << endl;
    }
    break;
  case '2':
    for (int i = 0; i < b; i++) {
      buffer.setAll(data[i].idNovel, data[i].namaNovel, data[i].harga,
                    data[i].namaPenerbit, data[i].namaPengarang);
      list.add(buffer);
    }
    list.cetakMundur();
    break;
  default:
    cout << "Tidak tersedia" << endl;
    exit(1);
  }
}

void APP::kasirSortingNovelByNameOrPenerbit() {
  int b = 0;
  int pilih = 0;
  cout << "\n+========================================+" << endl;
  cout << "|             Menu Searching             |" << endl;
  cout << "+========================================+" << endl;
  cout << "| 1. Searching Berdasarkan Nama Novel    |" << endl;
  cout << "| 2. Searching Berdasarkan Nama Penerbit |" << endl;
  cout << "+========================================+" << endl;
  cout << "Masukkan Pilihan Anda : ";
  cin >> pilih;
  if (pilih == 1) {
    string namaNovel;
    cout << "Masukkan Nama Novel yang Ingin Dicari : ";
    cin >> namaNovel;
    cout << endl;
    for (int i = 0; i < b; i++) {
      if (data[i].namaNovel == namaNovel) {
        cout << "Novel Ditemukan!!!" << endl;
        cout << "Nama Novel : " << data[i].namaNovel << endl;
        cout << "ID Novel : " << data[i].idNovel << endl;
        cout << "Harga Novel : " << data[i].harga << endl;
        cout << "Nama Penerbit : " << data[i].namaPenerbit << endl;
        cout << "Nama Pengarang : " << data[i].namaPengarang << endl;

        break;
      }
    }
  } else if (pilih == 2) {
    string namaPenerbit;
    cout << "Masukkan Nama Penerbit : ";
    cin.ignore();
    getline(cin, namaPenerbit);
    for (int i = 0; i < b; i++) {
      if (data[i].namaPenerbit == namaPenerbit) {
        cout << "Buku Ditemukan!!!" << endl;
        cout << "Nama Penerbit : " << data[i].namaPenerbit << endl;
        cout << "Nama Novel : " << data[i].namaNovel << endl;
        cout << "ID Novel : " << data[i].idNovel << endl;
        cout << "Harga Novel : " << data[i].harga << endl;
        cout << "Nama Pengarang : " << data[i].namaPengarang << endl;

        break;
      }
    }
    cout << endl;
  }

  char pil;
  cout << "\n==================";
  cout << " Cetak Struk ? (Y) ";
  cout << "===================" << endl;
  cout << "Masukkan pilihan : ";
  cin >> pil;
  if (pil == 'Y')
    ;

  ofstream cetak;
  cetak.open("StrukHarga.txt");
  cetak << "+================================================================"
           "===+"
        << endl;
  cetak << "|                          Struk Pembelian                       "
           "   |"
        << endl;
  cetak << "+================================================================"
           "===+"
        << endl;
  cetak << "| ID Buku | Nama Buku | Harga Buku | Nama Penerbit | Nama "
           "Pengarang |"
        << endl;
  cetak << "+================================================================"
           "===+"
        << endl;
  for (int i = 0; i < b; i++) {
    cetak << data[i].idNovel << "        " << data[i].namaNovel << "        "
          << data[i].harga << "        " << data[i].namaPenerbit << "        "
          << data[i].namaPengarang << "        " << endl;
  }
  cout << endl;
}

void APP::kasirDiskon() {
  int total_belanja, harga_akhir;
  DISKON dataDISKON;

  cout << "\n=========================================" << endl;
  cout << "##     VOUCHER DISKON BELANJA NOVEL    ##" << endl;
  cout << "=========================================" << endl;
  cout << endl;

  cout << "Total Belanja: Rp.";
  cin >> total_belanja;
  cout << endl;

  if ((total_belanja >= 10000) && (total_belanja < 50000)) {
    harga_akhir = total_belanja - (0.1 * total_belanja);
    cout << "Selamat, anda mendapat diskon 10%" << endl;
  } else if ((total_belanja >= 50000) && (total_belanja < 100000)) {
    harga_akhir = total_belanja - (0.2 * total_belanja);
    cout << "Selamat, anda mendapat diskon 20%" << endl;
  } else if (total_belanja >= 100000) {
    harga_akhir = total_belanja - (0.3 * total_belanja);
    cout << "Selamat, anda mendapat diskon 25%" << endl;
  } else {
    harga_akhir = total_belanja;
  }
  cout << "Total bayar: Rp." << harga_akhir;
}

void APP::kasirBestSeller() {
  BESTSELLER dataBESSELLER;
  char nama[15], jenis[15];
  int novel, stock, harga, total, jumbel, barang;

  cout << ("-------------------------------------") << endl;
  cout << (" TOKO NOVEL ");
  cout << ("-------------------------------------");
  cout << (" KODE BARANG ");
  cout << ("-------------------------------------");
  cout << ("1. Novel Tere Liye RP.100000 ");
  cout << ("2. Novel Anak Singkong RP.99000 ");
  cout << ("3.This Time Tomorrow RP.80000 ");
  cout << ("4.Laut Bercerita  RP.110000 ");
  cout << ("-------------------------------------");
  cout << ("Input Jenis Novel : ");
  cin >> novel;
  cout << ("Input Stock Barang: ");
  cin >> stock;
  cout << "Input Harga Barang : ";
  cin >> harga;
  switch (novel) {
  case 1:
    cout << (jenis, "Novel Tere Liye");
    harga = 100000;
    break;
  case 2:
    cout << (jenis, "Novel Anak Singkong");
    harga = 99000;
    break;
  case 3:
    cout << (jenis, "This Time Tomorrow");
    harga = 80000;
    break;
  case 4:
    cout << (jenis, "Laut Bercerita");
    harga = 110000;
    break;
  default:
    cout << (jenis, "Anda Salah Kode");
    harga = 10;
    break;
  }
  // harga=stockharga;
  cout << "===============================" << endl;
  cout << " STOCK DAN HARGA BARANG " << endl;
  cout << "Nama Pembeli : " << nama << endl;
  cout << "Nama Barang : " << barang << endl;
  cout << "Harga Barang : " << harga << endl;

  cout << "jumlah Stock Barang : " << jumbel << endl;
  cout << "Total : " << total;
}

istream &operator>>(istream &in, APP &out) {
mainapp:
  char pilih4, pilih3;
  cout << "-------------------------------------" << endl;
  cout << "---       Selamat Datang          ---" << endl;
  cout << "---   Aplikasi Penjualan Novel    ---" << endl;
  cout << "-------------------------------------" << endl;
  cout << "---  1. Admin" << endl;
  cout << "---  2. Kasir" << endl;
  cout << "Pilih : ";
  cin >> pilih4;
  switch (pilih4) {
  case '1': {
    cout << "-------------------------------------" << endl;
    cout << "---   Aplikasi Penjualan Novel    ---" << endl;
    cout << "---            Admin              ---" << endl;
    cout << "-------------------------------------" << endl;
    cout << "---  1. Daftar KTP" << endl;
    cout << "---  2. Login KTP" << endl;
    cout << "Pilih : ";
    cin >> pilih3;
    switch (pilih3) {
    case '1': {
      string tulisKTP[19];
      ofstream tulis;
      cin.ignore();
      cout << "Provinsi : ";
      getline(cin, tulisKTP[0]);
      cout << "Kabupaten/Kota : ";
      getline(cin, tulisKTP[1]);
      cout << "NIK : ";
      getline(cin, tulisKTP[2]);
      cout << "Nama : ";
      getline(cin, tulisKTP[3]);
      cout << "Tempat : ";
      getline(cin, tulisKTP[4]);
      cout << "Tanggal : ";
      getline(cin, tulisKTP[5]);
      cout << "Bulan : ";
      getline(cin, tulisKTP[6]);
      cout << "Tahun : ";
      getline(cin, tulisKTP[7]);
      cout << "Jenis Kelamin : ";
      getline(cin, tulisKTP[8]);
      cout << "Golongan Darah : ";
      getline(cin, tulisKTP[9]);
      cout << "Alamat : ";
      getline(cin, tulisKTP[10]);
      cout << "RT : ";
      getline(cin, tulisKTP[11]);
      cout << "RW : ";
      getline(cin, tulisKTP[12]);
      cout << "Kelurahan/Desa : ";
      getline(cin, tulisKTP[13]);
      cout << "Kecamatan : ";
      getline(cin, tulisKTP[14]);
      cout << "Agama : ";
      getline(cin, tulisKTP[15]);
      cout << "Status : ";
      getline(cin, tulisKTP[16]);
      cout << "Pekerjaan : ";
      getline(cin, tulisKTP[17]);
      cout << "Kewarganegaraan : ";
      getline(cin, tulisKTP[18]);
      tulis.open("inputktp.txt", ios::app);
      tulis << tulisKTP[0] << ",";
      tulis << tulisKTP[1] << ",";
      tulis << tulisKTP[2] << ",";
      tulis << tulisKTP[3] << ",";
      tulis << tulisKTP[4] << ",";
      tulis << tulisKTP[5] << ",";
      tulis << tulisKTP[6] << ",";
      tulis << tulisKTP[7] << ",";
      tulis << tulisKTP[8] << ",";
      tulis << tulisKTP[9] << ",";
      tulis << tulisKTP[10] << ",";
      tulis << tulisKTP[11] << ",";
      tulis << tulisKTP[12] << ",";
      tulis << tulisKTP[13] << ",";
      tulis << tulisKTP[14] << ",";
      tulis << tulisKTP[15] << ",";
      tulis << tulisKTP[16] << ",";
      tulis << tulisKTP[17] << ",";
      tulis << tulisKTP[18] << ",";
      tulis.close();
      tulis.open(tulisKTP[2] + "-admin.txt");
      tulis << tulisKTP[3];
      tulis.close();
      break;
    }
    case '2': {
      string nik, nama, password;
      ifstream baca;
      int login = 0;
      while (login < 5) {
        cout << "Masukkan NIK : ";
        cin >> nik;
        cout << "Masukkan Password : ";
        cin >> password;
        baca.open(nik + "-admin.txt");
        while (getline(baca, nama))
          ;
        if (baca.is_open() == true && password == nama) {
          out.isLogin = true;
          out.isAdmin = true;
          break;
        } else {
          cout << "Username/Password salah" << endl;
          login++;
        }
        baca.close();
      }
      if (login == 5) {
        cout << "Terlalu banyak login! Coba lagi nanti" << endl;
        exit(1);
      }
      break;
    }
    default:
      cout << "Tidak tersedia" << endl;
      exit(1);
    }
    break;
  }
  // End Case Untuk admin
  //---------------------
  // Case Untuk Kasir
  case '2': {
    system("clear");
    cout << "-------------------------------------" << endl;
    cout << "---   Aplikasi Penjualan Novel    ---" << endl;
    cout << "---            Kasir              ---" << endl;
    cout << "-------------------------------------" << endl;
    cout << "---  1. Daftar KTP" << endl;
    cout << "---  2. Login KTP" << endl;
    cout << "Pilih : ";
    cin >> pilih3;
    switch (pilih3) {
    case '1': {
      string tulisKTPKasir[7];
      ofstream tulisKasir;
      cin.ignore();
      cout << "NIK : ";
      getline(cin, tulisKTPKasir[0]);
      cout << "Nama : ";
      getline(cin, tulisKTPKasir[1]);
      cout << "Jenis Kelamin : ";
      getline(cin, tulisKTPKasir[2]);
      cout << "Alamat : ";
      getline(cin, tulisKTPKasir[3]);
      cout << "Agama : ";
      getline(cin, tulisKTPKasir[4]);
      cout << "Kewarganegaraan : ";
      getline(cin, tulisKTPKasir[5]);
      tulisKasir.open("inputktp-kasir.txt", ios::app);
      tulisKasir << tulisKTPKasir[0] << ",";
      tulisKasir << tulisKTPKasir[1] << ",";
      tulisKasir << tulisKTPKasir[2] << ",";
      tulisKasir << tulisKTPKasir[3] << ",";
      tulisKasir << tulisKTPKasir[4] << ",";
      tulisKasir << tulisKTPKasir[5] << ",";
      tulisKasir.close();
      tulisKasir.open(tulisKTPKasir[0] + "-kasir.txt");
      tulisKasir << tulisKTPKasir[1];
      tulisKasir.close();
      break;
    }
    case '2': {
      string nik, nama, password;
      ifstream baca;
      int login = 0;
      while (login < 5) {
        cout << "Masukkan NIK : ";
        cin >> nik;
        cout << "Masukkan Password : ";
        cin >> password;
        baca.open(nik + "-kasir.txt");
        while (getline(baca, nama))
          ;
        if (baca.is_open() == true && password == nama) {
          out.isLogin = true;
          out.isKasir = true;
          break;
        } else {
          cout << "Username/Password salah" << endl;
          login++;
        }
        baca.close();
      }
      if (login == 5) {
        cout << "Terlalu banyak login! Coba lagi nanti" << endl;
        exit(1);
      }
      break;
    }
    default: {
      cout << "Tidak tersedia" << endl;
      exit(1);
    }
    }
    break;
  }
  // End Case Untuk Kasir
  //---------------------
  // Case Default
  default: {
    cout << "Tidak tersedia" << endl;
    exit(1);
  }
    // End Case Default
  }

  if (out.isLogin == true && out.isAdmin == true) {
    int plh = 10;
    system("clear");
    while (plh != 0) {
      cout << "--- ---------------------------------" << endl;
      cout << "--- Berhasil Login Sebagai Admin  ---" << endl;
      cout << "---       Admin Dashboard         ---" << endl;
      cout << "-------------------------------------" << endl;
      cout << "--- 1. Input Data Pegawai" << endl;
      cout << "--- 2. Lihat Data Pegawai" << endl;
      cout << "--- 3. Input Data Novel" << endl;
      cout << "--- 4. Lihat Data Novel" << endl;
      cout << "--- 5. Data Penjualan" << endl;
      cout << "--- 6. Catat Data Transaksi" << endl;
      cout << "--- 7. Lihat Data Transaksi" << endl;
      cout << "--- 0. Logout" << endl;
      cout << "Pilih : ";
      cin >> plh;
      // cout << endl << "Pilihan : " << plh << endl;
      switch (plh) {
      case 1: {
        out.adminTambahPegawai();
        break;
      }
      case 2: {
        out.adminLihatPegawai();
        break;
      }
      case 3: {
        out.adminTambahNovel();
        break;
      }
      case 4: {
        out.adminLihatNovel();
        break;
      }
      case 5: {
        out.adminLihatPenjualan();
        break;
      }
      case 6: {
        out.adminCatatTransaksi();
        break;
      }
      case 7: {
        out.adminLihatTransaksi();
        break;
      }
      case 0: {
        out.isLogin = false;
        out.isAdmin = false;
        system("clear");
        goto mainapp;
        break;
      }
      default: {
        cout << "Tidak tersedia " << endl;
        break;
      }
      }
    }
  }
  if (out.isLogin == true && out.isKasir == true) {
    int plh = 10;
    system("clear");
    while (plh != 0) {
      cout << "--- ---------------------------------" << endl;
      cout << "--- Berhasil Login Sebagai Kasir  ---" << endl;
      cout << "---       Kasir Dashboard         ---" << endl;
      cout << "-------------------------------------" << endl;
      cout << "--- 1. Input Data Pelanggan" << endl;
      cout << "--- 2. Lihat Data Pelanggan" << endl;
      cout << "--- 3. Riwayat Pelanggan" << endl;
      cout << "--- 4. Tambah Rekomendasi" << endl;
      cout << "--- 5. Lihat Rekomendasi" << endl;
      cout << "--- 6. Input Data Novel" << endl;
      cout << "--- 7. Lihat Data Novel" << endl;
      cout << "--- 8. Input Data Penjualan" << endl;
      cout << "--- 9. Lihat Data Penjualan" << endl;
      cout << "--- 0. Logout" << endl;
      cout << "Pilih : ";
      cin >> plh;
      switch (plh) {
      case 1: {
        out.kasirTambahPelanggan();
        break;
      }
      case 2: {
        out.kasirLihatPelanggan();
        break;
      }
      case 3: {
        // pelanggan pel;
        // pel.riwayat();
        out.kasirLihatRiwayatPelanggan();
        break;
      }
      case 4: {
        // rekomen rek;
        // rek.detailnvl();
        out.kasirTambahRekomendasi();
        break;
      }
      case 5: {
        // rekomen rek;
        // rek.detailnvl();
        out.kasirLihatRekomendasi();
        break;
      }
      case 6: {
        out.kasirTambahNovel();
        break;
      }
      case 7: {
        out.kasirLihatNovel();
        break;
      }
      case 8: {
        out.kasirTambahPenjualan();
        break;
      }
      case 9: {
        out.kasirLihatPenjualan();
        break;
      }
      case 0: {
        out.isLogin = false;
        out.isKasir = false;
        system("clear");
        goto mainapp;
        break;
      }
      }
    }
  }
}

ostream &operator<<(ostream &out, const APP &outp) {
  string simpan;
  ifstream write;
  if (outp.isLogin == true) {
    write.open("StrukHarga.txt");
    if (write.is_open()) {
      while (getline(write, simpan)) {
        out << simpan << "\n";
      }
      write.close();
    } else {
      out << "Data tidak ada";
      return out;
    }
  }
  return out;
}

int main() {
  APP x;
  cin >> x;
  cout << x;
};