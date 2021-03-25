#include "FilterCriteria.h"

void FilterCriteria::add(std::function<bool(int)> filter) {
    m_filters.emplace_back(filter);
}

int FilterCriteria::size() const {
    return m_filters.size();
}

std::function<bool(int)> FilterCriteria::get(int index) {
    if (index < 0 || index >= (int)m_filters.size()) {
        std::cout << "WRONG INDEX!" << std::endl;
        exit(-1);
    } else {
        return m_filters[index];
    } 
}
