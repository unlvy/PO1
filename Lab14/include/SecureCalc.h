#pragma once

#include "Functions.h"

/** namepsace containing run function */
namespace SecureCalc {

    /**
     * allows to perform secure calculations, prints results on
     * std::out, handles std::invalid_argument exception
     * @param class representing math functions
     * @param function argument
     */
    void run(const Function& f, double x) {

        std::cout << "Obliczamy " << f.getType() << "(" << x << ")" << std::endl << "-> ";

        try {
            double result = f.calculate(x);
            std::cout << "Wynik: " << result << std::endl;
        } 
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

};
