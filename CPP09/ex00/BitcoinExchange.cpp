#include "BitcoinExchange.hpp"

// UTILS

bool isContained(uShort *tab, size_t size, uShort value)
{
	for (size_t i = 0; i < size; i++)
		if (tab[i] == value)
			return true;
	return false;
}

// DATE CLASS

Date::Date(void) : _year(1), _month(1), _day(1) {}

Date::Date(short Y, uShort m, uShort d) {
	if (Y == 0 || m == 0 || d == 0)
		std::cout << "Wrong input in numeric constructor corrected" << std::endl;
	this->_year = (Y == 0 ? 1 : Y);
	this->_month = (m == 0 ? 1 : m);
	this->_day = (d == 0 ? 1 : d);
}

Date::Date(std::string dateStr)
{
	std::istringstream lineStream(dateStr);
	std::string word;
	
	std::getline(lineStream, word, '-');
	std::istringstream yStream(word);
	yStream >> this->_year;
	std::getline(lineStream, word, '-');
	std::istringstream mStream(word);
	mStream >> this->_month;
	std::getline(lineStream, word, '-');
	std::istringstream dStream(word);
	dStream >> this->_day;
	if (this->_year == 0 || this->_month == 0 || this->_day == 0)
		std::cout << "Wrong input in string constructor corrected" << std::endl;
	this->_year = (this->_year == 0 ? 1 : this->_year);
	this->_month = (this->_month == 0 ? 1 : this->_month);
	this->_day = (this->_day == 0 ? 1 : this->_day);
}

Date::Date(const Date &ref) { *this = ref; }

Date &Date::operator=(const Date &rhs)
{
	this->_year = rhs.getYear();
	this->_month = rhs.getMonth();
	this->_day = rhs.getDay();
	return (*this);
}

Date &Date::operator=(std::string str)
{
	std::istringstream lineStream(str);
	std::string word;
	
	std::getline(lineStream, word, '-');
	std::istringstream yStream(word);
	yStream >> this->_year;
	std::getline(lineStream, word, '-');
	std::istringstream mStream(word);
	mStream >> this->_month;
	std::getline(lineStream, word, '-');
	std::istringstream dStream(word);
	dStream >> this->_day;
	return (*this);
}

Date::~Date() {}

uShort Date::getMonthLimit(uShort month, short year)
{
	uShort oddMonths[7] = {1, 3, 5, 7, 8, 10, 12};
	uShort evenMonths[4] = {4, 6, 9, 11};
	uShort monthLimit = 0;

	if (isContained(oddMonths, 7, month))
		monthLimit = 31;
	else if (isContained(evenMonths, 4, month))
		monthLimit = 30;
	else if (month == 2)
		monthLimit = (year % 4 ? 28 : 29);
	return (monthLimit);
}

short Date::getYear() const { return (this->_year); }

uShort Date::getMonth() const { return (this->_month); }

uShort Date::getDay() const { return (this->_day); }

Date &Date::operator+=(unsigned short val)
{
	for (int i = 0; i < val; i++)
	{
		if (this->_day + 1 > getMonthLimit(this->_month, this->_year))
		{
			this->_day = 1;
			this->_month++;
			if (this->_month > 12)
			{
				this->_month = 1;
				this->_year++;
				if (this->_year == 0)
					this->_year = 1;
			}
		}
		else
			this->_day++;
	}
	return (*this);
}

Date &Date::operator-=(unsigned short val)
{
	for (int i = 0; i < val; i++)
	{
		if (this->_day == 1)
		{
			if (this->_month == 1)
			{
				this->_month = 12;
				this->_year--;
				if (this->_year == 0)
					this->_year = -1;
			}
			this->_day = getMonthLimit(this->_month, this->_year);
		}
		else
			this->_day--;
	}
	return (*this);
}

std::string Date::str()
{
	std::stringstream stream;
	std::stringstream sizeStream;

	sizeStream << this->_year;
	for (size_t i = 4; i > sizeStream.str().size() ; i-- )
		stream << "0";
	stream << this->_year;
	stream << "-";

	if (this->_month < 10)
		stream << "0";
	stream << this->_month;
	stream << "-";

	if (this->_day < 10)
		stream << "0";
	stream << this->_day;

	return (stream.str());
}

// ERROR HANDLING

int exitPrint(const char *msg, int ret)
{
	std::cout << msg << std::endl;
	return (ret);
}

