#include <iostream>
#include "Dir.h"
#include "File.h"

int main() {
  std::cout << "------- 1 -------\n";
  Dir *top = new Dir(".");
  Dir *home = new Dir("home");
  *top += home; 
  Dir *stud1 = new Dir("stud1");
  *home += stud1;
  Dir *stud2 = new Dir("stud2");
  *home += stud2;  
  std::cout << const_cast<const Dir&>(*top) <<std::endl;

  std::cout << "------- 2 -------\n";
  *stud1 += new File("img1.jpg",2020);
  *stud1 += new File("img2.jpg");
  Dir* work = new Dir("work");
  *work += new File("main.h",150);
  *work += new File("proj.h",175);
  *stud1 += work;
  std::cout << *home <<std::endl;
  
  std::cout << "------- 3 -------\n";
  stud2->copy(stud1->getDir("work")); 
  if (stud1->getDir("img1.jpg")) 
    std::cout << "**** TO NIE POWINNO SIE WYPISAC ****\n";
  stud2->copy(stud1->get("img1.jpg"));
  *work += new Dir("tmp");
  Dir *tmp = static_cast<Dir*>(work->getDir("tmp"));
  *tmp += new Dir("cpp");
  std::cout << *(stud1->getDir("work"));
  
  *work -= "tmp";
  *work -= "proj.h";

  *work += new File("main.cpp"); 

  std::cout << "\n-------------" << std::endl;
  std::cout << *top;

  std::cout << "\n--------------" << std::endl;
  delete top;
}

/*  
./main
------- 1 -------
. (dir)
  home (dir)
    stud1 (dir)
    stud2 (dir)

------- 2 -------
home (dir)
  stud1 (dir)
    img1.jpg (2020)
    img2.jpg (0)
    work (dir)
      main.h (150)
      proj.h (175)
  stud2 (dir)

------- 3 -------
work (dir)
  main.h (150)
  proj.h (175)
  tmp (dir)
    cpp (dir)
Destruktor Dir: tmp
Destruktor Dir: cpp
---Destruktor File: proj.h

-------------
. (dir)
  home (dir)
    stud1 (dir)
      img1.jpg (2020)
      img2.jpg (0)
      work (dir)
        main.h (150)
        main.cpp (175)
    stud2 (dir)
      work (dir)
        main.h (150)
        proj.h (175)
      img1.jpg (2020)

--------------
Destruktor Dir: .
Destruktor Dir: home
Destruktor Dir: stud1
---Destruktor File: img1.jpg
---Destruktor File: img2.jpg
Destruktor Dir: work
---Destruktor File: main.h
---Destruktor File: main.cpp
Destruktor Dir: stud2
Destruktor Dir: work
---Destruktor File: main.h
---Destruktor File: proj.h
---Destruktor File: img1.jpg
 */ 