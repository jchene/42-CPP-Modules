#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	dataStruct_t data;

	if (argc != 2)
		return (errorHandler(ERR_NARG, data));
	
	data.database.open("db.csv", std::ifstream::in);
	if (!data.database.is_open())
		return (errorHandler(ERR_OPDB, data));
	
	data.input.open(argv[1], std::ifstream::in);
	if (!data.input.is_open())
		return (errorHandler(ERR_OPIN, data));
	
	std::map<std::string, std::string> valueContainer;

	if (fillContainer(valueContainer, data) == EXIT_ERROR)
		return (errorHandler(ERR_PARS, data));

	compareData(valueContainer, data);
	
	return (errorHandler(SUCCESS, data));
}
