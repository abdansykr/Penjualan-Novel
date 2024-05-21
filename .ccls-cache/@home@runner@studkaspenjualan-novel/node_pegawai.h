#ifndef __nodepegawai
#define __nodepegawai
#include "dll_pegawai.h"

template<typename T>
class NodePegawai{
  public:
    T data;
    NodePegawai<T> *next;
    NodePegawai<T> *prev;
};


#endif
