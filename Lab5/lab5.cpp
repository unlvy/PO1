#include <iostream>
#include <memory>

#include "Division.h"
#include "Exponentiation.h"
#include "SumOfElements.h"

int main() {
  Division divide(4,2.5);
  Exponentiation pow(5, 0.5);
  const int n = 4;
  double numbers[n] = {1,3.2,5,11};
  const SumOfElements suma(numbers, n);

  "***" >>= divide;
  "---" >>= pow;
  "===" >>= suma;

std::unique_ptr <Operation> d1(new Division(7,2));
  "---" >>= *d1;

std::unique_ptr <Operation> d2(new SumOfElements(numbers, n));
  "___" >>= *d2;

  std::cout << "=====================================" << std::endl;
    
  const Operation* all[] = {&divide, &pow, &suma}; 
  for ( unsigned idx = 0; idx < sizeof(all)/sizeof(Operation*); ++idx ) {
    const Operation* d = all[idx];
    d->print(); 
    std::cout << " = " << d->eval() << std::endl;
  }  
}
/* output

*** 4 / 2.5 ***
--- 5 ^ 0.5 ---
=== 1 + 3.2 + 5 + 11 ===
--- 7 / 2 ---
___ 1 + 3.2 + 5 + 11 ___
=====================================
4 / 2.5 = 1.6
5 ^ 0.5 = 2.23607
1 + 3.2 + 5 + 11 = 20.2

 */
