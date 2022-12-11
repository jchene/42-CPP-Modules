#include "./Convertor.hpp"

// COPLIEN
Convertor::Convertor(char *str) : _char(0), _int(0), _float(0.0f), _double(0.0)
{
	if (MSGS > 0)
		std::cout << "Convertor default c.tor called" << std::endl;
	storeValue(str);
	displayAll();
}

Convertor::Convertor(const Convertor &ref)
{
	if (MSGS > 0)
		std::cout << "Convertor copy c.tor called" << std::endl;
	(void)ref;
}

Convertor &Convertor::operator=(const Convertor &rhs)
{
	if (MSGS > 0)
		std::cout << "Convertor copy assignment o.tor called" << std::endl;
	(void)rhs;
	return (*this);
}

Convertor::~Convertor()
{
	if (MSGS > 0)
		std::cout << "Convertor d.tor called" << std::endl;
}

void Convertor::storeValue(char *str)
{
	std::stringstream ss;
	ss << str;
	ss >> this->_char;
	ss >> this->_char;
	/*this->_float = static_cast<float>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<char>(this->_double);*/
}

void Convertor::displayAll()
{
	std::cout << this->_double << std::endl;
	std::cout << this->_float << std::endl;
	std::cout << this->_int << std::endl;
	std::cout << "|" << this->_char << "|" << std::endl;
}
