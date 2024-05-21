#ifndef __nodetransaksi
#define __nodetransaksi
#include "dll_transaksi.h"

template<typename T>
class NodeTransaksi{
  public:
    T data;
    NodeTransaksi<T> *next;
    NodeTransaksi<T> *prev;
};


#endif
