#ifndef MSGS
#define MSGS 1
#endif
#ifndef LIBPROTEC
#define LIBPROTEC
#include <iostream>
#include <string>
#include <exception>
#endif
#ifndef CONVERTOR
#define CONVERTOR

class Convertor
{
private:
	class NonDisplayableException : public std::exception
	{
		const char *what() const throw();
	};
	class ImpossibleConversionException : public std::exception
	{
		const char *what() const throw();
	};

private:
	std::string _type;

public:
	Convertor(char *str);
	Convertor(const Convertor &ref);
	Convertor &operator=(const Convertor &rhs);
	~Convertor();

	const std::string &convertFromString(char *str);

	const char &strChar(const std::string &ref);
	const char &intChar(const int &ref);

	const int &strInt(const std::string &ref);
	const int &charInt(const char &ref);
	const int &doubleInt(const double &ref);

	const double &strDouble(const std::string &ref);
	const double &intDouble(const int &ref);
	const double &floatDouble(const float &ref);

	const float &strFloat(const std::string &ref);
	const float &doubleFloat(const double &ref);
};

#endif