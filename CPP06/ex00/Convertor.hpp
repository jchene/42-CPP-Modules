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
# define NB_SYM ".0123456789f"
# define POINT "."
# define INF "infa"
# define SUFFIXE "f"

//STRING TYPES
# define UNSET -1
# define INVALID 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4

//VALUE STATUSES
# define S_UNSET 5
# define S_IMPOSSIBLE 6
# define S_NON_DISP 7
# define S_OK 8

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
	
	bool checkChar(char *str);
	bool checkPrefix(char *str);
	bool checkNumber(char *str);
	bool checkInf(char *str);
	void convertValue(char *str);
	void fillOthers(char *str);
	bool storeValue(char *str);

public:
	Convertor(char *str);
	Convertor(const Convertor &ref);
	Convertor &operator=(const Convertor &rhs);
	~Convertor();

	const char *getDefineStr(int value);
	bool displayAll();
};

#endif