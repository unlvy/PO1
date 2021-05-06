#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>

/**
 * function printing argument on std out
 * @param value - double
 */
void printer(double value);

/**
 * class represnting daily expenses
 */
class Data {

private:
    std::string m_name;                 /** day name */
    std::vector<double> m_expenses;     /** expenses container */

public:

    /**
     * two-argument constructor
     */
    Data(std::string name, std::vector<double> expenses);

    /**
     * method printing data on std out
     */
    void print() const;

    /**
     * method returning sum of all expenses
     * @return - double
     */
    double sum() const;

    /**
     * method returning value at given index
     * @param - int
     * @return - double
     */
    double operator[] (int index) const;

    /**
     * method returning size of expenses container
     * @return - int
     */
    int size() const;
};
