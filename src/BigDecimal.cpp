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
#include "Exceptions.hh"
#include "BigDecimal.hh"
#include <cmath>
#include <limits>
#include <iomanip>
#include <algorithm>

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
        this->precision = this->precision > 200 ? 200 : static_cast<int> (data.substr(data.find(".") + 1).length());
    this->operand = data;
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

void BigDecimal::findReplace(std::string& source, std::string const& find, std::string const& replace) const
{
    for(std::string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}

IOperand *BigDecimal::operator+(const IOperand &rhs) const {
    std::string first_operand = this->toString();
    std::string second_operand = rhs.toString();

    if (first_operand.size() < second_operand.size())
        std::swap(first_operand, second_operand);

    int j = (int) (first_operand.size() - 1);
    for (int i = (int) (second_operand.size() - 1); i >= 0; i--, j--)
        first_operand[j] += (second_operand[i] - '0');
    for (int i = (int) (first_operand.size() - 1); i > 0; i--)
        if (first_operand[i] > '9') {
            int d = first_operand[i] - '0';
            first_operand[i - 1] = (char) (((first_operand[i - 1] - '0') + d / 10) + '0');
            first_operand[i] = (char) ((d % 10) + '0');
        }
    if (first_operand[0] > '9') {
        std::string k;
        k += first_operand[0];
        first_operand[0] = (char) (((first_operand[0] - '0') % 10) + '0');
        k[0] = (char) (((k[0] - '0') / 10) + '0');
        first_operand = k + first_operand;
    }
    findReplace(first_operand, ",", ".");
    return new BigDecimal(first_operand);
}

IOperand *BigDecimal::operator-(const IOperand &rhs) const {
/*    std::ostringstream tmp;
    long double result = stold(rhs.toString()) - this->operand;

    tmp << result;*/
    return (new BigDecimal(rhs.toString()));
}

IOperand *BigDecimal::operator*(const IOperand &rhs) const {
/*    std::ostringstream tmp;
    long double result = stold(rhs.toString()) * this->operand;

    tmp << result;*/
    return (new BigDecimal(rhs.toString()));
}

IOperand *BigDecimal::operator/(const IOperand &rhs) const {
/*    std::ostringstream tmp;

    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    long double result = stold(rhs.toString()) / this->operand;
    tmp << result;*/
    return (new BigDecimal(rhs.toString()));
}

IOperand *BigDecimal::operator%(const IOperand &rhs) const {
    std::ostringstream tmp;

/*    try {
        if (this->operand == 0)
            throw new ExceptionZero;
    } catch (const ExceptionZero *e) {
        e->printErrorFinish();
    }
    long double result = fmodl(stold(rhs.toString()), this->operand);
    tmp << result;*/
    return (new BigDecimal(rhs.toString()));
}
