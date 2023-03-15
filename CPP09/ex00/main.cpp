#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	dataStruct_t data;

	if (argc < 2)
		return (errorHandler(ERR_NARG, data));

	data.database.open("data.csv", std::ifstream::in);
	if (!data.database.is_open())
		return (errorHandler(ERR_OPDB, data));
	
	std::map<std::string, std::string> valueContainer;

	if (fillContainer(valueContainer, data) == EXIT_ERROR)
		return (errorHandler(ERR_PARS, data));

	for (int i = 1; i < argc; i++)
	{
		data.input.open(argv[i], std::ifstream::in);
		if (!data.input.is_open())
			return (errorHandler(ERR_OPIN, data));

		compareData(valueContainer, data);

		std::cout << std::endl;
		data.input.close();
	}
	return (errorHandler(SUCCESS, data));
}
