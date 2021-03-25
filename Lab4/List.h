#pragma once

#include <iostream>
#include <vector>
#include <functional>

/// class representing list of ints
class List {

private:
    /// list
    std::vector<int> m_list;

public:

    /* print()
     * method printing text given as argument and list on standard output
     * @param text - text printed before list
     */
    void print(const char* text = "") const;

    /* insert()
     * metthod adding elements to the end of the list
     * @param number - element to be added
     */
    void insert(int number);

    /* operator[]
     * overloaded [] operator returning reference to the element standing on given index
     * @param index - index of element, which we want to access
     * @returnValue - reference to element
     */
    int& operator[] (int index);

    /* filter()
     * method that filters list using filter given as argument
     * @param filter - filter, functor <bool(int)>
     * @returnValue - new list that contains elements of base list which passed filters
     */
    List filter(std::function<bool(int)> filter) const;
};
