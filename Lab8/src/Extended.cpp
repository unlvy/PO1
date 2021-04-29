#include "Extended.h"

/* Point */

std::ostream& operator<< (std::ostream& os, const Point& point) {
    return os << "(" << point.m_x << ", " << point.m_y << ")";
}

Point::Point(double x, double y) : m_x(x), m_y(y) {}

double Point::getX() const {
    return m_x;
}

double Point::getY() const {
    return m_y;
}

void Point::shift(double x, double y) {
    m_x += x;
    m_y += y;
}

/* Section */

Section::Section(Point start, Point end) : m_start(start), m_end(end) {}

Point Section::getStart() const {
    return m_start;
}

Point Section::getEnd() const {
    return m_end;
}

void Section::shift(double x, double y) {
    m_start.shift(x, y);
    m_end.shift(x, y);
}

double Section::length() const {
    return sqrt(pow(m_start.getX() - m_end.getX(), 2) + pow(m_start.getY() - m_end.getY(), 2));
}

void Section::print() const {
    std::cout << "odcinek od " << m_start << " do " << m_end << std::endl;
}
 
/* Circle */

Circle::Circle(Point center, double radius) : m_center(center), m_radius(radius) {}

void Circle::shift(double x, double y) {
    m_center.shift(x, y);
}

double Circle::length() const {
    return M_PI * 2 * m_radius;
}

void Circle::print() const {
    std::cout << "kolo o srodku " << m_center << " i promieniu " << m_radius << std::endl;
}

double Circle::area() const {
    return M_PI * pow(m_radius, 2);
}

/* Deltoid */

Deltoid::Deltoid(Section diagonal1, Section diagonal2) : m_diagonal1(diagonal1), m_diagonal2(diagonal2) {}

Deltoid::Deltoid(Point diag1Start, Point diag2Start, Point diag1End, Point diag2End) : m_diagonal1(diag1Start, diag1End), m_diagonal2(diag2Start, diag2End) {}

void Deltoid::shift(double x, double y) {
    m_diagonal1.shift(x, y);
    m_diagonal2.shift(x, y);
}

double Deltoid::length() const {
    double result = 0.0;
    result += 2 * Section(m_diagonal1.getStart(), m_diagonal2.getStart()).length();
    result += 2 * Section(m_diagonal1.getEnd(), m_diagonal2.getEnd()).length();
    return result;
}

void Deltoid::print() const {
    std::cout << "deltoid o wierzcholkach " << m_diagonal1.getStart() << ", " << m_diagonal2.getStart()
              << ", " << m_diagonal1.getEnd() << ", " << m_diagonal2.getEnd() << std::endl;
}

double Deltoid::area() const {
    return m_diagonal1.length() * m_diagonal2.length() * 0.5;
}