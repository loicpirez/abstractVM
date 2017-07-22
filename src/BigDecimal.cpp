//
// bigdecimal.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:58:43 2017 Julien Leleu
// Last update Fri Jul 21 18:35:05 2017 Julien Leleu
//

#include <string>
#include <sstream>
#include <iostream>
#include "Exceptions.hh"
#include "BigDecimal.hh"

#define MAX_FLOAT 340282346638528859811704183484516925440.000000
#define MIN_FLOAT 0.000000

BigDecimal::BigDecimal(const std::string &data) {
    long double tmp = stold(data);

    try {
        if (tmp > MAX_FLOAT)
            throw new ExceptionOverflow;
        else if (tmp < MIN_FLOAT)
            throw new ExceptionUnderflow;
    } catch (const ExceptionOverflow *e) {
        e->printErrorFinish();
    } catch (const ExceptionUnderflow *e) {
        e->printErrorFinish();
    }
    this->operand = tmp;
}

BigDecimal::~BigDecimal() {}

std::string BigDecimal::toString() const {
    std::ostringstream tmp;

    tmp << operand;
    return (tmp.str());
}

eOperandType BigDecimal::getType() const {
    return (eOperandType::BigDecimal);
}

IOperand *BigDecimal::operator+(const IOperand &rhs) const {
    std::ostringstream tmp;
    long double result = stold(rhs.toString()) + this->operand;

    tmp << result;
    return (new BigDecimal(tmp.str()));
}

IOperand *BigDecimal::operator-(const IOperand &rhs) const {
    std::ostringstream tmp;
    long double result = stold(rhs.toString()) - this->operand;

    tmp << result;
    return (new BigDecimal(tmp.str()));
}

IOperand *BigDecimal::operator*(const IOperand &rhs) const {
    std::ostringstream tmp;
    long double result = stold(rhs.toString()) * this->operand;

    tmp << result;
    return (new BigDecimal(tmp.str()));
}

IOperand *BigDecimal::operator/(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    long double result = stold(rhs.toString()) / this->operand;
    tmp << result;
    return (new BigDecimal(tmp.str()));
}

IOperand *BigDecimal::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    long double result = stold(rhs.toString()) / this->operand;
    tmp << result;
    return (new BigDecimal(tmp.str()));
}
