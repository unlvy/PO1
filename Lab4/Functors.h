#pragma once

#include <iostream>
#include <functional>

/// class creating functors checking if number is divisible by given in constructor value
class DivisibleBy {

private:

    /// functor checks if given number is divisible by this value
    int m_value;

public:

    /// one-argument constructor
    explicit DivisibleBy(int value);

    /* operator()
     * overloaded() operator checking if given number is divisble by member value
     * @param number - number
     * @returnValue - true if is divisible, false otherwise
     */
    bool operator() (int number) const;
};

/// class creating functors checking if number is lower than value given in constructor
class LowerThan {

private:

    /// functor checks if given number is lower than this value
    int m_value;

public:

    /// one-argument constructor
    explicit LowerThan(int value);

    /* operator()
     * overloaded () operator checking if given number is lower than member value
     * @param number - number
     * @returnValue - true if is lower, false otherwise
     */
    bool operator() (int number) const;
};
