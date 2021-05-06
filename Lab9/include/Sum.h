#pragma once

#include "Data.h"

/**
 * class that sums values
 */
class Sum {

protected:
    double m_sum = 0.0;     /** sum */

public:

    /**
     * default destructor
     */
    virtual ~Sum() = default;
    
    /**
     * method adding value to sum
     * @param - double
     */
    void operator() (double value);

    /**
     * method returning value of sum
     * @return - double
     */
    double value() const;
};

/**
 * class that sums expenses from day
 */
class sumData : public Sum {

public:

    /**
     * one-argument constructor
     */
    explicit sumData(const Data& data);
};
