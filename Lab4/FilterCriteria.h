#pragma once

#include <iostream>
#include <vector>
#include <functional>

/// class representing container of functors
class FilterCriteria {

private:

    /// vector of filters (functors <bool(int)>) 
    std::vector<std::function<bool(int)>> m_filters;

public:

    /* add()
     * method adding filter to the end of the container
     * @param filter - filter to add
     */
    void add(std::function<bool(int)> filter);

    /* size()
     * method returning size of container (number of filters)
     * @returnValue - size of container
     */
    int size() const;

    /* get()
     * method returning functor standing on given index
     * @param index - index
     * @returnValue - functor
     */
    std::function<bool(int)> get(int index);
};
