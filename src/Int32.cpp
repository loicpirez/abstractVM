//
// Int32.cpp for Int32 in /Users/romain/Epitech/Synthesis/abstractVM_2016
//
// Made by Romain Dick
// Login   <romain.dick@epitech.eu>
//
// Started on  Fri Jul 21 10:44:46 2017 Romain Dick
// Last update Mon Jul 24 14:44:09 2017 Julien Leleu
//

#include <string>
#include <sstream>
#include <iostream>
#include <climits>
#include "Exceptions.hh"
#include "Int32.hh"

using namespace operand_int32;

Int32::Int32(const std::string &data) {
    int tmp = stoi(data);

    try {
        if (tmp > INT_MAX)
            throw new ExceptionOverflow;
        else if (tmp < INT_MIN)
            throw new ExceptionUnderflow;
    } catch (const ExceptionOverflow *e) {
        e->printErrorFinish();
    } catch (const ExceptionUnderflow *e) {
        e->printErrorFinish();
    }
    this->precision = 0;
    this->operand = tmp;
}

Int32::~Int32() {}

int Int32::getPrecision() const {
    return (this->precision);
}

std::string Int32::toString() const {
    std::ostringstream tmp;

    tmp << operand;
    return (tmp.str());
}

eOperandType Int32::getType() const {
    return (eOperandType::Int32);
}

IOperand *Int32::operator+(const IOperand &rhs) const {
  if (rhs.getType() > this->getType())
    return (rhs + *this);
  std::ostringstream tmp;
  int result = (int) (stoi(rhs.toString()) + this->operand);

  tmp << result;
  return (new Int32(tmp.str()));
}

IOperand *Int32::operator-(const IOperand &rhs) const {
  if (rhs.getType() > this->getType())
    return (rhs - *this);
  std::ostringstream tmp;
  int result = this->operand - stoi(rhs.toString());

  tmp << result;
  return (new Int32(tmp.str()));
}

IOperand *Int32::operator*(const IOperand &rhs) const {
  if (rhs.getType() > this->getType())
    return (rhs * *this);
  std::ostringstream tmp;
  int result = (int) (stoi(rhs.toString()) * this->operand);

  tmp << result;
  return (new Int32(tmp.str()));
}

IOperand *Int32::operator/(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if ((int) this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    int result = this->operand / stoi(rhs.toString());
    tmp << result;
    return (new Int32(tmp.str()));
}

IOperand *Int32::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

    try {
        if ((int) this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    int result = this->operand % stoi(rhs.toString());
    tmp << result;
    return (new Int32(tmp.str()));
}
