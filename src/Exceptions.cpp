//
// Exceptions.cpp for VM in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Thu Jul 20 15:32:32 2017 Julien Leleu
// Last update Sun Jul 23 21:53:16 2017 Loïc Pirez
//

//Abort: Assert has failed
//Abort:

#include <iostream>
#include "Exceptions.hh"

AbstractVM_Exception::AbstractVM_Exception(const char *str) throw()
        : str(str) {}

AbstractVM_Exception::~AbstractVM_Exception() throw() {}

const char *AbstractVM_Exception::what() const throw() {
    return (this->str);
}

void AbstractVM_Exception::printErrorFinish() const {
    std::cerr << this->what() << std::endl;
    exit(84);
}

ExceptionLoadNotFound::ExceptionLoadNotFound() throw()
        : AbstractVM_Exception("Abort: Load on non existant value") {}

ExceptionStoreNotFound::ExceptionStoreNotFound() throw()
        : AbstractVM_Exception("Abort: Store on non existant value") {}

ExceptionStoreNotFound::~ExceptionStoreNotFound() throw() {}

ExceptionLoadNotFound::~ExceptionLoadNotFound() throw() {}

ExceptionFailedAssert::ExceptionFailedAssert() throw()
        : AbstractVM_Exception("Abort: Assert has failed") {}

ExceptionFailedAssert::~ExceptionFailedAssert() throw() {}

ExceptionNotEnoughNumber::ExceptionNotEnoughNumber() throw()
        : AbstractVM_Exception("Abort: Less than two value to calc") {}

ExceptionNotEnoughNumber::~ExceptionNotEnoughNumber() throw() {}

ExceptionPopEmptyStack::ExceptionPopEmptyStack() throw()
        : AbstractVM_Exception("Abort: Pop on empty stack") {}

ExceptionPopEmptyStack::~ExceptionPopEmptyStack() throw() {}


ExceptionDumpEmptyStack::ExceptionDumpEmptyStack() throw()
        : AbstractVM_Exception("Abort: Dump on empty stack") {}

ExceptionDumpEmptyStack::~ExceptionDumpEmptyStack() throw() {}


ExceptionNoExit::ExceptionNoExit() throw()
        : AbstractVM_Exception("Abort: No exit in given file") {}

ExceptionNoExit::~ExceptionNoExit() throw() {}


ExceptionSyntax::ExceptionSyntax() throw()
        : AbstractVM_Exception("Abort: Syntax Error") {}

ExceptionSyntax::~ExceptionSyntax() throw() {}

ExceptionOverflow::ExceptionOverflow() throw()
        : AbstractVM_Exception("Abort: Overflow") {}

ExceptionOverflow::~ExceptionOverflow() throw() {}

ExceptionUnderflow::ExceptionUnderflow() throw()
        : AbstractVM_Exception("Abort: Underflow") {}

ExceptionUnderflow::~ExceptionUnderflow() throw() {}

ExceptionStack::ExceptionStack() throw()
        : AbstractVM_Exception("Abort: Error during stack operation") {}

ExceptionStack::~ExceptionStack() throw() {}

ExceptionZero::ExceptionZero() throw()
        : AbstractVM_Exception("Abort: Division or modulo by 0") {}

ExceptionZero::~ExceptionZero() throw() {}

ExceptionFile::ExceptionFile() throw()
        : AbstractVM_Exception("Abort: can't read file") {}

ExceptionFile::~ExceptionFile() throw() {}

ExceptionOperand::ExceptionOperand() throw()
        : AbstractVM_Exception("Abort: Error with an Operand") {}

ExceptionOperand::~ExceptionOperand() throw() {}

