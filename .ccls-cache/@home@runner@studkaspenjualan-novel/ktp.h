#ifndef __ktp
#define __ktp

class KTP {
public:
  void setAll(string provinsi, 
              string kab_kota, 
              string nik, string nama,
              string tempat, 
              short tanggal, 
              short bulan, 
              short tahun,
              string jenisKelamin, 
              char golDarah, 
              string alamat, 
              short rt,
              short rw, 
              string kecamatan, 
              string kel_desa, 
              string agama,
              string statusKawin, 
              string pekerjaan, 
              string kewarganegaraan,
              const char *berlaku = "SEUMUR HIDUP") {
    this->provinsi = provinsi;
    this->kab_kota = kab_kota;
    this->nik = nik;
    this->nama = nama;
    this->tempat = tempat;
    this->tanggal = tanggal;
    this->bulan = bulan;
    this->tahun = tahun;
    this->jenisKelamin = jenisKelamin;
    this->golDarah = golDarah;
    this->alamat = alamat;
    this->rt = rt;
    this->rw = rw;
    this->kecamatan = kecamatan;
    this->kel_desa = kel_desa;
    this->agama = agama;
    this->statusKawin = statusKawin;
    this->pekerjaan = pekerjaan;
    this->kewarganegaraan = kewarganegaraan;
    this->berlaku = "SEUMUR HIDUP";
  }

private:
  string provinsi;
  string kab_kota;
  string nik;
  string nama;
  string tempat;
  short tanggal;
  short bulan;
  short tahun;
  string jenisKelamin;
  char golDarah;
  string alamat;
  short rt;
  short rw;
  string kel_desa;
  string kecamatan;
  string agama;
  string statusKawin;
  string pekerjaan;
  string kewarganegaraan;
  const char *berlaku = "SEUMUR HIDUP";
};

#endif