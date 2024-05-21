#ifndef __nodepenjualan
#define __nodepenjualan
#include "dll_penjualan.h"

template<typename T>
class NodePenjualan{
  public:
    T data;
    NodePenjualan<T> *next;
    NodePenjualan<T> *prev;
};


#endif
