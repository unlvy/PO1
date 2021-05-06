#include "Data.h"

void printer(double value) {
    std::cout << std::setw(6) << value;
};

Data::Data(std::string name, std::vector<double> expenses) : m_name(name), m_expenses(expenses) {}

void Data::print() const {
    std::cout << m_name << ":";
    std::for_each(std::begin(m_expenses), std::end(m_expenses), printer);
    std::cout << std::endl;
}

double Data::sum() const {
    return std::accumulate(std::begin(m_expenses), std::end(m_expenses), 0.0);
}

double Data::operator[] (int index) const {
    return m_expenses[index];
}

int Data::size() const {
    return m_expenses.size();
}
