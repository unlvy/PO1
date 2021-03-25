#include "List.h"

void List::print(const char* text) const {
    std::cout << text << "[";
    if (m_list.size() > 0) {
        std::cout << m_list[0];
    }
    for (int i = 1; i < (int)m_list.size(); i++) {
        std::cout << ", " << m_list[i];
    }
    std::cout << "]" << std::endl;
}

void List::insert(int number) {
    m_list.push_back(number);
}

int& List::operator[] (int index) {
    if (index < 0 || index >= (int)m_list.size()) {
        std::cout << "WRONG INDEX!" << std::endl;
        exit(-1);
    } else {
        return m_list[index];
    }
}

List List::filter(std::function<bool(int)> filter) const {
    List result;
    for (int i = 0; i < (int)m_list.size(); i++) {
        if (filter(m_list[i])) {
            result.insert(m_list[i]);
        }
    }
    return result;
}
