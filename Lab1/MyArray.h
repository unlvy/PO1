#pragma once

#include <iostream>


class MyArray {

    /// Class representing an array of integers

    public:
        
        /// Constructors
        explicit MyArray();
        MyArray(int sizeOfArray);
        MyArray(const MyArray& other);
        MyArray(MyArray&& other);

        /// Destructor
        ~MyArray();

        /** Overloaded = operator 
         *  Creates copy of given object
         *  @param other - an object to be copied
         *  @returnValue - created copy
         */
        MyArray& operator= (const MyArray& other);
        
        /** Overloaded [] operator 
         *  Returns dereference of an integer from array
         *  @param index - index 
         *  @returnValue - dereference
         */
        int& operator[](int index) const;

        /** Overloaded ++ operator 
         *  Increments all elements of array
         *  @returnValue - array with incremented elements
         */
        MyArray& operator++();

        /** Method printing array
         *  @param text - string printed before array
         */
        void print(const char* text) const;

        /** Method returning size of array
         *  @returnValue - size of array
         */
        int size() const; 

        /** Friend overloaded << operator
         *  Prints array
         *  @param1 stream
         *  @param2 array - object to be printed
         *  @returnValue 
         */
        friend std::ostream& operator<<(std::ostream& stream, const MyArray& array);

    private:
        /// size of array
        int _size;
        /// array
        int* _array;

};

