#ifndef __dllpelanggan
#define __dllpelanggan
#include "node_pelanggan.h"
#include "pelanggan.h"
#include <iostream>

NodePelanggan<PELANGGAN> *headPelanggan;
NodePelanggan<PELANGGAN> *tailPelanggan;
NodePelanggan<PELANGGAN> *jalanPelanggan;
NodePelanggan<PELANGGAN> *tempPelanggan;
NodePelanggan<PELANGGAN> *hapusPelanggan;

template <typename T> class DoublyLinkedListPelanggan {
public:
void add(T data) {
    NodePelanggan<T> *tempPelanggan = new NodePelanggan<T>();
    if (headPelanggan == 0) {
      headPelanggan = new NodePelanggan<T>();
      headPelanggan = calo(data);
      tailPelanggan = headPelanggan;
      return;
    }
    tempPelanggan = calo(data);
    tempPelanggan->prev = tailPelanggan;
    tailPelanggan->next = tempPelanggan;
    tailPelanggan = tempPelanggan;
  }

void remove() {
    hapusPelanggan = tailPelanggan;
    tailPelanggan = tailPelanggan->prev;
    tailPelanggan->next = 0;
    hapusPelanggan->prev = 0;
    delete hapusPelanggan;
  }

void clearList() {
    for (jalanPelanggan = headPelanggan; jalanPelanggan != 0;) {
      hapusPelanggan = jalanPelanggan;
      jalanPelanggan = jalanPelanggan->next;
      delete hapusPelanggan;
    }
    headPelanggan = 0;
    tailPelanggan = 0;
  }

void sortByIdDesc() {
    int swapped, i;
    NodePelanggan<PELANGGAN> *ptr1;
    NodePelanggan<PELANGGAN> *lptr = NULL;

    if (headPelanggan == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPelanggan;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.id) < stoi(ptr1->next->data.id)) {
          swap(ptr1->data, ptr1->next->data);
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }

void sortByIdAsc() {
    int swapped, i;
    NodePelanggan<PELANGGAN> *ptr1;
    NodePelanggan<PELANGGAN> *lptr = NULL;

    if (headPelanggan == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPelanggan;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.id) > stoi(ptr1->next->data.id)) {
          swap(ptr1->data, ptr1->next->data);
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }

void sortByNamaAsc() {
    int swapped, i;
    NodePelanggan<PELANGGAN> *ptr1;
    NodePelanggan<PELANGGAN> *lptr = NULL;

    if (headPelanggan == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPelanggan;

      while (ptr1->next != lptr) {
        if (ptr1->data.nama > ptr1->next->data.nama) {
          swap(ptr1->data, ptr1->next->data);
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }

void sortByNamaDesc() {
    int swapped, i;
    NodePelanggan<PELANGGAN> *ptr1;
    NodePelanggan<PELANGGAN> *lptr = NULL;

    if (headPelanggan == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPelanggan;

      while (ptr1->next != lptr) {
        if (ptr1->data.nama < ptr1->next->data.nama) {
          swap(ptr1->data, ptr1->next->data);
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }

void cetakMaju() {
    int a = 1;
    for (jalanPelanggan = headPelanggan; jalanPelanggan != 0; jalanPelanggan = jalanPelanggan->next) {
      std::cout << a << "." << jalanPelanggan->data << std::endl;
      a++;
    }
  }

void cetakMundur() {
    for (jalanPelanggan = tailPelanggan; jalanPelanggan != 0; jalanPelanggan = jalanPelanggan->prev) {
      std::cout << jalanPelanggan->data << std::endl;
      cout << "+==============================================================="
              "=======+"
           << endl;
    }
  }

int getLen() {
    int n = 0;
    for (jalanPelanggan = headPelanggan; jalanPelanggan != 0; jalanPelanggan = jalanPelanggan->next) {
      n++;
    }
    return n;
  }

private:
  NodePelanggan<T> *calo(T &data) {
    NodePelanggan<T> *tempPelanggan = new NodePelanggan<T>();
    tempPelanggan->data = data;
    tempPelanggan->next = 0;
    tempPelanggan->prev = 0;
    return tempPelanggan;
  }
};
#endif