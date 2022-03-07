#pragma once
#include <iostream>

template<typename T>

class ArrT {
public:
    ArrT(T* store = nullptr, size_t size = 0) :m_storage(store), m_size(size) {}

    ArrT(const ArrT& X): m_storage (X.m_storage), m_size(X.m_size) {}

    ~ArrT(){}

   /* template <typename T> T& operator [] (ArrT<T>, size_t index)*/

    //const T& getElement(size_t);

    T getElement(size_t) const;

    size_t getSize() const { return m_size; };

    void addElement(T);

    void print() const ;

    void resize(size_t);

    T* removeElement(size_t);


private:
    T* m_storage;
    size_t m_size;
};
