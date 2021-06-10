#include "SecureCalc.h"
#include "Functions.h"
#include <iostream>
#include <stdexcept>
#include <cmath>


int main() {
	SecureCalc::run(Asin{}, 0.5);
	SecureCalc::run(Asin{}, M_PI/2);
	
	SecureCalc::run(Log10{}, 1e-10);
	SecureCalc::run(Log10{}, -20);
	
	SecureCalc::run(DivideBy{2.5}, -0.4);
	SecureCalc::run(DivideBy{1.6}, 0);
}

/* oczekiwany wynik:

Obliczamy: arcsin(0.5)
-> Wynik: 0.523599
Obliczamy: arcsin(1.5708)
-> Error: wrong argument of arcsin
Obliczamy: log10(1e-10)
-> Wynik: -10
Obliczamy: log10(-20)
-> Error: wrong argument of log10
Obliczamy: DivideBy(-0.4)
-> Wynik: -6.25
Obliczamy: DivideBy(0)
-> Error: divide by zero!
 */