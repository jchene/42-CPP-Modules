#ifndef MSGS
# define MSGS 1
#endif
#ifndef LIBPROTEC
# define LIBPROTEC
# include <iostream>
# include <string>
# include <sstream>
# include <exception>
#endif
#ifndef CONVERTOR
# define CONVERTOR

//CONVERTOR STRINGS
# define SIGNS "+-"
# define NUMBERS "0123456789"
# define ALL_SYM "+-.inf0123456789"
# define NOT_INT_SYM ".inf"
# define POINT "."
# define INF "inf"
# define SUFFIXES "f"

//STRING TYPES
# define INVALID 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4

//RETURN VALUES
# define KO 0
# define OK 1

class Convertor
{

private:
	char		_char;
	int			_int;
	float		_float;
	double		_double;

	int checkType(const std::string &ref);
	int countOccur(const std::string &str, const std::string &charset);
	bool isCharset(const char &c, const std::string &charset);
	void storeValue(char *str);
	void fillFromChar();
	void fillFromInt();
	void fillFromFloat();
	void fillFromDouble();
	void fillInvalid();

public:
	Convertor(char *str);
	Convertor(const Convertor &ref);
	Convertor &operator=(const Convertor &rhs);
	~Convertor();

	void displayAll();
};

#endif