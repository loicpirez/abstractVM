//
// float.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 16:57:41 2017 Julien Leleu
// Last update Mon Jul 24 14:42:33 2017 Julien Leleu
//


#include <string>
#include <sstream>
#include <iostream>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include "Exceptions.hh"
#include "Float.hh"

using namespace operand_float;

Float::Float(const std::string &data) {
    float tmp = stof(data);

    try {
        if (tmp > FLT_MAX)
            throw new ExceptionOverflow;
        else if (tmp < -FLT_MAX)
            throw new ExceptionUnderflow;
    } catch (const ExceptionOverflow *e) {
        e->printErrorFinish();
    } catch (const ExceptionUnderflow *e) {
        e->printErrorFinish();
    }
    this->precision = 0;
    if (data.find(".") != std::string::npos)
        this->precision = this->precision > 3 ? 3 : (int) (data.substr(data.find(".") + 1).length());
    this->operand = tmp;
}

Float::~Float() {}

int Float::getPrecision() const {
    return (this->precision);
}

std::string Float::toString() const {
    std::ostringstream tmp;
    tmp << std::fixed << std::setprecision(precision) << operand;
    return (tmp.str());
}

eOperandType Float::getType() const {
    return (eOperandType::Float);
}

IOperand *Float::operator+(const IOperand &rhs) const {
    std::ostringstream tmp;
    rhs.toString();
    float result = stof(rhs.toString()) + this->operand;

    tmp << result;
    return (new Float(tmp.str()));
}

IOperand *Float::operator-(const IOperand &rhs) const {
    std::ostringstream tmp;
    float result = this->operand - stof(rhs.toString());

    tmp << result;
    return (new Float(tmp.str()));
}

IOperand *Float::operator*(const IOperand &rhs) const {
    std::ostringstream tmp;
    float result = stof(rhs.toString()) * this->operand;

    tmp << result;
    return (new Float(tmp.str()));
}

IOperand *Float::operator/(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    float result = this->operand / stof(rhs.toString());
    tmp << result;
    return (new Float(tmp.str()));
}

IOperand *Float::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    float result = fmodf(this->operand, stof(rhs.toString()));
    tmp << result;
    return (new Float(tmp.str()));
}
