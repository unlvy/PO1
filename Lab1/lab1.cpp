#include "MyArray.h"
#include <iostream>


int main() 
{
    std::cout << "Zadanie zaliczeniowe: Moja tablica liczb calkowitych!" << std::endl;
    
    //----------------------------------------------------
  	std::cout << "\nKonstruktor obiektu i metoda print" << std::endl;
    MyArray arr(6);
    arr.print("arr");
    
    //----------------------------------------------------
    std::cout << "\nOperator dostępu i metoda size" << std::endl;
    for(int i = 0; i < arr.size(); ++i)
    {
        arr[i] = i;
    }
    arr.print("arr");
    
    //----------------------------------------------------
    std::cout << "\nOperator wypisywania na ekran" << std::endl;
	std::cout << "arr = " << arr << std::endl;
    
    //----------------------------------------------------
    std::cout << "\nInkrementacja" << std::endl;
    ++arr;
    arr.print("arr");
    
    //----------------------------------------------------
    std::cout << "\nKonstruktor kopiujący" << std::endl;
    const MyArray arrCopy = arr;
    arrCopy.print("copy");
        
    //----------------------------------------------------
    std::cout << "\nSprawdzenie glebokiej kopii" << std::endl;
    arr[4] = 99;
    std::cout <<  "arr[5] = " << arr[4] << ", " << 
                 "copy[5] = " << arrCopy[4] << std::endl;
        
    //----------------------------------------------------
    std::cout << "\nOperator przypisania" << std::endl;
    MyArray arr2(4);
    arr2.print("arr2");
    arr2 = arr2 = arr;
    arr2.print("arr2");
    
    //----------------------------------------------------
    std::cout << "\nKonstruktor przenoszacy" << std::endl;
    arr.print("arr");
    MyArray marr = std::move(arr);
    arr.print("arr");
    marr.print("moved arr");
    
    //----------------------------------------------------
    std::cout << "\nDestruktory" << std::endl;
}
