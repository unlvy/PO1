#include "Table.h"

bool sort_by_column(const Data& d1, const Data& d2, int column) {
    return d1[column] < d2[column];
} 

void Table::operator+= (const Data& data) {
    m_days.push_back(data);
}

void Table::print() const {
    for (auto& day : m_days) {
        day.print();
    }
}

Table& Table::sort(int column) {
    int min = m_days[0].size();
    for (auto& day : m_days) {
        if (day.size() < min) {
            min = day.size();
        }
    }
    if (min > column) {
        auto sorter = std::bind(sort_by_column, std::placeholders::_1, std::placeholders::_2, column);
        std::sort(std::begin(m_days), std::end(m_days), sorter);
    } else {
        std::cout << "Index " << column << " is out of range!" << std::endl;
    }
    return *this;
}

Table& Table::sortBy(std::function<bool(const Data& d1, const Data& d2)> sorter) {
    std::sort(std::begin(m_days), std::end(m_days), sorter);
    return *this;
}
