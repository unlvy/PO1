#include "virus.h"
   
Virus::Virus(std::string name) : m_name(name), m_rna(nullptr), m_age(0) {}

Virus::Virus(const Virus& other) : m_name(other.m_name), m_rna(new RNA(*other.m_rna)), m_age(0) {}

Virus::Virus(Virus& other) : m_name(other.m_name), m_rna(new RNA(*other.m_rna)), m_age(0) {
    other.m_age++;
}

Virus::Virus(Virus&& other) : m_name(std::move(other.m_name)), m_rna(std::__exchange(other.m_rna, nullptr)), m_age(std::move(other.m_age)) {
    m_rna->mutate();
}

Virus::~Virus() {
    if (m_rna != nullptr) {
        delete m_rna;
    }
}

Virus& Virus::operator= (const Virus& other) {
    if (this != &other) {
        if (m_rna != nullptr) {
            delete m_rna;
        }
        m_rna = new RNA(*other.m_rna);
        m_name = other.m_name;
        m_age = 0;
    }
    return *this;
}

Virus& Virus::operator= (Virus&& other) {
    if (this != &other) {
        m_name = std::move(other.m_name);
        m_rna = std::__exchange(other.m_rna, nullptr);
        m_age = std::move(other.m_age);
        m_rna->mutate();
    }
    return *this;
}

void Virus::set_RNA(std::vector<Nukleotyp> seq) {
    if (m_rna != nullptr) {
        delete m_rna;
    }
    m_rna = new RNA(seq);
}

std::string Virus::get_name() const {
    return m_name;
}

RNA* Virus::get_RNA() const {
    return m_rna;
}

int Virus::get_age() const {
    return m_age;
}
