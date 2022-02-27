#include<iostream>
#include"Arr.h"
#define T int


T Arr:: getElement(size_t index) const { //получение элемента массива
    if (index < m_size) return *(m_storage + index);
    else return m_storage[0];
}
//*(m_storage + index);

void Arr:: addElement(T new_element) {// добавление элемента в массив
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

void Arr::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << m_storage[i] << ' ';
    }
    std::cout <<"\n"<< m_size << std::endl;
}

void Arr::resize(size_t new_size) {
    T* new_array = new T[new_size];
    if (new_size<=m_size){
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

T* Arr:: removeElement(size_t del_index) {//удаление элемента
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

    