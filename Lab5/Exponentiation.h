#include "Operation.h"

/// class representing operation of exponentiation
class Exponentiation : public Operation {

public:

    /// two-argument constructor (for two elements)
    Exponentiation(double element0, double element1);

    void print() const override;

    double eval() const override;

};
