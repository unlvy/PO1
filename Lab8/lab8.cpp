#include <iostream>
#include "main.h"

// #define ERROR1
// #define ERROR2

int main() {
	const Point p(1.5, 3.0);
	std::cout << "Punkt " << p << std::endl;

	Circle kolo(p, 3); 					

	Section ab(Point(0, 1), Point(-3, 5));

	Section diag1(Point(0.5, 1.0), Point(5.0, 1.0)), 
	        diag2(Point(2, 0), Point(2, 2));
	Deltoid delt1(diag1, diag2); 			

    Deltoid delt2(Point(0, 0), Point(2.5, 0), Point(2.5, 2.5), Point(0, 2.5));

	unsigned numObj = 4;
	Drawable *list[]{&kolo, &ab, &delt1, &delt2};
	for (unsigned i = 0; i < numObj; ++i){
		std::cout << "\n*** Obiekt " << i+1 << " ***\n";
		draw(list[i]); 
		std::cout << "Dlugosc/Obwod = " << list[i]->length() << std::endl;

		Transformable *t = dynamic_cast<Transformable*>(list[i]);
		if(t) t->shift(1.0, 1.0);
		draw(list[i]); 

		const ClosedShape *shape = dynamic_cast<const ClosedShape*>(list[i]);
		if(shape) std::cout << "Pole = " << shape->area() << std::endl;
	}
	Transformable *t = &delt2;
	t->shift(2.0, 2.0);
	draw(&delt2);

	#ifdef ERROR1
	Drawable* d = t; 
	#endif
	#ifdef ERROR2
	Transformable* t2 = list[0]; 
	#endif
  return 0;
}

/* 
Punkt (1.5, 3)

*** Obiekt 1 ***
Rysujemy kolo o srodku (1.5, 3) i promieniu 3
Dlugosc/Obwod = 18.8496
Rysujemy kolo o srodku (2.5, 4) i promieniu 3
Pole = 28.2743

*** Obiekt 2 ***
Rysujemy odcinek od (0, 1) do (-3, 5)
Dlugosc/Obwod = 5
Rysujemy odcinek od (1, 2) do (-2, 6)

*** Obiekt 3 ***
Rysujemy deltoid o wierzcholkach (0.5, 1), (2, 0), (5, 1), (2, 2)
Dlugosc/Obwod = 9.93011
Rysujemy deltoid o wierzcholkach (1.5, 2), (3, 1), (6, 2), (3, 3)
Pole = 9

*** Obiekt 4 ***
Rysujemy deltoid o wierzcholkach (0, 0), (2.5, 0), (2.5, 2.5), (0, 2.5)
Dlugosc/Obwod = 10
Rysujemy deltoid o wierzcholkach (1, 1), (3.5, 1), (3.5, 3.5), (1, 3.5)
Pole = 12.5
Rysujemy deltoid o wierzcholkach (3, 3), (5.5, 3), (5.5, 5.5), (3, 5.5)
 */