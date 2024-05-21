#ifndef __transaksi
#define __transaksi
#include <string>
#include <iostream>
using namespace std;


struct TRANSAKSI {
  string id;
  string nama;
  string jumlah;
  friend ostream &operator<<(ostream &out, TRANSAKSI &obj){
    out << obj.id << "         " << obj.nama << "         "
        << obj.jumlah << "        ";
    return out;
  }
  void setAll(string id, string nama, string jumlah){
    this->id=id;
    this->nama=nama;
    this->jumlah=jumlah;
  }
};

#endif