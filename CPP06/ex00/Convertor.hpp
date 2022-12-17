#ifndef MSGS
# define MSGS 1
#endif
#ifndef LIBPROTEC
# define LIBPROTEC
# include <iostream>
# include <string>
# include <sstream>
# include <exception>
# include <limits>
#endif
#ifndef CONVERTOR
# define CONVERTOR

// CONVERTOR STRINGS
# define NB_SYM ".0123456789f"
# define SPE_SYM "infa"
# define NUMBERS "0123456789"
# define SIGNS "+-"
# define POINT "."
# define SUFFIXE "f"

// STRING TYPES
# define UNSET -1
# define INVALID 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4

// VALUE STATUSES
# define S_UNSET 5
# define S_IMPOSSIBLE 6
# define S_NON_DISP 7
# define S_NAN 8
# define S_INF 9
# define S_INFM 10
# define S_OK 11

// LIMITS
# define CHAR_MIN -128
# define CHAR_MAX 127
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define FLOAT_MAX 3.402823466e+38f

class Convertor
{

private:

	size_t		_offset;
	int			_type;

	char		_char;
	int			_cStatus;

	int			_int;
	int			_iStatus;

	float		_float;
	int			_fStatus;

	double		_double;
	int			_dStatus;

	int countOccur(const std::string &str, const std::string &charset);
	bool setRetType(bool ret, int value);
	bool checkPrefix(char *str);
	bool checkNumber(char *str);
	bool checkSpe(char *str);
	void fillChar(char *str);
	void fillInt(char *str);
	void fillFloat(char *str);
	void fillDouble(); 
	void convertValue(char *str);
	void storeValue(char *str);

public:
	Convertor(char *str);
	Convertor(const Convertor &ref);
	Convertor &operator=(const Convertor &rhs);
	~Convertor();

	const char *getDefineStr(int value);
	bool displayAll();
};

#endif