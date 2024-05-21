#ifndef __pegawai
#define __pegawai
#include <string>
#include <iostream>
using namespace std;


struct PEGAWAI {
  string id;
  string nama;
  string divisi;
  string usia;
  friend ostream &operator<<(ostream &out, PEGAWAI &obj){
    out << obj.id << "         " << obj.nama << "         "
        << obj.divisi << "        " << obj.usia << "          ";
    return out;
  }
  void setAll(string id, string nama, string divisi, string usia){
    this->id=id;
    this->nama=nama;
    this->divisi=divisi;
    this->usia = usia;
  }
};

#endif