#include "List.h"
#include "FilterCriteria.h"
#include "Functors.h"
#include <iostream>

bool positive(int x){
	return x >= 0;
}

int main() {

	List l1;
	for (int i = 0; i < 8; ++i){
		int sign = i % 2 ? 1 : -1;
		l1.insert(i * sign);
	}
  l1.print("l1: ");
  l1[3] = 10;
  l1.print("l1: ");
  
  List l2=l1.filter([](auto elem) { return elem <= 5;});
  l2.print("l2 <= 5: ");
  l2=l1.filter([](auto elem) { return elem % 2;});
  l2.print("l2 odd?:");
  const List l3 = l1.filter(positive);
  l3.print("l3 >= 0: ");

  std::cout << "\nFunctors\n";
  DivisibleBy divisible(3);
  LowerThan lower(0);
  std::cout << std::boolalpha;
  std::cout << "(9 % 3 == 0)? " << divisible(9) << std::endl;
  std::cout << "(9 < 0)? " << lower(9) << std::endl;
  
  l2=l1.filter(LowerThan(-2));
  l2.print("l2 < -2: ");  
  l2=l1.filter(lower);
  l2.print("l2 > 0: ");
  l2=l1.filter(DivisibleBy(5));
  l2.print("l2 % 5 == 0: ");  
  l2=l1.filter(divisible);
  l2.print("l2 % 3 == 0: ");
	
  std::cout << "\nFilterCriteria\n";
	FilterCriteria criteria;
	criteria.add(lower);
	criteria.add(divisible);
	criteria.add(positive);

	for (int i = 0; i < criteria.size(); ++i){
		l1.filter(criteria.get(i)).print();
	}
	
}
/* output
./main
l1: [0, 1, -2, 3, -4, 5, -6, 7]
l1: [0, 1, -2, 10, -4, 5, -6, 7]
l2 <= 5: [0, 1, -2, -4, 5, -6]
l2 odd?:[1, 5, 7]
l3 >= 0: [0, 1, 10, 5, 7]

Functors
(9 % 3 == 0)? true
(9 < 0)? false
l2 < -2: [-4, -6]
l2 > 0: [-2, -4, -6]
l2 % 5 == 0: [0, 10, 5]
l2 % 3 == 0: [0, -6]

FilterCriteria
[-2, -4, -6]
[0, -6]
[0, 1, 10, 5, 7]
*/
