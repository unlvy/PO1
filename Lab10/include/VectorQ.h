#pragma once

#include "Persons.h"

#include <vector>
#include <memory>
#include <map>
#include <algorithm>

/**
 * class representing customers queue
 */
class VectorQ {

private:

    std::vector<std::unique_ptr<Person>> m_customers;   /** customers container */

public:

    /**
     * method adding customer to queue
     * @param - std::unique_ptr<Person>
     */
    void add(std::unique_ptr<Person> customer);

    /**
     * method printing queue on standard output
     * @param text - std::string
     */
    void print(std::string text) const;

    /**
     * method returning vector of all woman present in queue
     * @return - std::vector<Woman*>
     */
    std::vector<Woman*> getWomen();

    /**
     * method calculating occurences of specifics names
     */
    void countNames() const;

    /**
     * method that provides first customer with given name with a new haircut
     * @param - std::string
     */
    void haircut(std::string name);

    /**
     * method providing first customer in queue with a new haircut
     */
    void haircut();

    /**
     * method shaving beard of first customer with given name
     * @param - std::string
     */
    void shave(std::string name);

    /**
     * method shaving beard of first customer in queue
     */
    void shave();
    
};
