#pragma once
#include <iostream>
#define T int

class Arr {
public:
    Arr(T* store = nullptr, size_t size = 0) :m_storage(store), m_size(size) {}

    Arr(const Arr& X): m_storage(X.m_storage), m_size(X.m_size) {}

    ~Arr(){}

    size_t getSize() const { return m_size; };

    T getElement(size_t)const;

    void addElement(T);

    void print();

    void resize(size_t);

    T* removeElement(size_t);


private:
    T* m_storage;
    size_t m_size;
};