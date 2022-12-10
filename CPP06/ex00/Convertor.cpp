#include "./Convertor.hpp"

// EXCEPTIONS

// COPLIEN
Convertor::Convertor(char *str) : _type(checkType(str)), _char(0), _int(0), _float(0.0f), _double(0.0)
{
	if (MSGS > 0)
		std::cout << "Convertor default c.tor called" << std::endl;
	storeValue(str);
}

Convertor::Convertor(const Convertor &ref)
{
	if (MSGS > 0)
		std::cout << "Convertor copy c.tor called" << std::endl;
}

Convertor &Convertor::operator=(const Convertor &rhs)
{
	if (MSGS > 0)
		std::cout << "Convertor copy assignment o.tor called" << std::endl;
	return (*this);
}

Convertor::~Convertor()
{
	if (MSGS > 0)
		std::cout << "Convertor d.tor called" << std::endl;
}

int Convertor::checkType(char *str)
{
}

void Convertor::storeValue(char *str)
{
	std::stringstream ss;
	ss << str;
	switch (checkType(str))
	{
	case (CNV_C):
		this->_char = str[0];
		fillFromChar();
		break;
	case (CNV_I):
		ss >> this->_int;
		fillFromInt();
		break;
	case (CNV_F):
		ss >> this->_int;
		fillFromFloat();
		break;
	case (CNV_D):
		ss >> this->_double;
		fillFromDouble();
		break;
	case (CNV_INV):
		fillInvalid();
		break;
	default:
		break;
	}
}

void Convertor::fillFromChar()
{
}

void Convertor::fillFromInt()
{
}

void Convertor::fillFromFloat()
{
}

void Convertor::fillFromDouble()
{
}

void Convertor::fillInvalid()
{

}

void Convertor::displayAll()
{
}
