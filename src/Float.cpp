//
// float.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 16:57:41 2017 Julien Leleu
// Last update Fri Jul 21 17:42:26 2017 Julien Leleu
//


#include <string>
#include <sstream>
#include <iostream>
#include "Exceptions.hh"
#include "Float.hh"

#define MAX_FLOAT 340282346638528859811704183484516925440.000000
#define MIN_FLOAT 0.000000

using namespace operand_float;

Float::Float(const std::string &data) {
    float tmp = stof(data);

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

Float::~Float() {}

std::string Float::toString() const {
    std::ostringstream tmp;

    tmp << operand;
    return (tmp.str());
}

eOperandType Float::getType() const {
    return (eOperandType::Float);
}

IOperand *Float::operator+(const IOperand &rhs) const {
    std::ostringstream tmp;
    float result = stof(rhs.toString()) + this->operand;

    tmp << result;
    return (new Float(tmp.str()));
}

IOperand *Float::operator-(const IOperand &rhs) const {
    std::ostringstream tmp;
    float result = stof(rhs.toString()) - this->operand;

    tmp << result;
    return (new Float(tmp.str()));
}

IOperand *Float::operator*(const IOperand &rhs) const {
    std::ostringstream tmp;
    float result = (float) stoi(rhs.toString()) * this->operand;

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
    float result = (float) stoi(rhs.toString()) / this->operand;
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
    float result = (float) stoi(rhs.toString()) / this->operand;
    tmp << result;
    return (new Float(tmp.str()));
}
