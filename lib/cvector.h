#include <iostream>
#include <stdexcept>

template<class T>
class Vector {
private:
    T* array;
    int size;
    int capacity;

    void reallocate(int newCap) {
        T* temp = new T[newCap];
        for (int i = 0; i < size; i++)
            temp[i] = array[i];
        delete[] array;
        array = temp;
        capacity = newCap;
    }

public:
    Vector() : array(nullptr), size(0), capacity(4) {
        array = new T[capacity];
    }

    Vector(int n) : size(n), capacity(n + 4) {
        array = new T[capacity];
    }

    Vector(const Vector& v) : size(v.size), capacity(v.capacity) {
        array = new T[capacity];
        for (int i = 0; i < size; i++)
            array[i] = v.array[i];
    }

    Vector(Vector&& v) noexcept
        : array(v.array), size(v.size), capacity(v.capacity) {
        v.array = nullptr;
        v.size = 0;
        v.capacity = 0;
    }

    ~Vector() {
        delete[] array;
    }

    Vector& operator=(const Vector& v) {
        if (this != &v) {
            delete[] array;
            size = v.size;
            capacity = v.capacity;
            array = new T[capacity];
            for (int i = 0; i < size; i++)
                array[i] = v.array[i];
        }
        return *this;
    }

    Vector& operator=(Vector&& v) noexcept {
        if (this != &v) {
            delete[] array;
            array = v.array;
            size = v.size;
            capacity = v.capacity;
            v.array = nullptr;
            v.size = 0;
            v.capacity = 0;
        }
        return *this;
    }

    void push_back(const T& data) {
        if (size == capacity)
            reallocate(capacity + 4);
        array[size++] = data;
    }

    void pop_back() {
        if (size == 0)
            throw std::runtime_error("Vector is empty");
        size--;
    }

    int get_size() const { return size; }
    int get_capacity() const { return capacity; }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        return array[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        return array[index];
    }

    void resize(int n) {
        if (n > capacity)
            reallocate(n);
        size = n;
    }
};
