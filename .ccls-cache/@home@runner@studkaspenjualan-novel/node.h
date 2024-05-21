#ifndef __node
#define __node
#include "dll.h"

template<typename T>
class node{
  public:
    T data;
    node<T> *next;
    node<T> *prev;
};


#endif
