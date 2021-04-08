#include "SumOfElements.h"

SumOfElements::SumOfElements(const double* elements, int size) : Operation(elements, size) {}

void SumOfElements::print() const {
    if (m_size > 0) {
        std::cout << m_elements[0];
        for (int i = 1; i < m_size; i++) {
            std::cout << " + " << m_elements[i];
        }
    }
}

double SumOfElements::eval() const {
    double result = 0;
    for (int i = 0; i < m_size; i++) {
        result += m_elements[i];
    }
    return result;
}
