//
// double.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:44:40 2017 Julien Leleu
// Last update Fri Jul 21 18:37:27 2017 Julien Leleu
//

#include <string>
#include <sstream>
#include <iostream>
#include <cfloat>
#include "Exceptions.hh"
#include "Double.hh"
#include <cmath>

using namespace operand_double;

Double::Double(const std::string &data) {
    double tmp = stof(data);

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
    this->operand = tmp;
}

Double::~Double() {}

std::string Double::toString() const {
    std::ostringstream tmp;

    tmp << operand;
    return (tmp.str());
}

eOperandType Double::getType() const {
    return (eOperandType::Double);
}

IOperand *Double::operator+(const IOperand &rhs) const {
    std::ostringstream tmp;
    double result = (double) stof(rhs.toString()) + this->operand;

    tmp << result;
    return (new Double(tmp.str()));
}

IOperand *Double::operator-(const IOperand &rhs) const {
    std::ostringstream tmp;
    double result = (double) stof(rhs.toString()) - this->operand;

    tmp << result;
    return (new Double(tmp.str()));
}

IOperand *Double::operator*(const IOperand &rhs) const {
    std::ostringstream tmp;
    double result = (double) stof(rhs.toString()) * this->operand;

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
    double result = (double) stof(rhs.toString()) / this->operand;
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
    double result = fmod(stof(rhs.toString()), this->operand);
    tmp << result;
    return (new Double(tmp.str()));
}
