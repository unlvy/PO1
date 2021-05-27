#pragma once

/**
 * @file
 * contains template of associative array
 */

#include <vector>
#include "AuxillaryFunctions.h"

/** template of associative array class, T1 - keys, T2 - values */
template <typename T1, typename T2>
class Assoc {

private:

    /** keys container */
    std::vector<T1> m_keys;
    /** values container */
    std::vector<T2> m_values;

    /** 
     * method returning index of given key if it exists
     * or -1 otherwise
     * @param T1 - key
     * @return int - index
     */
    int getIndex(T1 key) const;

public:

    /**
     * adds new pair key-value if it doesn`t exist, or changes
     * value held at given key if it exists
     * @param T1 - key
     * @param T2 - value
     */
    void insert(T1 key, T2 value);

    /**
     * returns reference to value held at given key
     * if key doesn't exists it creates pair key - calue
     * using default value constructor and returns reference to value
     * @param T1 - key
     * @return T2& - value
     */
    T2& operator[](T1 key);

    /**
     * returns copy of value held at given key
     * key must exist
     * @param T1 - key
     * @param T2 - value
     */
    T2 operator[](T1 key) const;

    /**
     * prints array on standard output, also
     * printing text given as argument before each pair of key and value
     * @param std::string - tekst
     */
    void print(std::string text) const;

    /**
     * checks if given key exists in array
     * @param T1 - key
     * @return bool
     */
    bool contains(T1 key) const;

};

/* -------------------------------------------------- */

template <typename T1, typename T2>
int Assoc<T1, T2>::getIndex(T1 searchedKey) const {
    int index = 0;
    for (const auto& key : m_keys) {
        if (key == searchedKey) {
            return index;
        }
        index++;
    }
    return -1;
}

template <typename T1, typename T2>
void Assoc<T1, T2>::insert(T1 key, T2 value) {
    int index = getIndex(key);
    if (index != -1) {
        m_values[index] = value;
    } else {
        m_keys.push_back(key);
        m_values.push_back(value);
    }
}

template <typename T1, typename T2>
T2& Assoc<T1, T2>::operator[](T1 key) {
    int index = getIndex(key);
    if (index != -1) {
        return m_values[getIndex(key)];
    } else {
        m_keys.push_back(key);
        m_values.push_back(T2());
        return m_values[m_values.size() - 1];
    }
}

template <typename T1, typename T2>
T2 Assoc<T1, T2>::operator[](T1 key) const {
    return m_values[getIndex(key)];
}

template <typename T1, typename T2>
void Assoc<T1, T2>::print(std::string text) const {
    for (unsigned i = 0; i < m_keys.size(); i++) {
        std::cout << " --- " << text << " --- klucz: " << m_keys[i] 
                  << " wartosc: " << m_values[i] << std::endl;
    }
}

template <typename T1, typename T2>
bool Assoc<T1, T2>::contains(T1 key) const {
    if (getIndex(key) != -1) {
        return true;
    } else {
        return false;
    }
}
