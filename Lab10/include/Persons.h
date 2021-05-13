#pragma once

#include "Person.h"

/**
 * class representing male person
 */
class Man : public Person {

private:

    bool m_hasBeard;    /** field informing if man has a beard */

public:

    /**
     * three-argument constructor
     * @param - std::string
     * @param - bool
     * @param - bool
     */
    explicit Man(std::string name, bool needsHaircut = true, bool hasBeard = true);

    /** destructor */
    ~Man();

    void print() const override;

    bool done() const override;

    void makeup() override;

    void shave() override;

};

/**
 * class representing female person
 */
class Woman : public Person {

private:

    bool m_hasNoMakeup;     /** field informing if woman has no makeup */

public:

    /**
     * three-argument constructor
     * @param - std::string
     * @param - bool
     * @param - bool
     */
    explicit Woman(std::string name, bool needsHaircut = true, bool hasNoMakeup = true);

    /** destructor */
    ~Woman();

    void print() const override;

    bool done() const override;
    
    void makeup() override;
    
    void shave() override;
    
};
