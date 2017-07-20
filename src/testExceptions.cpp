#include <iostream>
#include "Exceptions.hh"

int main(int ac, char **av)
{
  std::cout << "First" << std::endl;
  try
  {
    if (ac != 2)
      throw new ExceptionSyntax;
  }
  catch (const ExceptionSyntax *e)
  {
    std::cout << e->what() << std::endl;
    exit(84);
  }
  std::cout << "End" << std::endl;
}
