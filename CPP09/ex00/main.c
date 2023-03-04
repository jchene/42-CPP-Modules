#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (exitPrint("Bad number of arguments", -1));
	std::ifstream database("db.csv");
	database.open();
	return (0);
}
