#include "MyArray.h"
#include <iostream>

int main() 
{    
    MyArray tab1(5), tab2(3);
    std::cout << "tab1 = " << tab1 << std::endl;
    
    for(int i = 0; i<tab1.size(); ++i) {
        tab1[i] = i*2;
    }
    std::cout << "tab1 = " << tab1++ << std::endl;
    std::cout << "tab1++ = " << tab1 << std::endl;
    std::cout << "--tab2 = " << --tab2 << std::endl;
   
    const MyArray tab1Copy = tab1;
    std::cout << "tab1Copy = " << tab1 << std::endl;
        
    tab1[4] = 19;
    std::cout <<  "tab1[4] = " << tab1[4] << ", " << 
                 "tab1Copy[4] = " << tab1Copy[4] << std::endl;
        
    MyArray tab3(4);
    std::cout << "tab3 = " << tab3 << std::endl;
    tab3 = tab3 = tab1;
    std::cout << "tab3 = " << tab3 << std::endl;
    
    std::cout << "tab1 = " << tab1 << std::endl;
    MyArray mtab1 = std::move(tab1);
    std::cout << "tab1 = " << tab1 << std::endl;
    std::cout << "moved tab1 = " << mtab1 << std::endl;
   
    mtab1+=tab2;
    std::cout << "next = " << mtab1.getNext() << std::endl;
    mtab1.getNext()[1]=100;
    mtab1+=tab3;
    std::cout << "next = " << tab2.getNext() << std::endl;
    mtab1.print("Mtab1: ");
    MyArray mtab1Copy = mtab1;
    std::cout << "\ntab[6]= " << mtab1[6] << std::endl;
  
    MyArray newtab(3);
    newtab+=std::move(tab3);
    newtab.print("Newtab: ");
    mtab1+=std::move(MyArray(3));
    mtab1.print("\nMtab1: ");
    std::cout << "\nnext = " << mtab1.getNext() << std::endl;
    std::cout << "tab[9]= " << mtab1[9] << std::endl;
}
