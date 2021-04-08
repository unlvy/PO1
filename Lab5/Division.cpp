#include "Division.h"

Division::Division(double element0, double element1) : Operation(element0, element1) {}

void Division::print() const {
    std::cout << m_elements[0] << " / " << m_elements[1];
}

double Division::eval() const {
    return m_elements[0] / m_elements[1];
}
