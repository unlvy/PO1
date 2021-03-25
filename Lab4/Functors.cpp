#include "Functors.h"

DivisibleBy::DivisibleBy(int value) : m_value(value) {}

bool DivisibleBy::operator() (int number) const {
    return !(number % m_value);
}

LowerThan::LowerThan(int value) : m_value(value) {}

bool LowerThan::operator() (int number) const {
    return number < m_value;
}
