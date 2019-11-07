/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ClassA.hpp
*/

#ifndef CLASSB_HHP__
#define CLASSB_HHP__

#include "ClassA.hpp"

/**
 * @brief My ClassB debrief
 * 
 */
class ClassB : public ClassA
{
private:
    int _myValue;
public:
    ClassB();
    ~ClassB();

    /**
     * @brief Set the My Value object
     * 
     * @param newValue 
     */
    void setMyValue(int newValue);

    /**
     * @brief Get the My Value object
     * 
     * @return const int 
     */
    const int getMyValue() const;
};

ClassB::ClassB()
{
}

ClassB::~ClassB()
{
}

void ClassB::setMyValue(int newValue)
{
    _myValue = newValue;
}

const int ClassB::getMyValue() const
{
    return _myValue;
}

#endif