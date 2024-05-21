#ifndef __dllpenjualan
#define __dllpenjualan
#include "node_penjualan.h"
#include "penjualan.h"
#include <iostream>

NodePenjualan<PENJUALAN> *headPenjualan;
NodePenjualan<PENJUALAN> *tailPenjualan;
NodePenjualan<PENJUALAN> *jalanPenjualan;
NodePenjualan<PENJUALAN> *tempPenjualan;
NodePenjualan<PENJUALAN> *hapusPenjualan;

template <typename T> class DoublyLinkedListPenjualan {
public:
void add(T data) {
    NodePenjualan<T> *tempPenjualan = new NodePenjualan<T>();
    if (headPenjualan == 0) {
      headPenjualan = new NodePenjualan<T>();
      headPenjualan = calo(data);
      tailPenjualan = headPenjualan;
      return;
    }
    tempPenjualan = calo(data);
    tempPenjualan->prev = tailPenjualan;
    tailPenjualan->next = tempPenjualan;
    tailPenjualan = tempPenjualan;
  }

void remove() {
    hapusPenjualan = tailPenjualan;
    tailPenjualan = tailPenjualan->prev;
    tailPenjualan->next = 0;
    hapusPenjualan->prev = 0;
    delete hapusPenjualan;
  }

void clearList() {
    for (jalanPenjualan = headPenjualan; jalanPenjualan != 0;) {
      hapusPenjualan = jalanPenjualan;
      jalanPenjualan = jalanPenjualan->next;
      delete hapusPenjualan;
    }
    headPenjualan = 0;
    tailPenjualan = 0;
  }

void sortByNamaAsc() {
    int swapped, i;
    NodePenjualan<PENJUALAN> *ptr1;
    NodePenjualan<PENJUALAN> *lptr = NULL;

    if (headPenjualan == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPenjualan;

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
    NodePenjualan<PENJUALAN> *ptr1;
    NodePenjualan<PENJUALAN> *lptr = NULL;

    if (headPenjualan == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPenjualan;

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

void sortByTotalDesc() {
    int swapped, i;
    NodePenjualan<PENJUALAN> *ptr1;
    NodePenjualan<PENJUALAN> *lptr = NULL;

    if (headPenjualan == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPenjualan;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.total) < stoi(ptr1->next->data.total)) {
          swap(ptr1->data, ptr1->next->data);
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }

void sortByTotalAsc() {
    int swapped, i;
    NodePenjualan<PENJUALAN> *ptr1;
    NodePenjualan<PENJUALAN> *lptr = NULL;

    if (headPenjualan == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPenjualan;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.total) > stoi(ptr1->next->data.total)) {
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
    for (jalanPenjualan = headPenjualan; jalanPenjualan != 0;
         jalanPenjualan = jalanPenjualan->next) {
      std::cout << a << "." << jalanPenjualan->data << std::endl;
      a++;
    }
  }

void cetakMundur() {
    for (jalanPenjualan = tailPenjualan; jalanPenjualan != 0;
         jalanPenjualan = jalanPenjualan->prev) {
      std::cout << jalanPenjualan->data << std::endl;
      cout << "+==============================================================="
              "=======+"
           << endl;
    }
  }

  int getLen() {
    int n = 0;
    for (jalanPenjualan = headPenjualan; jalanPenjualan != 0;
         jalanPenjualan = jalanPenjualan->next) {
      n++;
    }
    return n;
  }

private:
  NodePenjualan<T> *calo(T &data) {
    NodePenjualan<T> *tempPenjualan = new NodePenjualan<T>();
    tempPenjualan->data = data;
    tempPenjualan->next = 0;
    tempPenjualan->prev = 0;
    return tempPenjualan;
  }
};
#endif