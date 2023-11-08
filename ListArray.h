#ifndef LISTARRAY_H
#define LISTARRAY_H
#include "List.h"
#include <iostream>

template <typename T>
class ListArray : public List<T> {
private:
    static const int MINSIZE = 2;
    T* arr;
    int capacity;
    int length;

public:
    ListArray(int initialCapacity = MINSIZE) {
        if (initialCapacity < MINSIZE) {
            initialCapacity = MINSIZE;
        }
        capacity = initialCapacity;
        arr = new T[capacity];
        length = 0;
    }

    ~ListArray() {
        delete[] arr;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > length) {
            throw std::out_of_range("Posición fuera de los límites");
        }
        if (length == capacity) {
            capacity *= 2;
            T* newArr = new T[capacity];
            for (int i = 0; i < length; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        for (int i = length; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        length++;
    }

    void append(T e) override {
        insert(length, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= length) {
            throw std::out_of_range("Posición fuera de los límites");
        }
        T removedElement = arr[pos];
        for (int i = pos; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        length--;
        return removedElement;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= length) {
            throw std::out_of_range("Posición fuera de los límites");
        }
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < length; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    bool empty() override {
        return length == 0;
    }

    int size() override {
        return length;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= length) {
            throw std::out_of_range("Posición fuera de los límites");
        }
        return arr[pos];
    }

    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.length; i++) {
            out << list.arr[i];
            if (i < list.length - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

private:
    void resize(int new_size) {
        if (new_size < MINSIZE) {
            new_size = MINSIZE;
        }
        T* new_arr = new T[new_size];
        for (int i = 0; i < length; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_size;
    }
};

#endif

