#pragma once

#include <cmath>
#include <iostream>
#include <string>
#include <exception>

/** base class of simple math functions hierarchy */
class Function {

protected:

    /** function type */
    std::string m_type;

public:

    /** 
     * constructor, sets m_type field
     * @param - type
     */
    explicit Function(std::string type = "undefined");

    /** default destructor */
    virtual ~Function() = default;

    /**
     * returns type field
     * @return type
     */
    virtual std::string getType() const;

    /**
     * returns function value for given argument
     * migth throw exception connected with invalid argument
     * @param argument
     * @return function value
     * @throws std::invalid_argument
     */
    virtual double calculate(double x) const = 0;
};

/** class representing arcsin function */
class Asin : public Function {

public:

    /** 
     * kconstructor, sets m_type with arcsin
     */
    Asin();

    double calculate(double x) const override;

};

/** class representing log10 function */
class Log10 : public Function {

public:

    /** 
     * constructor, sets m_type with log10
     */
    Log10();

    double calculate(double x) const override;

};

/** class representing division function (numerator is constant) */
class DivideBy : public Function {

private:

    /** numerator */
    double m_numerator;

public:

    /** 
     * constructor, sets m_type with DivideBy
     * and m_numerator based on given argument
     * @param numerator
     */
    explicit DivideBy(double numerator);

    double calculate(double x) const override;

};
