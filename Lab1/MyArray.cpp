#include "MyArray.h"

MyArray::MyArray() {
    _size = 0;
    _array = nullptr;
}

MyArray::MyArray(int size) {
    if(size > 0) {
        _size = size;
        _array = new int[size];
        for (int i = 0; i < _size; i++) {
            _array[i] = 0;
        }
    } else {
        std::cout << "Wrong size!" << std::endl;
        _size = 0;
        _array = nullptr;
    }
}

MyArray::MyArray(const MyArray& other) {
    _size = other._size;
    if(_size > 0) {
        _array = new int[_size];
        for(int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
    } else {
        _array = nullptr;
    }
}

MyArray::MyArray(MyArray&& other) {
    _array = std::move(other._array);
    _size = std::__exchange(other._size, 0);
}

MyArray::~MyArray() {
    if(_size > 0) {
        delete[] _array;
    }
}

MyArray& MyArray::operator= (const MyArray& other) {
    if(this != &other) {
        if (_size > 0) {
            delete[] _array;
        }
        _size = other._size;
        if(_size > 0) {
            _array = new int[_size];
            for(int i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
        } else {
            _array = nullptr;
        }
    }
    return *this;
}
        
int& MyArray::operator[](int index) const{
    return _array[index];
}

MyArray& MyArray::operator++() {
    for(int i = 0; i < _size; i++) {
        _array[i]++;
    }
    return *this;
}

void MyArray::print(const char* text) const{
    std::cout << text << " = [";
    if(_size > 0) {
        std::cout << _array[0];
    }
    for(int i = 1; i < _size; i++) {
        std::cout << ", " << _array[i];
    }
    std::cout << "]" << std::endl;
}

int MyArray::size() const{
    return _size;
}

std::ostream& operator<<(std::ostream& stream, const MyArray& array) {
    stream << "[" << array._array[0];
    for(int i = 1; i < array._size; i++) {
        stream << ", " << array._array[i];
    }
    stream << "]" << std::endl;
    return stream;
}
