#pragma once

#include "Virtual.h"

/**
 * class representing point
 */
class Point : public Transformable {

protected:
    double m_x;    /** x */
    double m_y;    /** y */

public:

    /** two-argument constructor */
    Point(double x, double y);

    /**
     * returns x
     * @return double
     */
    double getX() const;

    /**
     * returns y
     * @return double
     */
    double getY() const;

    void shift(double x, double y) override;

    /**
     * prints point on output stream
     * @param os - output stream
     * @param point - point
     * @return std::ostream&
     */
    friend std::ostream& operator<< (std::ostream& os, const Point& point);
};

/**
 * class represnting section
 */
class Section : public Drawable, public Transformable {

protected:
    Point m_start;  /** start of the section */
    Point m_end;    /** end of the section */

public:

    /** two-argument constructor */
    Section(Point start, Point end);

    /**
     * returns start of the section
     * @return Point
     */
    Point getStart() const;

    /**
     * returns end of the section
     * @return Point
     */
    Point getEnd() const;

    void shift(double x, double y) override;

    double length() const override;

    void print() const override;
};

/**
 * class representing circle
 */
class Circle : public ClosedShape, public Transformable {

private:
    Point m_center;     /** center of the circle */
    double m_radius;    /** radius of the circle */

public:

    /** two arguent constructor */
    Circle(Point center, double radius);

    void shift(double x, double y) override;

    double length() const override;

    void print() const override;

    double area() const override;
};

/**
 * class representing deltoid
 */
class Deltoid : public ClosedShape, public Transformable {

private:
    Section m_diagonal1;    /** first diagonal */
    Section m_diagonal2;    /** second diagonal */

public:

    /** two-argument constructor (takes diagonals) */
    Deltoid(Section diagonal1, Section diagonal2);

    /** four-argument constructor (takes vectexes) */
    Deltoid(Point diag1Start, Point diag2Start, Point diag1End, Point diag2End);

    void shift(double x, double y) override;

    double length() const override;

    void print() const override;

    double area() const override;
};
