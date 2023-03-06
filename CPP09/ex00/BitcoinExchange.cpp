#include "BitcoinExchange.hpp"

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
		data.input.close();
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
		data.input.close();
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
				value = word.substr(1, word.size() - 1);
			else
				return (EXIT_ERROR);
			i++;
		}
		
		container[date] = value;

	}
	return (SUCCESS);
}

// RESULT PARSING/DISPLAYING

int parseInput(std::string date, std::string quantity, dataStruct_t &data)
{
	std::istringstream ssQuantity(quantity);
	double dQuantity;

	if (!(ssQuantity >> dQuantity) || dQuantity < 0)
		return (errorHandler(ERR_VALN, data));
	else if (dQuantity > INT_MAX)
		return (errorHandler(ERR_VALL, data));

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

	if ((year > 2023) || (month > 12) || (day > 31) || (year % 4 && month == 2 && day > 28) || (!year % 4 && month == 2 && day > 29))
		return (errorHandler(ERR_DATE, data));
	return (SUCCESS);
}

double getTotal(std::string inValue, std::string cValue)
{
	std::stringstream ss;
	double dInValue;
	double dCValue;
	
	ss << inValue;
	ss >> dInValue;
	ss.clear();
	ss << cValue;
	ss >> dCValue;

	return (dInValue * dCValue);
}

void compareData(std::map<std::string, std::string> &container, dataStruct_t &data)
{
	std::string inLine;
	std::getline(data.input, inLine);
	while (std::getline(data.input, inLine))
	{
		std::istringstream sstream(inLine);
		std::string word;

		if (!std::getline(sstream, word, '|'))
		{
			errorHandler(ERR_DATE, data);
			continue;
		}
		std::string date = word.substr(0, word.size() - 1);

		if (!std::getline(sstream, word, '|'))
		{
			errorHandler(ERR_VALC, data);
			continue;
		}
		std::string quantity = word.substr(1, word.size() - 1);

		if (parseInput(date, quantity, data) == EXIT_ERROR)
			continue;

		std::cout << date << " => " << quantity << " = " << getTotal(quantity, container[date]) << std::endl;
	}
}
