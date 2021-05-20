#pragma once

#include <iostream>

/** 
 * class representing car
 */
class Car {
private:
    /** name */
    std::string m_name;
public:
    /**
     * one-argument constructor
     * @param std::string
     */
    explicit Car(std::string name);

    /**
     * one-argument constructor
     * sets "Undefined" as name 
     * @param int
     */
    explicit Car(int number);

    /**
     * prints car on standard output
     */
    void print() const;
};

/* ----------------------- */

Car::Car(std::string name) : m_name(name) {}

Car::Car(int number) : m_name("Undefined") {}

void Car::print() const {
    std::cout << "Car: "<< m_name << std::endl;
}
