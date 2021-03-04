#include "MyArray.h"
#include <iostream>


int main() 
{
    
    //----------------------------------------------------
    MyArray arr(6);
    arr.print("arr");
    //----------------------------------------------------
    for(int i = 0; i < arr.size(); ++i)
    {
        arr[i] = i;
    }
    arr.print("arr");
    //----------------------------------------------------
    std::cout << "arr = " << arr << std::endl;
    //----------------------------------------------------
    ++arr;
    arr.print("arr");
    //----------------------------------------------------
    const MyArray arrCopy = arr;
    arrCopy.print("copy");  
    //----------------------------------------------------
    arr[4] = 99;
    std::cout <<  "arr[5] = " << arr[4] << ", " << 
               "copy[5] = " << arrCopy[4] << std::endl; 
    //----------------------------------------------------
    MyArray arr2(4);
    arr2.print("arr2");
    arr2 = arr2 = arr;
    arr2.print("arr2");
    //----------------------------------------------------
    arr.print("arr");
    MyArray marr = std::move(arr);
    arr.print("arr");
    marr.print("moved arr");
    //----------------------------------------------------

}
