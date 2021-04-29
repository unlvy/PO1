#pragma once

#include <iostream>
#include <cmath>

/**
 * class representing drawable object
 */
class Drawable {

public:

    /** default destructor */
    virtual ~Drawable() = default;

    /**
     * prints object on standard output
     */
    virtual void print() const = 0;

    /**
     * returns length / perimeter
     * @return double
     */
    virtual double length() const = 0;

};

/**
 * class representing transformable object
 */
class Transformable {

public:
    /** default destructor */
    virtual ~Transformable() = default;

    /**
     * shifts object
     */
    virtual void shift(double x, double y) = 0;
};

/**
 * class representing closed shape
 * (shape that has surface area)
 */
class ClosedShape : public Drawable {

public:

    /**
     * returns surface area
     * @return double
     */
    virtual double area() const = 0;
};