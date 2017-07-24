//
// double.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:44:40 2017 Julien Leleu
// Last update Mon Jul 24 14:43:24 2017 Julien Leleu
//

#include <string>
#include <sstream>
#include <iostream>
#include <cfloat>
#include "Exceptions.hh"
#include "Double.hh"
#include <cmath>
#include <iomanip>

using namespace operand_double;

Double::Double(const std::string &data) {
    double tmp = stod(data);

    try {
        if (tmp > DBL_MAX)
            throw new ExceptionOverflow;
        else if (tmp < -DBL_MAX)
            throw new ExceptionUnderflow;
    } catch (const ExceptionOverflow *e) {
        e->printErrorFinish();
    } catch (const ExceptionUnderflow *e) {
        e->printErrorFinish();
    }
    if (data.find(".") != std::string::npos)
        this->precision = this->precision > 7 ? 7 : (int) (data.substr(data.find(".") + 1).length());
    this->operand = tmp;
}

Double::~Double() {}

int Double::getPrecision() const {
    return (this->precision);
}

std::string Double::toString() const {
    std::stringstream tmp;
    tmp << std::fixed << std::setprecision(precision) << operand;
    return (tmp.str());
}

eOperandType Double::getType() const {
    return (eOperandType::Double);
}

IOperand *Double::operator+(const IOperand &rhs) const {
    std::ostringstream tmp;
    double result = stod(rhs.toString()) + this->operand;

    tmp << result;
    return (new Double(tmp.str()));
}

IOperand *Double::operator-(const IOperand &rhs) const {
    std::ostringstream tmp;
    double result = this->operand - stod(rhs.toString());

    tmp << result;
    return (new Double(tmp.str()));
}

IOperand *Double::operator*(const IOperand &rhs) const {
    std::ostringstream tmp;
    double result = stod(rhs.toString()) * this->operand;

    tmp << result;
    return (new Double(tmp.str()));
}

IOperand *Double::operator/(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    double result = this->operand / stod(rhs.toString());
    tmp << result;
    return (new Double(tmp.str()));
}

IOperand *Double::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    double result = fmod(this->operand, stof(rhs.toString()));
    tmp << result;
    return (new Double(tmp.str()));
}
