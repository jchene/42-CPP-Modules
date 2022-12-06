#include "./Convertor.hpp"

// EXCEPTIONS

// COPLIEN
Convertor::Convertor(char *str) : _type(0), _char(0), _int(0), _float(0.0f), _double(0.0)
{
	if (MSGS > 0)
		std::cout << "Convertor default c.tor called" << std::endl;
	this->_type = convertFrom(str);
	if ()
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

void Convertor::convertTo(char *str)
{
	std::stringstream ss(static_cast<std::string>(str));
	switch (checkType(str))
	{
	case (CNV_C):
		this->_char = static_cast<char>(str[0]);
		fillFromChar();
		break;
	case (CNV_I):
		this->_int = static_cast<int>();
		break;
	case (CNV_F):
		/* code */
		break;
	case (CNV_D):
		/* code */
		break;
	case (CNV_INV):
		/* code */
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

void Convertor::displayAll()
{
}
