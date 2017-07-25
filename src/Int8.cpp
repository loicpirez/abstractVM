//
// Int8.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 09:38:28 2017 Julien Leleu
// Last update Mon Jul 24 14:39:50 2017 Julien Leleu
//

#include <string>
#include <sstream>
#include <iostream>
#include <climits>
#include "Exceptions.hh"
#include "Int8.hh"

using namespace operand_int8;

Int8::Int8(const std::string &data) {
    int tmp = stoi(data);

    try {
        if (tmp > SCHAR_MAX)
            throw new ExceptionOverflow;
        else if (tmp < SCHAR_MIN)
            throw new ExceptionUnderflow;
    } catch (const ExceptionOverflow *e) {
        e->printErrorFinish();
    } catch (const ExceptionUnderflow *e) {
        e->printErrorFinish();
    }
    this->precision = 0;
    this->operand = static_cast<char>(tmp);
}

Int8::~Int8() {}

int Int8::getPrecision() const {
    return (this->precision);
}

std::string Int8::toString() const {
    std::ostringstream tmp;

    tmp << static_cast<int> (operand);
    return (tmp.str());
}

eOperandType Int8::getType() const {
    return (eOperandType::Int8);
}

IOperand *Int8::operator+(const IOperand &rhs) const {
    if (rhs.getType() > this->getType())
        return (rhs + *this);
    std::ostringstream tmp;
    int result = static_cast<char>(stoi(rhs.toString()) + this->operand);

    tmp << result;
    return (new Int8(tmp.str()));
}

IOperand *Int8::operator-(const IOperand &rhs) const {
    if (rhs.getType() > this->getType())
        return (rhs - *this);
    std::ostringstream tmp;
    int result = this->operand - static_cast<char> ((stoi(rhs.toString())));

    tmp << result;
    return (new Int8(tmp.str()));
}

IOperand *Int8::operator*(const IOperand &rhs) const {
    if (rhs.getType() > this->getType())
        return (rhs * *this);
    std::ostringstream tmp;
    int result = static_cast<char>(stoi(rhs.toString()) * this->operand);

    tmp << result;
    return (new Int8(tmp.str()));
}

IOperand *Int8::operator/(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if ((static_cast<int> (this->operand == 0)))
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    int result = static_cast<char>(this->operand / stoi(rhs.toString()));
    tmp << result;
    return (new Int8(tmp.str()));
}

IOperand *Int8::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if ((static_cast<int> (this->operand == 0)))
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    int result = static_cast<char>(this->operand % stoi(rhs.toString()));
    tmp << result;
    return (new Int8(tmp.str()));
}
