#include "./Convertor.hpp"

// EXCEPTIONS

// COPLIEN
Convertor::Convertor(char *str)
{
	if (MSGS > 0)
		std::cout << "Convertor default c.tor called" << std::endl;
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

const std::string &get_type(char *str)
{

}

const char &strChar(const std::string &ref)
{

}

const char &intChar(const int &ref)
{}


const int &strInt(const std::string &ref)
{}

const int &charInt(const char &ref)
{}

const int &doubleInt(const double &ref)
{}


const double &strDouble(const std::string &ref)
{}

const double &intDouble(const int &ref)
{}

const double &floatDouble(const float &ref)
{}


const float &strFloat(const std::string &ref)
{}

const float &doubleFloat(const double &ref)
{}
