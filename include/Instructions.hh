//
// Instructions.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Sat Jul 22 17:14:16 2017 Julien Leleu
// Last update Sat Jul 22 17:37:11 2017 Julien Leleu
//

#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <list>
#include "IOperand.hh"

class Instructions
{
public:
  Instructions() {}
  ~Instructions() {}

  std::list<IOperand *> pop_stack(std::list<IOperand*> stack);
  std::list<IOperand *> clear_stack(std::list<IOperand*> stack);
  std::list<IOperand *> dup_stack(std::list<IOperand*> stack);
  std::list<IOperand *> swap_stack(std::list<IOperand*> stack);
  std::list<IOperand *> dump_stack(std::list<IOperand*> stack);
  std::list<IOperand *> add_stack(std::list<IOperand*> stack);
  std::list<IOperand *> sub_stack(std::list<IOperand*> stack);
  std::list<IOperand *> mul_stack(std::list<IOperand*> stack);
  std::list<IOperand *> div_stack(std::list<IOperand*> stack);
  std::list<IOperand *> mod_stack(std::list<IOperand*> stack);
  std::list<IOperand *> print_stack(std::list<IOperand*> stack);
  std::list<IOperand *> exit_stack(std::list<IOperand*> stack);

  std::list<IOperand *> load_stack(std::list<IOperand*> stack, IOperand *current);
  std::list<IOperand *> store_stack(std::list<IOperand*> stack, IOperand *current);
  std::list<IOperand *> push_stack(std::list<IOperand*> stack, IOperand *current);
  std::list<IOperand *> assert_stack(std::list<IOperand*> stack, IOperand *current);
};


#endif
