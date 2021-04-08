#include "Exponentiation.h"

Exponentiation::Exponentiation(double element0, double element1) : Operation(element0, element1) {}

void Exponentiation::print() const {
    std::cout << m_elements[0] << " ^ " << m_elements[1];
}

double Exponentiation::eval() const {
    return std::pow(m_elements[0], m_elements[1]);
}
