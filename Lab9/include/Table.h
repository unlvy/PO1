#pragma once

#include "Data.h"

/**
 * function comparing expenses in given column
 * @param - const Data&
 * @param - const Data&
 * @param - int
 * @return - bool
 */
bool sort_by_column(const Data& d1, const Data& d2, int column);

/**
 * class represneting table of expenses
 */
class Table {

private:
    std::vector<Data> m_days;       /** days container */
public:

    /**
     * method adding days to the table
     * @param - const Data&
     */
    void operator+= (const Data& data);

    /**
     * method printing table on std out
     */
    void print() const;

    /**
     * method sorting table by column
     * @param - int
     * @return - Table&
     */
    Table& sort(int column);

    /**
     * method sorting table with given sorting function
     * @param - std::function<bool(const Data& d1, const Data& d2)>
     * @return - Table&
     */
    Table& sortBy(std::function<bool(const Data& d1, const Data& d2)> sorter);
};
