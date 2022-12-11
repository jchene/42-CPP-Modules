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
# define CNV_INV 0
# define CNV_C 1
# define CNV_I 2
# define CNV_F 3
# define CNV_D 4

class Convertor
{

private:
	char		_char;
	int			_int;
	float		_float;
	double		_double;

public:
	Convertor(char *str);
	Convertor(const Convertor &ref);
	Convertor &operator=(const Convertor &rhs);
	~Convertor();

	void storeValue(char *str);
	void fillFromChar();
	void fillFromInt();
	void fillFromFloat();
	void fillFromDouble();
	void fillInvalid();
	void displayAll();
};

#endif