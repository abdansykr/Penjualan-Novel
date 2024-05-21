#ifndef __dllpegawai
#define __dllpegawai
#include "node_pegawai.h"
#include "115.h"
#include <iostream>

NodePegawai<PEGAWAI> *headPegawai;
NodePegawai<PEGAWAI> *tailPegawai;
NodePegawai<PEGAWAI> *jalanPegawai;
NodePegawai<PEGAWAI> *tempPegawai;
NodePegawai<PEGAWAI> *hapusPegawai;

template <typename T> class DoublyLinkedListPegawai {
public:
void add(T data) {
    NodePegawai<T> *tempPegawai = new NodePegawai<T>();
    if (headPegawai == 0) {
      headPegawai = new NodePegawai<T>();
      headPegawai = calo(data);
      tailPegawai = headPegawai;
      return;
    }
    tempPegawai = calo(data);
    tempPegawai->prev = tailPegawai;
    tailPegawai->next = tempPegawai;
    tailPegawai = tempPegawai;
  }

void remove() {
    hapusPegawai = tailPegawai;
    tailPegawai = tailPegawai->prev;
    tailPegawai->next = 0;
    hapusPegawai->prev = 0;
    delete hapusPegawai;
  }

void clearList() {
    for (jalanPegawai = headPegawai; jalanPegawai != 0;) {
      hapusPegawai = jalanPegawai;
      jalanPegawai = jalanPegawai->next;
      delete hapusPegawai;
    }
    headPegawai = 0;
    tailPegawai = 0;
  }

void sortByIdDesc() {
    int swapped, i;
    NodePegawai<PEGAWAI> *ptr1;
    NodePegawai<PEGAWAI> *lptr = NULL;

    if (headPegawai == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPegawai;

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
    NodePegawai<PEGAWAI> *ptr1;
    NodePegawai<PEGAWAI> *lptr = NULL;

    if (headPegawai == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPegawai;

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

void sortByUsiaAsc() {
    int swapped, i;
    NodePegawai<PEGAWAI> *ptr1;
    NodePegawai<PEGAWAI> *lptr = NULL;

    if (headPegawai == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPegawai;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.usia) > stoi(ptr1->next->data.usia)) {
          swap(ptr1->data, ptr1->next->data);
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }

void sortByUsiaDesc() {
    int swapped, i;
    NodePegawai<PEGAWAI> *ptr1;
    NodePegawai<PEGAWAI> *lptr = NULL;

    if (headPegawai == 0)
      return;

    do {
      swapped = 0;
      ptr1 = headPegawai;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.usia) < stoi(ptr1->next->data.usia)) {
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
    for (jalanPegawai = headPegawai; jalanPegawai != 0; jalanPegawai = jalanPegawai->next) {
      std::cout << a << "." << jalanPegawai->data << std::endl;
      a++;
    }
  }

void cetakMundur() {
    for (jalanPegawai = tailPegawai; jalanPegawai != 0; jalanPegawai = jalanPegawai->prev) {
      std::cout << jalanPegawai->data << std::endl;
      cout << "+==============================================================="
              "=======+"
           << endl;
    }
  }

int getLen() {
    int n = 0;
    for (jalanPegawai = headPegawai; jalanPegawai != 0; jalanPegawai = jalanPegawai->next) {
      n++;
    }
    return n;
  }

private:
  NodePegawai<T> *calo(T &data) {
    NodePegawai<T> *tempPegawai = new NodePegawai<T>();
    tempPegawai->data = data;
    tempPegawai->next = 0;
    tempPegawai->prev = 0;
    return tempPegawai;
  }
};
#endif