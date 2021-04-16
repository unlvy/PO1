#pragma once

#include <iostream>
#include "rna.h"

/** class representing virus */
class Virus {

protected:

    std::string m_name;     /** name */
    RNA* m_rna;             /** virus RNA */
    int m_age;              /** virus AGE */
public:

    /**
     * 1-arguemetn constructor
     */
    Virus(std::string name);

    /**
     * copy constructor (doesn`t increment age)
     */
    Virus(const Virus& other);

    /**
     * copy constructor (increments age)
     */
    Virus(Virus& other);

    /**
     * move constructor (mutates RNA)
     */
    Virus(Virus&& other);
    
    /**
     * destructor
     */
    virtual ~Virus();

    /**
     * overloaded = operator
     * copies objects
     * @param other - object to be copied
     * @returnValue - created copy
     */
    Virus& operator= (const Virus& other);

    /**
     * overloaded = operator
     * moves objects
     * @param other - object to be moved
     * @returnValue - moved object
     */
    Virus& operator= (Virus&& other);

    /**
     * set_RNA
     * method setting m_rna field
     * @param seq - new RNA sequence
     */
    virtual void set_RNA(std::vector<Nukleotyp> seq);

    /**
     * get_name
     * method returning field name
     * @returnValue - virus name
     */
    virtual std::string get_name() const;

    /**
     * get_RNA
     * metoda returning m_rna field
     * @returnValue - virus RNA sequence
     */
    virtual RNA* get_RNA() const;

     /**
     * get_age
     * method returning field m_age
     * @returnValue - virus age
     */
    virtual int get_age() const;
    
};
