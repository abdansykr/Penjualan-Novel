#ifndef __dll
#define __dll
#include "node.h"
#include "novel.h"
#include <iostream>
#include <string>

node<Novel> *head;
node<Novel> *tali;
node<Novel> *jalan;
node<Novel> *temp;
node<Novel> *hapus;
node<Novel> *next;

template <typename T> class DoublyLinkedList {
public:
  void add(T data) {
    node<T> *temp = new node<T>();
    if (head == 0) {
      head = new node<T>();
      head = calo(data);
      tali = head;
      return;
    }
    temp = calo(data);
    temp->prev = tali;
    tali->next = temp;
    tali = temp;
    tali->next = 0;
  }

  void remove() {
    hapus = tali;
    tali = tali->prev;
    tali->next = 0;
    hapus->prev = 0;
    delete hapus;
  }

  void clearList() {
    for (jalan = head; jalan != 0;) {
      hapus = jalan;
      jalan = jalan->next;
      delete hapus;
    }
    head = 0;
    tali = 0;
  }

  void sortByIdDesc() {
    int swapped, i;
    node<Novel> *ptr1;
    node<Novel> *lptr = NULL;

    if (head == 0)
      return;

    do {
      swapped = 0;
      ptr1 = head;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.idNovel) < stoi(ptr1->next->data.idNovel)) {
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
    node<Novel> *ptr1;
    node<Novel> *lptr = NULL;

    if (head == 0)
      return;

    do {
      swapped = 0;
      ptr1 = head;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.idNovel) > stoi(ptr1->next->data.idNovel)) {
          swap(ptr1->data, ptr1->next->data);
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }

  void sortByHargaAsc() {
    int swapped, i;
    node<Novel> *ptr1;
    node<Novel> *lptr = NULL;

    if (head == 0)
      return;

    do {
      swapped = 0;
      ptr1 = head;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.harga) > stoi(ptr1->next->data.harga)) {
          swap(ptr1->data, ptr1->next->data);
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }

  void sortByHargaDesc() {
    int swapped, i;
    node<Novel> *ptr1;
    node<Novel> *lptr = NULL;

    if (head == 0)
      return;

    do {
      swapped = 0;
      ptr1 = head;

      while (ptr1->next != lptr) {
        if (stoi(ptr1->data.harga) < stoi(ptr1->next->data.harga)) {
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
    jalan = head;
    while (jalan != 0) {
      std::cout << a << ". " << jalan->data << std::endl;
      a++;
      jalan = jalan->next;
    }
    // for (jalan = head; jalan != 0; jalan = jalan->next) {
    //   std::cout << a << ". " << jalan->data << std::endl;
    //   a++;
    // }
  }
  void cetakMundur() {
    for (jalan = tali; jalan != 0; jalan = jalan->prev) {
      std::cout << jalan->data << std::endl;
      cout << "+==============================================================="
              "=======+"
           << endl;
    }
  }

  int getLen() {
    int n = 0;
    for (jalan = head; jalan != 0; jalan = jalan->next) {
      n++;
    }
    return n;
  }

private:
  node<T> *calo(T &data) {
    node<T> *temp = new node<T>();
    temp->data = data;
    temp->next = 0;
    temp->prev = 0;
    return temp;
  }
};
#endif