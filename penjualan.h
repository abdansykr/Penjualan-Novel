#ifndef __penjualan
#define __penjualan
#include <string>
#include <iostream>
using namespace std;


struct PENJUALAN {
  string id;
  string nama;
  string jumlah;
  string total;
  friend ostream &operator<<(ostream &out, PENJUALAN &obj){
    out << obj.id << "         " << obj.nama << "         "
        << obj.jumlah << "        " << obj.total << "          ";
    return out;
  }
  void setAll(string id, string nama, string jumlah, string total){
    this->id=id;
    this->nama=nama;
    this->jumlah=jumlah;
    this->total = total;
  }
};

#endif