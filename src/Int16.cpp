//
// Int16.cpp for Int16 in /Users/romain/Epitech/Synthesis/abstractVM_2016
//
// Made by Romain Dick
// Login   <romain.dick@epitech.eu>
//
// Started on  Fri Jul 21 10:44:38 2017 Romain Dick
// Last update Mon Jul 24 14:39:24 2017 Julien Leleu
//

#include <string>
#include <sstream>
#include <iostream>
#include <climits>
#include "Exceptions.hh"
#include "Int16.hh"

using namespace operand_int16;

Int16::Int16(const std::string &data) {
    int tmp = stoi(data);

    try {
        if (tmp > SHRT_MAX)
            throw new ExceptionOverflow;
        else if (tmp < SHRT_MIN)
            throw new ExceptionUnderflow;
    } catch (const ExceptionOverflow *e) {
        e->printErrorFinish();
    } catch (const ExceptionUnderflow *e) {
        e->printErrorFinish();
    }
    this->precision = 0;
    this->operand = static_cast<short>(tmp);
}

Int16::~Int16() {}

int Int16::getPrecision() const {
    return (this->precision);
}

std::string Int16::toString() const {
    std::ostringstream tmp;

    tmp << static_cast<int> (operand);
    return (tmp.str());
}

eOperandType Int16::getType() const {
    return (eOperandType::Int16);
}

IOperand *Int16::operator+(const IOperand &rhs) const {
    if (rhs.getType() > this->getType())
        return (rhs + *this);
    std::ostringstream tmp;
    int result = static_cast<short>(stoi(rhs.toString()) + this->operand);

    tmp << result;
    return (new Int16(tmp.str()));
}

IOperand *Int16::operator-(const IOperand &rhs) const {
    if (rhs.getType() > this->getType())
        return (rhs - *this);
    std::ostringstream tmp;
    int result = this->operand - static_cast<short>(stoi(rhs.toString()));

    tmp << result;
    return (new Int16(tmp.str()));
}

IOperand *Int16::operator*(const IOperand &rhs) const {
    if (rhs.getType() > this->getType())
        return (rhs * *this);
    std::ostringstream tmp;
    int result = static_cast<short>(stoi(rhs.toString()) * this->operand);

    tmp << result;
    return (new Int16(tmp.str()));
}

IOperand *Int16::operator/(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (static_cast<int> (this->operand == 0))
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    int result = static_cast<short>(this->operand / stoi(rhs.toString()));
    tmp << result;
    return (new Int16(tmp.str()));
}

IOperand *Int16::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (static_cast<int> (this->operand == 0))
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    int result = static_cast<short>(this->operand % stoi(rhs.toString()));
    tmp << result;
    return (new Int16(tmp.str()));
}
