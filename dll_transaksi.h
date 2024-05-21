#ifndef __dlltransaksi
#define __dlltransaksi
#include "node_transaksi.h"
#include "transaksi.h"
#include <iostream>

NodeTransaksi<TRANSAKSI> *headTransaksi;
NodeTransaksi<TRANSAKSI> *tailTransaksi;
NodeTransaksi<TRANSAKSI> *jalanTransaksi;
NodeTransaksi<TRANSAKSI> *tempTransaksi;
NodeTransaksi<TRANSAKSI> *hapusTransaksi;

template <typename T> class DoublyLinkedListTransaksi {
public:
  void add(T data) {
    NodeTransaksi<T> *tempTransaksi = new NodeTransaksi<T>();
    if (headTransaksi == 0) {
      headTransaksi = new NodeTransaksi<T>();
      headTransaksi = calo(data);
      tailTransaksi = headTransaksi;
      return;
    }
    tempTransaksi = calo(data);
    tempTransaksi->prev = tailTransaksi;
    tailTransaksi->next = tempTransaksi;
    tailTransaksi = tempTransaksi;
  }

  void remove() {
    hapusTransaksi = tailTransaksi;
    tailTransaksi = tailTransaksi->prev;
    tailTransaksi->next = 0;
    hapusTransaksi->prev = 0;
    delete hapusTransaksi;
  }

  void clearList() {
    for (jalanTransaksi = headTransaksi; jalanTransaksi != 0;) {
      hapusTransaksi = jalanTransaksi;
      jalanTransaksi = jalanTransaksi->next;
      delete hapusTransaksi;
    }
    headTransaksi = 0;
    tailTransaksi = 0;
  }

  void cetakMaju() {
    int a = 1;
    for (jalanTransaksi = headTransaksi; jalanTransaksi != 0; jalanTransaksi = jalanTransaksi->next) {
      std::cout << a << "." << jalanTransaksi->data << std::endl;
      a++;
    }
  }
  void cetakMundur() {
    for (jalanTransaksi = tailTransaksi; jalanTransaksi != 0; jalanTransaksi = jalanTransaksi->prev) {
      std::cout << jalanTransaksi->data << std::endl;
      cout << "+==============================================================="
              "=======+"
           << endl;
    }
  }

  int getLen() {
    int n = 0;
    for (jalanTransaksi = headTransaksi; jalanTransaksi != 0; jalanTransaksi = jalanTransaksi->next) {
      n++;
    }
    return n;
  }

private:
  NodeTransaksi<T> *calo(T &data) {
    NodeTransaksi<T> *tempTransaksi = new NodeTransaksi<T>();
    tempTransaksi->data = data;
    tempTransaksi->next = 0;
    tempTransaksi->prev = 0;
    return tempTransaksi;
  }
};
#endif