//
// bigdecimal.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:58:43 2017 Julien Leleu
// Last update Sun Jul 23 21:53:20 2017 Loïc Pirez
//

#include <string>
#include <sstream>
#include <iostream>
#include <cfloat>
#include "Exceptions.hh"
#include "BigDecimal.hh"
#include <cmath>
#include <limits>
#include <iomanip>

BigDecimal::BigDecimal(const std::string &data) {
    long double tmp = stold(data);

    try {
        if (tmp > std::numeric_limits<long double>::max())
            throw new ExceptionOverflow;
        else if (tmp < std::numeric_limits<long double>::min())
            throw new ExceptionUnderflow;
    } catch (const ExceptionOverflow *e) {
        e->printErrorFinish();
    } catch (const ExceptionUnderflow *e) {
        e->printErrorFinish();
    }
    if (data.find(".") != std::string::npos)
        this->precision = this->precision > 200 ? 200 : (int) (data.substr(data.find(".") + 1).length());
    this->operand = tmp;
}

BigDecimal::~BigDecimal() {}

std::string BigDecimal::toString() const {
    std::ostringstream tmp;
    tmp << std::fixed << std::setprecision(precision) << operand;
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

// 1.23123123120319230129310239103812931293812398123

IOperand *BigDecimal::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    long double result = fmodl(stold(rhs.toString()), this->operand);
    tmp << result;
    return (new BigDecimal(tmp.str()));
}
