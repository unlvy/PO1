#pragma once

#include "Virtual.h"
#include "Extended.h"

void draw(const Drawable* drawable) {
    std::cout << "Rysujemy ";
    drawable->print();
}
