#ifndef __nodepelanggan
#define __nodepelanggan
#include "dll_pelanggan.h"

template<typename T>
class NodePelanggan{
  public:
    T data;
    NodePelanggan<T> *next;
    NodePelanggan<T> *prev;
};


#endif
