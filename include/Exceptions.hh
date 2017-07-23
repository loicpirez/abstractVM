//
// Exceptions.hh for VM in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Thu Jul 20 15:34:44 2017 Julien Leleu
// Last update Sun Jul 23 21:50:24 2017 Loïc Pirez
//

#ifndef EXCEPTIONS_HH
# define EXCEPTIONS_HH

#include <exception>
#include <string>

class AbstractVM_Exception : public std::exception {
public:
    virtual const char *what() const throw();

    void printErrorFinish() const;

protected:
    AbstractVM_Exception(const char *) throw();


    virtual ~AbstractVM_Exception() throw();

private:
    const char *str;
};

class ExceptionFile : public AbstractVM_Exception {
public:
    ExceptionFile() throw();

    virtual ~ExceptionFile() throw();
};

class ExceptionNotEnoughNumber : public AbstractVM_Exception {
public:
    ExceptionNotEnoughNumber() throw();

    virtual ~ExceptionNotEnoughNumber() throw();
};

class ExceptionFailedAssert : public AbstractVM_Exception {
public:
    ExceptionFailedAssert() throw();

    virtual ~ExceptionFailedAssert() throw();
};

class ExceptionPopEmptyStack : public AbstractVM_Exception {
public:
    ExceptionPopEmptyStack() throw();

    virtual ~ExceptionPopEmptyStack() throw();
};

class ExceptionDumpEmptyStack : public AbstractVM_Exception {
public:
    ExceptionDumpEmptyStack() throw();

    virtual ~ExceptionDumpEmptyStack() throw();
};

class ExceptionNoExit : public AbstractVM_Exception {
public:
    ExceptionNoExit() throw();

    virtual ~ExceptionNoExit() throw();
};


class ExceptionSyntax : public AbstractVM_Exception {
public:
    ExceptionSyntax() throw();

    virtual ~ExceptionSyntax() throw();
};

class ExceptionOverflow : public AbstractVM_Exception {
public:
    ExceptionOverflow() throw();

    virtual ~ExceptionOverflow() throw();
};

class ExceptionUnderflow : public AbstractVM_Exception {
public:
    ExceptionUnderflow() throw();

    virtual ~ExceptionUnderflow() throw();
};

class ExceptionStack : public AbstractVM_Exception {
public:
    ExceptionStack() throw();

    virtual ~ExceptionStack() throw();
};

class ExceptionZero : public AbstractVM_Exception {
public:
    ExceptionZero() throw();

    virtual ~ExceptionZero() throw();
};

class ExceptionOperand : public AbstractVM_Exception {
public:
    ExceptionOperand() throw();

    virtual ~ExceptionOperand() throw();
};

#endif        /* !EXCEPTIONS_HH_ */
