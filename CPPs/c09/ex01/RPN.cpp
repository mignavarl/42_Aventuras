#include "RPN.hpp"


// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
RPN::RPN(void)
{
	//std::cout << GREEN "RPN default constructor called" NC << std::endl;
}

RPN::RPN(RPN const& other)
{
	//std::cout << GREEN "RPN copy constructor called" NC << std::endl;
	*this = other;
}

RPN::~RPN(void)
{
	//std::cout << RED "RPN destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
RPN& RPN::operator=(RPN const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

//------------------------------------------------------------------------------

void	RPN::put_stack(std::string arg)
{
	for (size_t i = arg.size() - 1; arg[i]; i--)
	{
		if (arg[i] != ' ')
		{
			this->pile.push(arg[i]);
		}
	}
}

bool	RPN::calcule(std::stack<int> *buff, char token)
{
	if (buff->size() < 2)
		return (false);
	int second = buff->top();
	buff->pop();
	int first = buff->top();
	buff->pop();
	switch (token)
	{
	case '+':
		buff->push(first + second);
		break;
	case '-':
		buff->push(first - second);
		break;
	case '*':
		buff->push(first * second);
		break;
	case '/':
		buff->push(first / second);
		break;
	default:
		break;
	}
	return (true);
}

void	RPN::reverse_polish_notation(void)
{
	std::stack<int> buff;
	std::string tok;

	for (size_t i = 0; this->pile.size() >= 1; i++)
	{
		tok = this->pile.top();
		if (!isdigit(tok[0]))
		{
			if (!calcule(&buff,tok[0]))
			{
				std::cout << RED "Error: Faltan números\n" NC;
				return ;
			}
		}
		else
			buff.push(atoi(tok.c_str()));
		this->pile.pop();
	}
	if (buff.size() == 1)
		std::cout << GREEN << buff.top() << NC << std::endl;
	else
		std::cout << RED "Error: faltan símbolos\n" NC;
}