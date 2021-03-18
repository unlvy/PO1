#pragma once

#include <iostream>

/// class representing array of integers with possibility to create list of objects
class MyArray{

public:
    
    /* ---------- CONSTRUCTORS, DESTRUCTOR ---------- */
    
    /// default constructor
    MyArray();

    /// one-agrument constructor
    explicit MyArray(int size);

    /// copy constructor
    MyArray(const MyArray& other);

    /// move constructor
    MyArray(MyArray&& other);

    /// destructor
    ~MyArray();

    /* ---------- BASIC METHODS ---------- */
    
    /** size()
     *  returns size of an array
     *  @returnValue - array`s size
     */
    int size() const;

    /** getNext()
     *  returns reference to next element of list
     *  @returnValue - next element of list
     */
    MyArray& getNext();

    /** print() const
     *  prints whole list on standard output
     *  @param text - additional text that is printed before the list
     */
    void print(const char* text) const;

    /* ---------- OPERATORS OVERLOADED AS METHODS ---------- */

    /** operator++ ()
     *  overloaded postincrementation operator
     *  @param - :)
     *  @returnValue - copy of object made before incrementation
     */
    MyArray operator++ (int);

    /** operator-- ()
     *  overloaded predecrementation operator
     *  @returnValue - decremented object
     */
    MyArray& operator-- ();

    /** operator[] ()
     *  returns reference to the element of the list with given index
     *  @param - index 
     *  @returnValue - reference to the element
     */
    int& operator[] (int index);

    /** operator[] ()
     *  returns value of the element of the list with given index
     *  @param - index 
     *  @returnValue - value of the element
     */
    int operator[] (int index) const;

    /** operator= ()
     *  assign operator (copying version)
     *  @param - object to copy
     *  @returnValue - copy
     */
    MyArray& operator= (const MyArray& other);

    /** operator= ()
     *  assign operator (moving version)
     *  @param - object to move
     *  @returnValue - moved object
     */
    MyArray& operator= (MyArray&& other);

    /** operator+= ()
     *  operator adding object to list
     *  @param - object to be added
     */
    void operator+= (MyArray& next);

    /** operator+= ()
     *  operator adding elements to array
     *  @param - array, which elements will be added
     */
    void operator+= (MyArray&& other);

    /* ---------- FRIEND FUNCTION ---------- */

    /** operator<< ()
     *  prints object on output stream
     *  @param1 - output stream
     *  @param2 - object to be printed
     *  @returnValue - output stream with printed object
     */
    friend std::ostream& operator<< (std::ostream& os, const MyArray& myArray);

private:

    /* ---------- CLASS FIELDS ---------- */

    /// array size
    int _size;
    /// array
    int* _array;
    /// pointer to the next element of the list
    MyArray* _next;
};
