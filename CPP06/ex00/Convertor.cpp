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
	if (this->_cStatus == S_UNSET)
		this->_cStatus = S_IMPOSSIBLE;
	if (this->_iStatus == S_UNSET)
		this->_iStatus = S_IMPOSSIBLE;
	if (this->_fStatus == S_UNSET)
		this->_fStatus = S_IMPOSSIBLE;
	if (this->_dStatus == S_UNSET)
		this->_dStatus = S_IMPOSSIBLE;
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
	{
		return (setRetType(true, FLOAT));
	}
	if (tmp.find_first_of(POINT) != std::string::npos)
		return (setRetType(true, DOUBLE));
	return (setRetType(true, INT));
}

bool Convertor::checkSpe(char *str)
{
	std::string tmp = &str[0 + this->_offset];
	if (tmp.find_first_not_of(SPE_SYM) != std::string::npos)
		return (setRetType(false, INVALID));
	if (tmp.length() == 3 && tmp.substr(0, 3).compare("nan") == 0 && this->_offset == 0)
	{
		this->_cStatus = S_IMPOSSIBLE;
		this->_iStatus = S_IMPOSSIBLE;
		this->_fStatus = S_NAN;
		this->_dStatus = S_NAN;
		return (setRetType(true, DOUBLE));
	}
	if (tmp.length() == 4 && tmp.substr(0, 4).compare("nanf") == 0 && this->_offset == 0)
	{
		this->_cStatus = S_IMPOSSIBLE;
		this->_iStatus = S_IMPOSSIBLE;
		this->_fStatus = S_NAN;
		this->_dStatus = S_NAN;
		return (setRetType(true, FLOAT));
	}
	if (tmp.length() == 3 && tmp.substr(0, 3).compare("inf") == 0 && this->_offset == 1)
	{
		this->_cStatus = S_IMPOSSIBLE;
		this->_iStatus = S_IMPOSSIBLE;
		if (str[0] == '-')
			this->_fStatus = S_INFM;
		else
			this->_fStatus = S_INF;
		if (str[0] == '-')
			this->_dStatus = S_INFM;
		else
			this->_dStatus = S_INF;
		return (setRetType(true, DOUBLE));
	}
	if (tmp.length() == 4 && tmp.substr(0, 4).compare("inff") == 0 && this->_offset == 1)
	{
		this->_cStatus = S_IMPOSSIBLE;
		this->_iStatus = S_IMPOSSIBLE;
		if (str[0] == '-')
			this->_fStatus = S_INFM;
		else
			this->_fStatus = S_INF;
		if (str[0] == '-')
			this->_dStatus = S_INFM;
		else
			this->_dStatus = S_INF;
		return (setRetType(true, FLOAT));
	}
	return (setRetType(false, INVALID));
}

// CONVERSION
void Convertor::fillChar(char *str)
{
	(void)str;
	this->_cStatus = S_OK;
	this->_int = static_cast<int>(this->_char);
	this->_iStatus = S_OK;
	this->_float = static_cast<float>(this->_char);
	this->_fStatus = S_OK;
	this->_double = static_cast<double>(this->_char);
	this->_dStatus = S_OK;
}

void Convertor::fillInt(char *str)
{
	double dtmp;
	std::stringstream iss(&str[0 + this->_offset]);
	iss >> dtmp;
	std::cout << "teste: " << dtmp << std::endl;
	if (this->_int > CHAR_MAX || this->_int < CHAR_MIN)
		this->_cStatus = S_IMPOSSIBLE;
	else if (this->_int <= 31)
		this->_cStatus = S_NON_DISP;
	else
	{
		this->_char = static_cast<char>(this->_int);
		this->_cStatus = S_OK;
	}
	if (dtmp > static_cast<double>(INT_MAX))
		this->_iStatus = S_IMPOSSIBLE;
	else
		this->_iStatus = S_OK;
	if (dtmp > static_cast<double>(FLOAT_MAX))
		this->_fStatus = S_IMPOSSIBLE;
	else
	{
		this->_float = static_cast<float>(dtmp);
		this->_fStatus = S_OK;
	}
	this->_double = static_cast<double>(dtmp);
	this->_dStatus = S_OK;	
}

