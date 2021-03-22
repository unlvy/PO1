#include "MyArray.h"

/* ---------- CONSTRUCTORS, DESTRUCTOR ---------- */

MyArray::MyArray() {
    _size = 0;
    _array = nullptr;
    _next = nullptr;
}

MyArray::MyArray(int size) {
    _size = size;
    if (_size > 0) {
        _array = new int[_size];
        for (int i = 0; i < _size; i++) {
            _array[i] = 0;
        }
    } else {
        _array = nullptr;
    }
    _next = nullptr;
}

MyArray::MyArray(const MyArray& other) {
    _size = other._size;
    if (_size > 0) {
        _array = new int[_size];
        for (int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
    } else {
        _array = nullptr;
    }
    _next = other._next;
}

MyArray::MyArray(MyArray&& other) {
    _array = std::__exchange(other._array, nullptr);
    _next = std::__exchange(other._next, nullptr);
    _size = std::__exchange(other._size, 0);
}

MyArray::~MyArray() {
    if (_array != nullptr) {
        delete[] _array;
    }
}

/* ---------- BASIC METHODS ---------- */

int MyArray::size() const {
    return _size;
}

MyArray& MyArray::getNext() {
    return *_next;
}

void MyArray::print(const char* text) const {
    std::cout << text << " " << *this;
    MyArray* current = _next;
    while (current != nullptr) {
        std::cout << " " << *current;
        current = current->_next;
    }
}

/* ---------- OPERATORS OVERLOADED AS METHODS ---------- */

MyArray MyArray::operator++ (int) {
    MyArray copy(*this);
    for (int i = 0; i < _size; i++) {
        _array[i]++;
    }
    return copy;
}

MyArray& MyArray::operator-- () {
    for (int i = 0; i < _size; i++) {
        _array[i]--;
    }
    return *this;
}

int& MyArray::operator[] (int index) {
    if (index >= _size) {
        return (*_next)[index - _size];
    } else {
        return _array[index];
    }
}

int MyArray::operator[] (int index) const {
    if (index >= _size) {
        return (*_next)[index - _size];
    } else {
        return _array[index];
    }
}

MyArray& MyArray::operator= (const MyArray& other) {
    if (&other != this) {
        if (other._array != nullptr) {
            delete[] _array;
        }
        _size = other._size;
        if (_size > 0) {
            _array = new int[_size];
            for (int i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
        } else {
            _array = nullptr;
        }
        _next = other._next;
    }
    return *this;
}

MyArray& MyArray::operator= (MyArray&& other) {
    delete[] _array;
    _array = std::__exchange(other._array, nullptr);
    _next = std::__exchange(other._next, nullptr);
    _size = std::__exchange(other._size, 0);
    return *this;
}

void MyArray::operator+= (MyArray& next) {
    if (_next == nullptr) {
        _next = &next;
    } else {
        (*_next) += next;
    }
}

void MyArray::operator+= (MyArray&& other) {
    MyArray temp(other);
    int newSize = _size + temp._size;
    int* newArray = new int[newSize];
    for (int i = 0; i < _size; i++) {
        newArray[i] = _array[i];
    } 
    for (int i = 0; i < temp._size; i++) {
        newArray[i + _size] = temp._array[i];
    }
    delete[] _array;
    _array = newArray;
    _size = newSize;
}

/* ---------- FRIEND FUNCTION ---------- */

std::ostream& operator<< (std::ostream& os, const MyArray& myArray) {
    os << "[";
    if (myArray._size > 0) {
        os << myArray._array[0];
        for (int i = 1; i < myArray._size; i++) {
            os << ", " << myArray._array[i];
        } 
    }
    os << "]";
    return os;
}
