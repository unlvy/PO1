#pragma once

#include "virus.h"

/** class representing animal virus */
class AnimalVirus : public Virus {

private:

    std::string m_host;     /** animal hosting virus */

public: 

    /**
     * basic constructor
     */
    AnimalVirus();

    /**
     * 3-argument constructor
     */
    AnimalVirus(std::string name, std::string host, const RNA& seq);

    /**
     * copy constructor (doesn`t increment age)
     */
    AnimalVirus(const AnimalVirus& other);

    /**
     * copy constructor (increments age)
     */
    AnimalVirus(AnimalVirus& other);

    /**
     * move constructor (mutates RNA)
     */
    AnimalVirus(AnimalVirus&& other);

    /**
     * overloaded = operator
     * copies objects
     * @param other - object to be copied
     * @returnValue - created copy
     */
    AnimalVirus& operator= (const AnimalVirus& other);

    /**
     * overloaded = operator
     * moves objects
     * @param other - object to be moved
     * @returnValue - moved object
     */
    AnimalVirus& operator= (AnimalVirus&& other);

    /**
     * get_animal_host
     * metohod returning m_host field
     * @returnValue - host of the virus
     */    
    std::string get_animal_host() const;

};
