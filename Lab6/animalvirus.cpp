#include "animalvirus.h"

AnimalVirus::AnimalVirus() : Virus("undefined"), m_host("undefined") {}

AnimalVirus::AnimalVirus(const AnimalVirus& other) : Virus(other) {
    m_host = other.m_host;
}

AnimalVirus::AnimalVirus(AnimalVirus& other) : Virus(other) {
    m_host = other.m_host;
}

AnimalVirus::AnimalVirus(AnimalVirus&& other) : Virus(other) {
    m_host = std::move(other.m_host);
}

AnimalVirus& AnimalVirus::operator= (const AnimalVirus& other) {
    if (this != &other) {
        Virus::operator=(other);
        m_host = other.m_host;
    }
    return *this;
}

AnimalVirus& AnimalVirus::operator= (AnimalVirus&& other) {
    if (this != &other) {
        Virus::operator=(other);
        m_rna->mutate();
        m_host = std::move(other.m_host);
    }
    return *this;
}

AnimalVirus::AnimalVirus(std::string name, std::string host, const RNA& seq) : Virus(name), m_host(host) {
    m_rna = new RNA(seq);
}

std::string AnimalVirus::get_animal_host() const {
    return m_host;
}
