#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <climits>

#define SUCCESS 0
#define EXIT_ERROR -1
#define ERR_NARG -1
#define ERR_OPDB -2
#define ERR_OPIN -3
#define ERR_PARS -4
#define ERR_DATF -5
#define ERR_DATE -6
#define ERR_VALN -7
#define ERR_VALL -8
#define ERR_VALC -9

typedef struct dataStruct
{
	std::ifstream database;
	std::ifstream input;
}	dataStruct_t;

typedef unsigned short uShort;

class Date : public std::string
{
private:
	short _year;
	uShort _month;
	uShort _day;

	Date();

	uShort getMonthLimit(uShort month, short year);
	
public:
	Date(short Y, uShort m, uShort d);
	Date(std::string dateStr);
	Date(const Date &ref);
	Date &operator=(const Date &rhs);
	Date &operator=(std::string str);
	~Date();
	
	short getYear() const;
	uShort getMonth() const;
	uShort getDay() const;

	Date &operator+=(unsigned short val);
	Date &operator-=(unsigned short val);
	std::string str();
};

int errorHandler(int code, dataStruct_t &data);
int fillContainer(std::map<std::string, std::string> &container, dataStruct_t &data);
void compareData(std::map<std::string, std::string> &container, dataStruct_t &data);

#endif
