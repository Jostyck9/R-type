/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** ClassA.hpp
*/

#ifndef CLASSA_HHP__
#define CLASSA_HHP__

#include <string>

/**
 * @brief My classA Brief description
 * 
 */
class ClassA
{
private:
    std::string _myText;
public:
    ClassA();
    ~ClassA();

    /**
     * @brief Set the MyText object
     * 
     * @param newText 
     */
    void setMyText(const std::string &newText);

    /**
     * @brief Get the My Text object
     * 
     * @return const std::string& 
     */
    const std::string &getMyText() const;
};

ClassA::ClassA()
{
}

ClassA::~ClassA()
{
}

void ClassA::setMyText(const std::string &newText)
{
    _myText = newText;
}

const std::string &ClassA::getMyText() const
{
    return _myText;
}

#endif