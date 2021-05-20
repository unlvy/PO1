#pragma once

/**
 * class that is base of wrappers hierarchy
 */
class Wrapper {
    public:
    /** default destructor */
    virtual ~Wrapper() = default;
};

/** 
 * template of class that is able to wrap any type
 */
template<typename T>
class ValueWrapper : public Wrapper {
private:
    /** field containing value */
    T m_value;
public:
    /** 
     * one-argument constructor
     * @param T
     */
    explicit ValueWrapper(T value);

    /**
     * metohod returning wrapped value
     * @return T
     */
    T get();

    /**
     * method setting stores value
     * @param T
     */
    void set(T value);
};

/* ------------------------ */

template<typename T>
ValueWrapper<T>::ValueWrapper(T value) : m_value(value) {}

template<typename T>
T ValueWrapper<T>::get() { return m_value; }

template<typename T>
void ValueWrapper<T>::set(T value) { m_value = value; }
