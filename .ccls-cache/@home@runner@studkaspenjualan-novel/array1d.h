#include "xcept.h"
#include <iostream>
using namespace std;

template <class T> class Array1D 
{

  template <class U> friend ostream &operator<<(ostream &, const Array1D<U> &x);

public:
  Array1D(int size = 0);
  Array1D(const Array1D<T> &v);
  ~Array1D() { delete[] dataPegawai; }
  T &operator[](int i) const;
  int Size() { return size; }
  Array1D<T> &operator=(const Array1D<T> &v);
  Array1D<T> operator+() const;
  Array1D<T> operator+(const Array1D<T> &v) const;
  Array1D<T> operator-() const;
  Array1D<T> operator-(const Array1D<T> &v) const;
  Array1D<T> operator*(const Array1D<T> &v) const;
  Array1D<T> &operator+=(const T &x);
  Array1D<T> &ReSize(int sz);

private:
  int size;
  T *dataPegawai;
};

template <class T> Array1D<T>::Array1D(int sz) 
{
  if (sz < 0){
      throw BadInitializers();
  }
    
  size = sz;
  dataPegawai = new T[sz];
}

template <class T> Array1D<T>::Array1D(const Array1D<T> &v) 
{
  size = v.size;
  dataPegawai = new T[size];     // get space
  for (int i = 0; i < size; i++){
      dataPegawai[i] = v.dataPegawai[i];
  } // copy dataNovels    
}
template <class T> T &Array1D<T>::operator[](int i) const 
{
  if (i < 0 || i >= size){
    throw OutOfBounds();
  }
    
  return dataPegawai[i];
}
template <class T> Array1D<T> &Array1D<T>::operator=(const Array1D<T> &v) 
{
  if (this != &v) {
    size = v.size;
    delete[] dataPegawai;
    dataPegawai = new T[size];
    for (int i = 0; i < size; i++){
        dataPegawai[i] = v.dataPegawai[i];
    }      
  }
  return *this;
}
template <class T> Array1D<T> Array1D<T>::operator+(const Array1D<T> &v) const 
{
  if (size != v.size)
    throw SizeMismatch();
  Array1D<T> w(size);
  for (int i = 0; i < size; i++){
      w.dataPegawai[i] = dataPegawai[i] + v.dataPegawai[i];
  }
    
  return w;
}
template <class T> Array1D<T> Array1D<T>::operator-(const Array1D<T> &v) const 
{
  if (size != v.size){
      throw SizeMismatch();
  }
    
  Array1D<T> w(size);
  for (int i = 0; i < size; i++){
      w.dataPegawai[i] = dataPegawai[i] - v.dataPegawai[i];
  }
    
  return w;
}
template <class T> Array1D<T> Array1D<T>::operator-() const 

{
  Array1D<T> w(size);
  for (int i = 0; i < size; i++){
    w.dataPegawai[i] = -dataPegawai[i];
  }
    
  return w;
}

template <class T> Array1D<T> Array1D<T>::operator*(const Array1D<T> &v) const 
{
  if (size != v.size){
    throw SizeMismatch();
  }
    
  Array1D<T> w(size);
  for (int i = 0; i < size; i++){
    w.dataPegawai[i] = dataPegawai[i] * v.dataPegawai[i];
  }
    
  return w;
}

template <class T> Array1D<T> &Array1D<T>::operator+=(const T &x) 
{
  for (int i = 0; i < size; i++){
    dataPegawai[i] += x;
  }
    
  return *this;
}

template <class T> ostream &operator<<(ostream &out, const Array1D<T> &x) 
{
  for (int i = 0; i < x.size; i++){
      out << x.dataPegawai[i] << "  ";
  }
    
  return out;
}

template <class T> Array1D<T> &Array1D<T>::ReSize(int sz) 
{
  if (sz < 0){
    throw BadInitializers();
  }
    
  delete[] dataPegawai;
  size = sz;
  dataPegawai = new T[size];
  return *this;
}