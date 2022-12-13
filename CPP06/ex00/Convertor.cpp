#include "./Convertor.hpp"

// COPLIEN
Convertor::Convertor(char *str) : _char(0), _int(0), _float(0.0f), _double(0.0)
{
	if (MSGS > 0)
		std::cout << "Convertor default c.tor called" << std::endl;
	storeValue(str);
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

int Convertor::checkType(const std::string &ref)
{
	if (ref.length() < 2 && ref.find_first_not_of(NUMBERS))
		return (0);
	return (INVALID);
}

int Convertor::countOccur(const std::string &str, const std::string &charset)
{
	int occur = 0;
	for (size_t j = 0; j < charset.length(); j++){
		for (size_t i = 0; (i = str.find(charset[j], i)) != std::string::npos; i++){
			occur++;
		}
	}
	return (occur);
}

bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

void Convertor::storeValue(char *str)
{
	std::istringstream iss(str);
	iss >> this->_float;
	if (iss.fail())
		std::cout << "Fail" << std::endl;
	if (!iss.eof())
		std::cout << "Not eof" << std::endl;
	/*std::string string = str;
	if (string.find_first_not_of(ALL_SYM) != std::string::npos)
		//INVALID BAD SYMBOLS
	if (countOccur(string, SIGNS) > 1 || string.find_first_of(SIGNS) > 0)
		//INVALID TOO MANY SIGNS OR SIGN NOT AT START
	if (countOccur(string, POINT) > 1)
		//INVALID TOO
	if (string.find_first_of(NOT_INT_SYM) != std::string::npos)
	*/
	
	
	
	displayAll();
	
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
