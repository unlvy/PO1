#include "Operation.h"

Operation::Operation(double element0, double element1) : m_size(2) {
    m_elements = new double[2];
    m_elements[0] = element0;
    m_elements[1] = element1;
}

Operation::Operation(const double* elements, int size) : m_size(size) {
    m_elements = new double[size];
    for (int i =  0; i < m_size; i++) {
        m_elements[i] = elements[i];
    }
}

Operation::~Operation() {
    if (m_elements != nullptr) {
        delete[] m_elements;
    }
}

void operator>>= (const std::string& text, const Operation& operation) {
    std::cout << text << " ";
    operation.print();
    std::cout << " " << text << std::endl;
}
