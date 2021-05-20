#pragma once

#include "Wrapper.h"
#include <vector>

/** 
 * class representing factory of types basing on knkown prototypes
 * types must have constructor(int)
 */
class Factory  {
private:
    /** number of exsisting factories */
    static int m_activeInstances;
    /** vector of wrapped prototypes */
    static std::vector<Wrapper*> m_prototypes;
public:

    /**
     * non-argument constructor
     */
    Factory();

    /**
     * destructor
     */
    ~Factory();

    /** 
     * template of method adding new prototype to factory
     * @param T
     */
    template<typename T>
    void prototype(T value);

    /** 
     * template of method returning type basing on known prototype or
     * T(0) if prototype doesn`t exist
     * @return T
     */
    template<typename T>
    T manufacture() const;
};

/* ---------------------- */

std::vector<Wrapper*> Factory::m_prototypes =  std::vector<Wrapper*>();

int Factory::m_activeInstances = 0;

Factory::Factory() {
    m_activeInstances++;
}

Factory::~Factory() {
    m_activeInstances--;
    if (m_activeInstances == 0) {
        for (auto* prototype : m_prototypes) {
            delete prototype;
        }
    }
}

template<typename T>
void Factory::prototype(T value) {
    for (auto* prototype : m_prototypes) {
        if (dynamic_cast<ValueWrapper<T>*>(prototype)) {
            dynamic_cast<ValueWrapper<T>*>(prototype)->set(value);
            return;
        }
    }
    m_prototypes.push_back(new ValueWrapper<T>(value));
}

template<typename T>
T Factory::manufacture() const {
    for (auto* prototype : m_prototypes) {
        if (dynamic_cast<ValueWrapper<T>*>(prototype)) {
            return dynamic_cast<ValueWrapper<T>*>(prototype)->get();
        }
    }
    std::cout << "No prototype for this type: ";
    return T(0);
}
