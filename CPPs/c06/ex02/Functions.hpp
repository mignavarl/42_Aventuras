#ifndef _FUNCTIONS_HPP
# define _FUNCTIONS_HPP

#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <unistd.h>
#include <cstdlib>


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif