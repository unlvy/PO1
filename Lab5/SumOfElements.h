#include "Operation.h"

/// class representing operation of summation
class SumOfElements : public Operation {

public:

    /// two-argument constructor (for array of elements)
    SumOfElements(const double* elements, int size);

    void print() const override;
    
    double eval() const override;

};
