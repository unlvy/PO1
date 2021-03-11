#pragma once

#include <iostream>
#include <cmath>

/// class representing complex numbers
class ComplexNumber {

public:

                // constructors, destructor

    /// two-argument constructor
    explicit ComplexNumber (double real, double imaginary = 0.0);

    /// copy constructor
    ComplexNumber (const ComplexNumber& other);

    /// move constructor
    ComplexNumber (ComplexNumber&& other);

    /// destructor
    ~ComplexNumber() = default;

                // operators overloaded as methods
    /**
     * overloaded double() operator
     * casts ComplexNumber object to double by returning real part
     * @returnValue real part of complex number
     */
    operator double() const;

    /**
     * overloaded = operator
     * assigns values of fields from object on the right to the object on the left 
     * @param - object, which fileds are copied
     * @returnValue - *this, with overwritten values
     */
    ComplexNumber& operator= (const ComplexNumber& other);

    /**
     * overloaded *= operator
     * mutiplies real and imaginary part of complex number by multipler
     * @param - multipler
     */
    void operator*= (int multipler);

    /**
     * overloaded pre-incrementation operator
     * increments value of real part
     * @returnValue - *this with incremented real part
     */
    ComplexNumber& operator++ ();

    /**
     * overloaded post-incrementation operator
     * creates and returns copy of object, then increments real part 
     * @param / hmmmm /
     * @returnValue copy of object made before incrementation
    ComplexNumber operator++ (int);

    /**
     * overloaded [] operator
     * returns reference to fields of object, for 0 - _real, for any other number - _imaginary
     * @param - index of field which we want to access
     * @returnValue - reference to field
     */
    double& operator[] (unsigned index);


                // friend functions

    /**
     * overloaded << operator
     * prints object on exit
     * @param1 - output stream
     * @param2 - reference to object which is to be printed 
     * @returnValue - output stream
     */
    friend std::ostream& operator<< (std::ostream& os, const ComplexNumber& cs);

    /**
     * overloaded + operator
     * adds two complex numbers
     * @param1 - first number
     * @param2 - second number
     * @returnValue - new object that is sum of given arguments
     */
    friend ComplexNumber operator+ (const ComplexNumber& cs1, const ComplexNumber& cs2);

    /**
     * overloaded + operator
     * adds number to real part of complex number
     * @param1 - number
     * @param2 - complex number
     * @returnValue - new object that is sum of given arguments
     */
    friend ComplexNumber operator+ (int value, const ComplexNumber& cs);

    /**
     * overloaded * operator
     * multiplies two complex numbers
     * @param1 - first number
     * @param2 - second number
     * @returnValue - new object that is product of multiplication of given arguments
     */
    friend ComplexNumber operator* (const ComplexNumber& cs1, const ComplexNumber& cs2);

    /**
     * overloaded - operator
     * subtracts two complex numbers
     * @param1 - first number
     * @param2 - second number
     * @returnValue - new object that is difference of given arguments
     */
    friend ComplexNumber operator- (const ComplexNumber& cs1, const ComplexNumber& cs2);

    /**
     * overloaded < operator
     * compares two complex numbers
     * @param1 - firs number
     * @param2 - second number
     * @returnValue - product of comparison (l1 < l2)
     */
    friend bool operator< (const ComplexNumber& cs1, const ComplexNumber& cs2);

    /**
     * overloaded > operator
     * compares two complex numbers
     * @param1 - firs number
     * @param2 - second number
     * @returnValue - product of comparison (l1 > l2)
     */
    friend bool operator> (const ComplexNumber& cs1, const ComplexNumber& cs2);

private:

    /// real part of complex number
    double _real;

    /// imaginary part of complex number
    double _imaginary;

};
