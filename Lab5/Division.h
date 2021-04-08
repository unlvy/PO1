#include "Operation.h"

/// class representing operation of division
class Division : public Operation {

public:

    /// two-argument constructor (for two elements)k
    Division(double element0, double element1);

    void print() const override;

    double eval() const override;
};
