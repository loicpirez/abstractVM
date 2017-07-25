//
// bigdecimal.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:58:43 2017 Julien Leleu
// Last update Tue Jul 25 17:24:47 2017 Julien Leleu
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

void BigDecimal::findReplace(std::string &source, std::string const &find, std::string const &replace) const {
    for (std::string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;) {
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
    std::string a = this->toString();
    std::string b = rhs.toString();
    std::string::reverse_iterator rit_1 = a.rbegin();
    std::string::reverse_iterator rit_2 = b.rbegin();
    std::string c;

    bool carry = false;
    while (rit_1 != a.rend() && rit_2 != b.rend()) {
        int a1 = *rit_1 - '0';
        int b1 = *rit_2 - '0';
        if (carry) {
            b1 += 1;
        }
        if (a1 < b1) {
            a1 += 10;
            carry = true;
        } else {
            carry = false;
        }
        c += (a1 - b1) + '0';
        rit_1++;
        rit_2++;
    }
    if (rit_1 != a.rend()) {
        do {
            int a1 = *rit_1 - '0';
            int b1 = carry ? 1 : 0;
            if (a1 < b1) {
                a1 += 10;
                carry = true;
            } else {
                carry = false;
            }
            c += (a1 - b1) + '0';
            rit_1++;
        } while (rit_1 != a.rend());
    }
    std::reverse(c.begin(), c.end());
    while (c.at(0) == '0')
      c.erase(0, 1);
    return (new BigDecimal(c));
}

IOperand *BigDecimal::operator*(const IOperand &rhs) const {
    return (new BigDecimal(rhs.toString()));
}

IOperand *BigDecimal::operator/(const IOperand &rhs) const {
    return (new BigDecimal(rhs.toString()));
}

IOperand *BigDecimal::operator%(const IOperand &rhs) const {
    return (new BigDecimal(rhs.toString()));
}
