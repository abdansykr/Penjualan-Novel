#include <string>

class SORTING {
public:
  void full(std::string id, std::string nm, std::string hr, std::string pen,
            std::string png, int pil) {
    pilih = pil;
    idNovel_temp = id;
    namaNovel_temp = nm;
    harga_temp = hr;
    namaPenerbit_temp = pen;
    namaPengarang_temp = png;
  }
  int pilih;
  std::string idNovel_temp; 
  std::string namaNovel_temp;
  std::string harga_temp;
  std::string namaPenerbit_temp;
  std::string namaPengarang_temp;
};