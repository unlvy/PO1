#include "ComplexNumber.h"

// constructors

ComplexNumber::ComplexNumber (double real, double imaginary) {
    _real = real;
    _imaginary = imaginary;
}

ComplexNumber::ComplexNumber (const ComplexNumber& other) {
    _real = other._real;
    _imaginary = other._imaginary;
}

ComplexNumber::ComplexNumber(ComplexNumber&& other) {
    _real = std::__exchange(other._real, 0.0);
    _imaginary = std::__exchange(other._imaginary, 0.0);
}

// overloaded operators

ComplexNumber::operator double() const {
    return _real;
}

ComplexNumber& ComplexNumber::operator= (const ComplexNumber& other) {
    if (this != &other) {
        _real = other._real;
        _imaginary = other._imaginary;
    }
    return *this;
}

void ComplexNumber::operator*= (int multipler) {
    _real *= multipler;
    _imaginary *= multipler;
}

ComplexNumber& ComplexNumber::operator++ () {
    _real++;
    return *this;
}

ComplexNumber ComplexNumber::operator++ (int) {
    ComplexNumber result(*this);
    ++(*this);
    return result;
}

double& ComplexNumber::operator[] (unsigned index) {
    if (index == 0) {
        return _real;
    } else {
        return _imaginary;
    } 
}


// friend functions

std::ostream& operator<< (std::ostream& os, const ComplexNumber& cs) {
    if (cs._real != 0.0) {
        os << cs._real;
    } 
    if (cs._imaginary > 0.0) {
        os << " + " << cs._imaginary << "i";
    } else if (cs._imaginary < 0.0) {
        os << " - " << cs._imaginary * -1.0 << "i";
    }
    return os;
}

ComplexNumber operator+ (const ComplexNumber& cs1, const ComplexNumber& cs2) {
    return ComplexNumber(cs1._real + cs2._real, cs1._imaginary + cs2._imaginary);
}

ComplexNumber operator+ (int value, const ComplexNumber& cs) {
    return ComplexNumber(cs._real + static_cast<double>(value), cs._imaginary);
}

ComplexNumber operator* (const ComplexNumber& cs1, const ComplexNumber& cs2) {
    return ComplexNumber(cs1._real * cs2._real - cs1._imaginary * cs2._imaginary,
                         cs1._real * cs2._imaginary + cs1._imaginary * cs2._real);
}

ComplexNumber operator- (const ComplexNumber& cs1, const ComplexNumber& cs2) {
    return ComplexNumber(cs1._real - cs2._real, cs1._imaginary - cs2._imaginary);
}

bool operator< (const ComplexNumber& cs1, const ComplexNumber& cs2) {
    return sqrt(pow(cs1._real, 2) + pow(cs1._imaginary, 2)) < 
           sqrt(pow(cs2._real, 2) + pow(cs2._imaginary, 2));
}

bool operator> (const ComplexNumber& cs1, const ComplexNumber& cs2) {
    return sqrt(pow(cs1._real, 2) + pow(cs1._imaginary, 2)) > 
           sqrt(pow(cs2._real, 2) + pow(cs2._imaginary, 2));
}

