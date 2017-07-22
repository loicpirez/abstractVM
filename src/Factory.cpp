//
// Factory.cpp for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Fri Jul 21 20:38:49 2017 Loïc Pirez
// Last update Fri Jul 21 20:38:49 2017 Loïc Pirez
//

#include <Int8.hh>
#include <Double.hh>
#include <Int16.hh>
#include <Int32.hh>
#include <Float.hh>
#include <BigDecimal.hh>
#include <functional>
#include "Factory.hpp"

using namespace operand_double;
using namespace operand_int8;
using namespace operand_int16;
using namespace operand_int32;
using namespace operand_float;

IOperand *Factory::createInt8(std::string const &value) const {
    return (new class operand_int8::Int8(value));
}

IOperand *Factory::createInt16(std::string const &value) const {
    return (new class operand_int16::Int16(value));
}

IOperand *Factory::createInt32(std::string const &value) const {
    return (new class operand_int32::Int32(value));
}

IOperand *Factory::createFloat(std::string const &value) const {
    return (new class operand_float::Float(value));
}

IOperand *Factory::createDouble(std::string const &value) const {
    return (new class operand_double::Double(value));
}

IOperand *Factory::createBigDecimal(std::string const &value) const {
    return (new class BigDecimal(value));
}

std::map<eOperandType, std::function<IOperand *(std::string const &)>> Factory::createFunctionPointer() {
    return {
            {eOperandType::Int8,       std::bind(&Factory::createInt8, this, std::placeholders::_1)},
            {eOperandType::Int16,      std::bind(&Factory::createInt16, this, std::placeholders::_1)},
            {eOperandType::Int32,      std::bind(&Factory::createInt32, this, std::placeholders::_1)},
            {eOperandType::Float,      std::bind(&Factory::createFloat, this, std::placeholders::_1)},
            {eOperandType::Double,     std::bind(&Factory::createDouble, this, std::placeholders::_1)},
            {eOperandType::BigDecimal, std::bind(&Factory::createBigDecimal, this, std::placeholders::_1)}
    };
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value) {
    Factory *factory = new Factory;

    std::map<eOperandType, std::function<IOperand *(std::string const &)>> map = factory->createFunctionPointer();
    return (map.at(type)(value));
}
