#include "Sum.h"

void Sum::operator() (double value) {
    m_sum += value;
}

double Sum::value() const {
    return m_sum;
}

sumData::sumData(const Data& data) {
    m_sum = data.sum();
}
