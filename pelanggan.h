#ifndef __pelanggan
#define __pelanggan
#include <iostream>
#include <string>
using namespace std;

struct PELANGGAN {
  string id;
  string nama;
  string alamat;
  string usia;
  friend ostream &operator<<(ostream &out, PELANGGAN &obj) {
    out << obj.id << "         " << obj.nama << "         " << obj.alamat
        << "        " << obj.usia << "          ";
    return out;
  }
  void setAll(string id, string nama, string alamat, string usia) {
    this->id = id;
    this->nama = nama;
    this->alamat = alamat;
    this->usia = usia;
  }
};

#endif