int errorHandler(int code, dataStruct_t &data)
{
	switch (code)
	{
	case SUCCESS:
		data.database.close();
		return (SUCCESS);
	case ERR_NARG:
		return (exitPrint("Error: Bad number of arguments", EXIT_ERROR));
		break;
	case ERR_OPDB:
		return (exitPrint("Error: Couldn't open csv database", EXIT_ERROR));
		break;
	case ERR_OPIN:
		data.database.close();
		return (exitPrint("Error: Couldn't open input database", EXIT_ERROR));
	case ERR_PARS:
		data.database.close();
		return (exitPrint("Error: Incorrect database", EXIT_ERROR));
	case ERR_DATF:
		return (exitPrint("Error: Bad date (format must be YYYY-MM-DD)", EXIT_ERROR));
		break;
	case ERR_DATE:
		return (exitPrint("Error: Impossible date", EXIT_ERROR));
		break;
	case ERR_VALN:
		return (exitPrint("Error: Not a positive integer", EXIT_ERROR));
		break;
	case ERR_VALL:
		return (exitPrint("Error: Too big to be an integer", EXIT_ERROR));
		break;
	case ERR_VALC:
		return (exitPrint("Error: Missing data", EXIT_ERROR));
		break;
	default:
		std::ostringstream strNb;
		strNb << code;
		std::cout << "Unknown error: ";
		return (exitPrint(strNb.str().c_str(), EXIT_ERROR));
		break;
	}
	return (SUCCESS);
}

// CONTAINER FILLING

int fillContainer(std::map<std::string, std::string> &container, dataStruct_t &data)
{
	std::string dbLine;
	std::getline(data.database, dbLine);

	while (std::getline(data.database, dbLine))
	{
		std::istringstream sstream(dbLine);
		std::string date;
		std::string value;
		std::string word;
		unsigned int i = 0;

		while (std::getline(sstream, word, ','))
		{
			if (i == 0)
				date = word;
			else if (i == 1)
				value = word;
			else
				return (EXIT_ERROR);
			i++;
		}
		container[date] = value;
	}
	return (SUCCESS);
}

// RESULT PARSING/DISPLAYING

int parseInput(std::string date, std::string quantity, dataStruct_t &data, Date &dateObj, double &qty)
{
	// Parsing value
	std::istringstream ssQuantity(quantity);
	std::string tmp;
	double decimal = 0;

	if (!(ssQuantity >> qty) || qty < 0)
		return (errorHandler(ERR_VALN, data));
	else if (qty > INT_MAX)
		return (errorHandler(ERR_VALL, data));
	if (ssQuantity >> tmp)
	{
		std::istringstream ssTmp(tmp.substr(1, tmp.size()));
		if (tmp[0] == ',')
		{
			if (ssTmp >> decimal)
			{
				while (decimal > 1)
					decimal /= 10;
				qty += decimal;
			}
			else
				return (errorHandler(ERR_VALN, data));
			if (ssTmp >> tmp)
				return (errorHandler(ERR_VALN, data));
		}
		else
			return (errorHandler(ERR_VALN, data));
	}

	// Parsing date
	for (unsigned long i = 0; i < date.size(); i++)
	{
		if (date.size() != 10)
			return (errorHandler(ERR_DATE, data));
		if ((date.at(i) < '0' || date.at(i) > '9') && date.at(i) != '-')
			return (errorHandler(ERR_DATE, data));
		if (date.at(i) == '-' && i != 4 && i != 7)
			return (errorHandler(ERR_DATE, data));
		if ((i == 4 || i == 7) && date.at(i) != '-')
			return (errorHandler(ERR_DATE, data));
	}

	dateObj = date;
	std::istringstream ssDate(date);
	std::string chunk;
	std::stringstream ssChunk;
	int year, month, day;

	std::getline(ssDate, chunk, '-');
	ssChunk << chunk;
	ssChunk >> year;

	std::getline(ssDate, chunk, '-');
	ssChunk.clear();
	ssChunk << chunk;
	ssChunk >> month;

	std::getline(ssDate, chunk, '-');
	ssChunk.clear();
	ssChunk << chunk;
	ssChunk >> day;

	if ((month > 12) || (day > 31) || (year % 4 && month == 2 && day > 28) || (!(year % 4) && month == 2 && day > 29))
		return (errorHandler(ERR_DATE, data));
	return (SUCCESS);
}

double getTotal(double qty, std::string cValue)
{
	std::stringstream ssC;
	double dCValue;
	ssC << cValue;
	ssC >> dCValue;

	return (qty * dCValue);
}

void compareData(std::map<std::string, std::string> &container, dataStruct_t &data)
{
	std::string inLine;
	std::string strDate;
	std::string strQty;
	while (std::getline(data. input, inLine))
	{
		std::istringstream sstream(inLine);
		std::string word;

		if (!std::getline(sstream, word, '|'))
		{
			errorHandler(ERR_DATE, data);
			continue;
		}
		strDate = word.substr(0, word.size() - 1);

		if (!std::getline(sstream, word, '|'))
		{
			errorHandler(ERR_VALC, data);
			continue;
		}
		strQty = word.substr(1, word.size() - 1);

		Date date(1, 1, 1);
		double qty = 0.0;
		if (parseInput(strDate, strQty, data, date, qty) == EXIT_ERROR)
			continue;

		std::cout << date.str() << " => " << qty << " = ";

		if (container.find(date.str()) == container.end())
		{
			date -= 1;
			while (container.find(date.str()) == container.end() && date.getYear() >= 2009)
				date -= 1;
		}
		if (container.find(date.str()) != container.end())
			std::cout << getTotal(qty, container[date.str()]) << std::endl;
		else
			std::cout << "[ ERROR ] Date is too old" << std::endl;
	}
}

