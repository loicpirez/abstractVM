//
// Int8.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 09:38:28 2017 Julien Leleu
// Last update Fri Jul 21 16:14:08 2017 Julien Leleu
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
    this->operand = (char) tmp;
}

Int8::~Int8() {}

std::string Int8::toString() const {
    std::ostringstream tmp;

    tmp << (int) operand;
    return (tmp.str());
}

eOperandType Int8::getType() const {
    return (eOperandType::Int8);
}

IOperand *Int8::operator+(const IOperand &rhs) const {
    std::ostringstream tmp;
    int result = (char) stoi(rhs.toString()) + this->operand;

    tmp << result;
    return (new Int8(tmp.str()));
}

IOperand *Int8::operator-(const IOperand &rhs) const {
    std::ostringstream tmp;
    int result = (char) stoi(rhs.toString()) - this->operand;

    tmp << result;
    return (new Int8(tmp.str()));
}

IOperand *Int8::operator*(const IOperand &rhs) const {
    std::ostringstream tmp;
    int result = (char) stoi(rhs.toString()) * this->operand;

    tmp << result;
    return (new Int8(tmp.str()));
}

IOperand *Int8::operator/(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if ((int) this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    int result = (char) stoi(rhs.toString()) / this->operand;
    tmp << result;
    return (new Int8(tmp.str()));
}

IOperand *Int8::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if ((int) this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    int result = (char) stoi(rhs.toString()) % this->operand;
    tmp << result;
    return (new Int8(tmp.str()));
}
