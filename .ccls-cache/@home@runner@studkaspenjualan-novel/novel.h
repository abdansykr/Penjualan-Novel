#ifndef __novel
#define __novel
#include <string>
#include <iostream>
using namespace std;


struct Novel {
  string idNovel;
  string namaNovel;
  string harga;
  string namaPenerbit;
  string namaPengarang;
  friend ostream &operator<<(ostream &out, Novel &obj){
    out << obj.idNovel << "         " << obj.namaNovel << "         "
        << obj.harga << "        " << obj.namaPenerbit << "          "
        << obj.namaPengarang << "         ";
    return out;
  }
  void setAll(string id, string nama, string harga, string Penerbit, string Pengarang){
    this->idNovel=id;
    this->namaNovel=nama;
    this->harga=harga;
    this->namaPenerbit = Penerbit;
    this->namaPengarang = Pengarang;
  }
};

#endif