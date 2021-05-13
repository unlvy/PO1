#include "Persons.h"

/* Man */

Man::Man(std::string name, bool needsHaircut, bool hasBeard) : Person(name, false, needsHaircut), m_hasBeard(hasBeard) {}

Man::~Man() {
    print();
    std::cout << " idzie na piwko" << std::endl;
}

void Man::print() const {
    std::cout << _name << ( _haircut ? " nieobciety" : " obciety" ) 
              << " i " << ( m_hasBeard ? "nieogolony" : "ogolony" );
}
    
bool Man::done() const {
    if (!_haircut && !m_hasBeard) return true;
    else return false;
}

void Man::makeup() {}

void Man::shave() {
    if(m_hasBeard) m_hasBeard = false;
    else std::cout << "\n!!! Klient juz ogolony !!!";
}

/* Woman */

Woman::Woman(std::string name, bool needsHaircut, bool hasNoMakeup) : Person(name, true, needsHaircut), m_hasNoMakeup(hasNoMakeup) {}

Woman::~Woman() {
    print();
    std::cout << " idzie na zakupy" << std::endl;
}

void Woman::print() const {
    std::cout << _name << ( _haircut ? " nieobcieta" : " obcieta" ) 
              << " i " << ( m_hasNoMakeup ? "nieumalowana" : "umalowana" );
}

bool Woman::done() const {
    if (!_haircut && !m_hasNoMakeup) return true;
    else return false;
}

void Woman::makeup() {
    if(m_hasNoMakeup) m_hasNoMakeup = false;
    else std::cout << "\n!!! Klientka juz umalowana !!!";
}

void Woman::shave() {}
