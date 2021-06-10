#include "Functions.h"

Function::Function(std::string type) : m_type(type) {} 

std::string Function::getType() const {
    return m_type;
}

Asin::Asin() : Function("arcsin") {}

double Asin::calculate(double x) const {
    if (x <= -1.0 || x >= 1.0) { 
        throw std::invalid_argument("wrong argument of arcsin"); 
    } 
    return std::asin(x);
}

Log10::Log10() : Function("log10") {}

double Log10::calculate(double x) const {
    if (x < 0.0) { 
        throw std::invalid_argument("wrong argument of log10"); 
    } 
    return std::log10(x);
}

DivideBy::DivideBy(double numerator) : Function("DivideBy"), m_numerator(numerator) {}

double DivideBy::calculate(double x) const {
    if (x == 0.0) { 
        throw std::invalid_argument("divide by zero!"); 
    } 
    return m_numerator / x;
}
