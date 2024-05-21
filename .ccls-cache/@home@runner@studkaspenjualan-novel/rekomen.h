#include <iostream>

using namespace std;

class rekomen {

public:
  void detail();

private:
  int pilihan;
  string judul, pengarang, penerbit, tt;
};

void rekomen::detail() {

  rekomen surat_surat;

  surat_surat.judul = "surat_surat";
  surat_surat.pengarang = "@surat_surat";
  surat_surat.penerbit = "@surat_surat";
  surat_surat.tt = "jakal";
  kembali:
  cout << "--- ---------------------------------" << endl;
  cout << "---  REKOMENDASI NOVEL TERBAIK    ---" << endl;
  cout << "---            LIST NOVEL         ---" << endl;
  cout << "-------------------------------------" << endl;
  cout<<"1. "<<surat_surat.judul<<endl;

  switch (pilihan) {
  case 1:
    cout << "judul : " << surat_surat.judul << endl
         << "pengarang :" << surat_surat.pengarang << endl
         << "penerbit :" << surat_surat.penerbit << endl
         << "tahun terbit" << surat_surat.tt<< endl
         << endl;
    goto kembali;
    break;

    default:
    cout<<"pilihan tidak di temukan"<<endl;
    break;
  }