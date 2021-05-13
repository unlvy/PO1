#include "VectorQ.h"

void VectorQ::add(std::unique_ptr<Person> customer) {
    m_customers.push_back(std::move(customer));
}

void VectorQ::print(std::string text) const {
    std::cout << text << std::endl;
    for (auto& customer : m_customers) {
        customer->print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<Woman*> VectorQ::getWomen() {
    std::vector<Woman*> women;
    for (auto &customer : m_customers) {
        if (customer->is_woman()) {
            women.push_back(static_cast<Woman*>(customer.get()));
        }
    }
    return women;
}

void VectorQ::countNames() const {
    std::map<std::string, int> names;
    for (auto& customer : m_customers) {
        if (names.find(customer->name()) == std::end(names)) {
            names[customer->name()] = 1;
        } else {
            names[customer->name()]++;
        }
    }

    for (auto& name : names) {
        std::cout << name.first << " : " << name.second << std::endl;
    }
}

void VectorQ::haircut(std::string name) {
     for (auto& customer : m_customers) {
        if (customer->name() == name) {
            customer->haircut();
            if (customer->done()) {
                m_customers.erase(std::find(m_customers.begin(), m_customers.end(), customer));
            }
            return;
        }
    }
}

void VectorQ::haircut() {
    haircut(m_customers[0]->name());
}

void VectorQ::shave(std::string name) {
    for (auto& customer : m_customers) {
        if (customer->name() == name) {
            customer->shave();
            if (customer->done()) {
                m_customers.erase(std::find(m_customers.begin(), m_customers.end(), customer));
            }
            return;
        }
    }
}

void VectorQ::shave() {
    shave(m_customers[0]->name());
}
