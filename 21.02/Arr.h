#pragma once
#include <iostream>

template<typename T>

class ArrT {
public:
    ArrT(T* store = nullptr, size_t size = 0) :m_storage(store), m_size(size) {}

    ArrT(const ArrT& X): m_storage (X.m_storage), m_size(X.m_size) {}

    ~ArrT(){}

    T& operator [] (size_t index);

    const T& getElement(size_t);

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

template <typename T> 
T& ArrT<T>::operator[]  (size_t index) {
    if (index < m_size) return m_storage[index];
    else return m_storage[0];
}
template <typename T>const T& ArrT<T>::getElement(size_t index) {
    if (index < m_size) return m_storage[index];
    else return m_storage[0];
}
template <typename T>T ArrT<T>::getElement(size_t index) const {
    if (index < m_size) return m_storage[index];
    else return m_storage[0];
}

template <typename T>void ArrT<T>::addElement(T new_element) {
    size_t new_size = m_size + 1;
    T* new_array = new T[new_size];
    for (int i = 0; i < m_size; ++i) {
        new_array[i] = m_storage[i];
    }
    new_array[new_size - 1] = new_element;
    delete[] m_storage;
    m_storage = new_array;
    ++m_size;
}

template <typename T>void ArrT<T>::print() const {
    for (int i = 0; i < getSize(); i++) {
        std::cout << m_storage[i] << ' ';
    }
    std::cout << "\n" << m_size << std::endl;
}

template <typename T>void ArrT<T>::resize(size_t new_size) {
    T* new_array = new T[new_size];
    if (new_size <= m_size) {
        for (size_t i = 0; i < new_size; i++) {
            new_array[i] = m_storage[i];
        }
    }
    if (new_size > m_size) {
        for (size_t i = 0; i < m_size; i++) {
            new_array[i] = m_storage[i];
        }
    }
    delete[] m_storage;
    m_storage = new_array;
    m_size = new_size;
}

template <typename T>T* ArrT<T>::removeElement(size_t del_index) {
    if (del_index < m_size) {
        T* new_array = new T[m_size - 1];
        for (size_t i = 0; i < del_index; i++) {
            new_array[i] = m_storage[i];
        }
        for (size_t j = del_index + 1; j < m_size; j++) {
            new_array[j - 1] = m_storage[j];
        }
        delete[] m_storage;
        m_storage = new_array;
        --m_size;
    }
    else std::cout << "Error" << std::endl;
    return m_storage;
}
