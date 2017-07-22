//
// Int32.hh for Int32 in /Users/romain/Epitech/Synthesis/abstractVM_2016
//
// Made by Romain Dick
// Login   <romain.dick@epitech.eu>
//
// Started on  Fri Jul 21 10:45:14 2017 Romain Dick
// Last update Fri Jul 21 19:13:03 2017 Julien Leleu
//

#ifndef        INT32_HH_
# define    INT32_HH_

# include "IOperand.hh"

namespace operand_int32 {
    class Int32 : public IOperand {
    public:
        Int32(const std::string &);

        ~Int32();

        std::string toString() const;

        eOperandType getType() const;

        IOperand *operator+(const IOperand &rhs) const;

        IOperand *operator-(const IOperand &rhs) const;

        IOperand *operator*(const IOperand &rhs) const;

        IOperand *operator/(const IOperand &rhs) const;

        IOperand *operator%(const IOperand &rhs) const;

    protected:
        long long operand;
    };
}

#endif        /* !INT32_HH_ */
