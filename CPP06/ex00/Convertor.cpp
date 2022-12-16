#include "./Convertor.hpp"

// COPLIEN
Convertor::Convertor(char *str) : _offset(0), _type(UNSET),
								  _char(0), _cStatus(S_UNSET),
								  _int(0), _iStatus(S_UNSET),
								  _float(0.0f), _fStatus(S_UNSET),
								  _double(0.0), _dStatus(S_UNSET)
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

// USEFULL FUNCTIONS
int Convertor::countOccur(const std::string &str, const std::string &charset)
{
	int occur = 0;
	for (size_t j = 0; j < charset.length(); j++)
		for (size_t i = 0; (i = str.find(charset[j], i)) != std::string::npos; i++)
			occur++;
	return (occur);
}

bool Convertor::setRetType(bool ret, int value)
{
	this->_type = value;
	return (ret);
}

// PARSING
bool Convertor::checkPrefix(char *str)
{
	std::string tmp = str;
	if (tmp.find_first_of(SIGNS) != std::string::npos)
	{
		if (countOccur(tmp, SIGNS) > 1)
			return (setRetType(false, INVALID));
		if (tmp.find_first_of(SIGNS) != 0)
			return (setRetType(false, INVALID));
		this->_offset++;
	}
	return (true);
}

bool Convertor::checkNumber(char *str)
{
	std::string tmp = &str[0 + this->_offset];
	if (tmp.find_first_not_of(NB_SYM) != std::string::npos)
		return (setRetType(false, INVALID));
	if (tmp.find_first_of(POINT) != std::string::npos)
	{
		if (countOccur(tmp, POINT) > 1)
			return (setRetType(false, INVALID));
	}
	if (tmp.find_first_of(SUFFIXE) != std::string::npos)
	{
		if (countOccur(tmp, SUFFIXE) > 1)
			return (setRetType(false, INVALID));
		if (tmp.find_first_of(SUFFIXE) != tmp.length() - 1)
			return (setRetType(false, INVALID));
	}
	if (tmp.find_first_of(SUFFIXE) != std::string::npos)
		return (setRetType(true, FLOAT));
	if (tmp.find_first_of(POINT) != std::string::npos)
		return (setRetType(true, DOUBLE));
	return (setRetType(true, INT));
}

bool Convertor::checkInf(char *str)
{
	std::string tmp = &str[0 + this->_offset];
	if (tmp.find_first_not_of(INF) != std::string::npos)
		return (setRetType(false, INVALID));
	if (tmp.length() == 3 && tmp.substr(0, 3).compare("nan") == 0 && this->_offset == 0)
		return (setRetType(true, DOUBLE));
	if (tmp.length() == 4 && tmp.substr(0, 4).compare("nanf") == 0 && this->_offset == 0)
		return (setRetType(true, FLOAT));
	if (tmp.length() == 3 && tmp.substr(0, 3).compare("inf") == 0 && this->_offset == 1)
		return (setRetType(true, DOUBLE));
	if (tmp.length() == 4 && tmp.substr(0, 4).compare("inff") == 0 && this->_offset == 1)
		return (setRetType(true, FLOAT));
	return (setRetType(false, INVALID));
}

// CONVERSION
void fillOthers(char *str)
{

}

void Convertor::convertValue(char *str)
{
	std::string sstr = str;
	std::istringstream stream(sstr);
	switch (this->_type)
	{
	case (CHAR):
		this->_char = str[0];
		break;
	case (INT):
		stream >> this->_int;
		if (stream.fail())
			this->_iStatus = S_IMPOSSIBLE;
		break;
	case (FLOAT):
		stream >> this->_float;
		if (stream.fail())
			this->_fStatus = S_IMPOSSIBLE;
		break;
	case (DOUBLE):
		stream >> this->_double;
			if (stream.fail())
			this->_dStatus = S_IMPOSSIBLE;
		break;
	default:
		break;
	}
	fillOthers(str);
}

bool Convertor::storeValue(char *str)
{
	std::string tmp = str;
	if (tmp.length() == 0)
	{
		setRetType(false, INVALID);
		return (displayAll());
	}
	if (tmp.length() == 1 && tmp.find_first_of(NUMBERS) == std::string::npos)
	{
		setRetType(true, CHAR);
		convertValue(str);
		return (displayAll());
	}
	if (checkPrefix(str) == false)
		return (displayAll());
	if (checkNumber(str) == false)
		if (checkInf(str) == false)
			return (displayAll());
	convertValue(str);
	return (displayAll());
}

// DISPLAY
const char *Convertor::getDefineStr(int value)
{
	switch (value)
	{
	case (UNSET):
		return ("UNSET");
		break;
	case (INVALID):
		return ("INVALID");
		break;
	case (CHAR):
		return ("CHAR");
		break;
	case (INT):
		return ("INT");
		break;
	case (FLOAT):
		return ("FLOAT");
		break;
	case (DOUBLE):
		return ("DOUBLE");
		break;
	case (S_UNSET):
		return ("UNSET");
		break;
	case (S_IMPOSSIBLE):
		return ("IMPOSSIBLE");
		break;
	case (S_NON_DISP):
		return ("NON DISPLAYABLE");
		break;
	default:
		return ("DEFAULT");
		break;
	}
}

bool Convertor::displayAll()
{
	std::cout << "type: " << getDefineStr(this->_type) << std::endl
			  << "-----" << std::endl;
	std::cout << "char: ";
	if (this->_cStatus == S_OK)
		std::cout << this->_char << std::endl;
	else
		std::cout << getDefineStr(this->_cStatus) << std::endl;
	std::cout << "int: ";
	if (this->_iStatus == S_OK)
		std::cout << this->_int << std::endl;
	else
		std::cout << getDefineStr(this->_iStatus) << std::endl;
	std::cout << "float: ";
	if (this->_fStatus == S_OK)
		std::cout << this->_float << std::endl;
	else
		std::cout << getDefineStr(this->_fStatus) << std::endl;
	std::cout << "double: ";
	if (this->_dStatus == S_OK)
		std::cout << this->_double << std::endl;
	else
		std::cout << getDefineStr(this->_dStatus) << std::endl;
	return true;
}
