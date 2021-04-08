#pragma once

#include <iostream>
#include <string>
#include <cmath>

/// class representing mathematic operations
class Operation {

protected:

    /// array of arguments
    double* m_elements;

    /// number of arguments
    double m_size;

public:

    /// two-argument constructor (for two elements)
    Operation(double element0, double element1);

    /// two-argument constructor (for array of elements)
    Operation(const double* elements, int size);

    /// destructor
    virtual ~Operation();

    /**
     * method printing operation on standard output
     */
    virtual void print() const = 0;

    /**
     * method returning result of operation
     */
    virtual double eval() const = 0;

    /**
     * overloaded >>= operator
     * prints operation on standard output, also printing given string before and after operation
     * @param1 text - string to be printed before and after printing operation
     * @param2 operation - operation to be printed
     */
    friend void operator>>= (const std::string& text, const Operation& operation);
};