void Convertor::fillFloat(char *str)
{
	double dtmp;
	std::stringstream iss(&str[0 + this->_offset]);
	iss >> dtmp;
	if (this->_fStatus == S_NAN || this->_fStatus == S_INF || this->_fStatus == S_INFM)
		return;
	if (this->_float > static_cast<float>(CHAR_MAX) || this->_float < static_cast<float>(CHAR_MIN))
		this->_cStatus = S_IMPOSSIBLE;
	else if (this->_float <= 31)
		this->_cStatus = S_NON_DISP;
	else
	{
		this->_char = static_cast<char>(this->_float);
		this->_cStatus = S_OK;
	}
	if (this->_float > static_cast<float>(INT_MAX) || this->_float < static_cast<float>(INT_MIN))
		this->_iStatus = S_IMPOSSIBLE;
	else
	{
		this->_int = static_cast<int>(this->_float);
		this->_iStatus = S_OK;
	}
	if (dtmp > static_cast<double>(FLOAT_MAX))
	{
		this->_fStatus = S_IMPOSSIBLE;
		this->_double = static_cast<double>(dtmp);
		this->_dStatus = S_OK;
		return;
	}
	this->_double = static_cast<double>(this->_float);
	this->_dStatus = S_OK;
	this->_fStatus = S_OK;
}

void Convertor::fillDouble()
{
	if (this->_dStatus == S_NAN || this->_dStatus == S_INF || this->_dStatus == S_INFM)
		return;
	this->_dStatus = S_OK;
	if (this->_double > static_cast<double>(CHAR_MAX) || this->_double < static_cast<double>(CHAR_MIN))
		this->_cStatus = S_IMPOSSIBLE;
	else if (this->_double <= 31)
		this->_cStatus = S_NON_DISP;
	else
	{
		this->_char = static_cast<char>(this->_double);
		this->_cStatus = S_OK;
	}
	if (this->_double > static_cast<double>(INT_MAX) || this->_double < static_cast<double>(INT_MIN))
		this->_iStatus = S_IMPOSSIBLE;
	else
	{
		this->_int = static_cast<int>(this->_double);
		this->_iStatus = S_OK;
	}
	if (this->_double > static_cast<double>(FLOAT_MAX))
		this->_fStatus = S_IMPOSSIBLE;
	else if (this->_double < static_cast<double>(-FLOAT_MAX))
		this->_fStatus = S_IMPOSSIBLE;
	else
	{
		this->_float = static_cast<float>(this->_double);
		this->_fStatus = S_OK;
	}
}

void Convertor::convertValue(char *str)
{
	std::string sstr = str;
	std::istringstream stream(sstr);
	switch (this->_type)
	{
	case (CHAR):
		this->_char = str[0];
		fillChar(str);
		break;
	case (INT):
		stream >> this->_int;
		if (stream.fail())
			this->_iStatus = S_IMPOSSIBLE;
		fillInt(str);
		break;
	case (FLOAT):
		stream >> this->_float;
		if (stream.fail() && this->_fStatus != S_NAN && this->_fStatus != S_INF && this->_fStatus != S_INFM)
			this->_fStatus = S_IMPOSSIBLE;
		fillFloat(str);
		break;
	case (DOUBLE):
		stream >> this->_double;
		if (stream.fail() && this->_dStatus != S_NAN && this->_dStatus != S_INF && this->_dStatus != S_INFM)
			this->_dStatus = S_IMPOSSIBLE;
		fillDouble();
		break;
	default:
		break;
	}
}

void Convertor::storeValue(char *str)
{
	std::string tmp = str;
	if (tmp.length() == 0)
		setRetType(false, INVALID);
	if (tmp.length() == 1 && tmp.find_first_of(NUMBERS) == std::string::npos)
		setRetType(true, CHAR);
	else if (tmp.length() == 0 || !checkPrefix(str) || (!checkNumber(str) && !checkSpe(str)))
		return;
	convertValue(str);
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
	case (S_NAN):
		return ("nan");
		break;
	case (S_INF):
		return ("inf");
		break;
	case (S_INFM):
		return ("-inf");
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
		std::cout << this->_float;
	else
		std::cout << getDefineStr(this->_fStatus);
	if (this->_fStatus == S_OK || this->_fStatus == S_NAN || this->_fStatus == S_INF || this->_fStatus == S_INFM)
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	if (this->_dStatus == S_OK)
		std::cout << this->_double << std::endl;
	else
		std::cout << getDefineStr(this->_dStatus) << std::endl;
	return true;
}
