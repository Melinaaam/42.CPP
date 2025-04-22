#include"ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
		std::cerr << RED << "Not the right number of arguments" << RESET << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	return (0);
}
//nan : not a number
//+inf : infini pos
//-inf : infini neg 
    //pseudo litteraux speciaux

// ./convert 12.1f   # doit tomber dans FLOAT
// ./convert -.5f    # idem
// ./convert 3.14    # doit tomber dans DOUBLE
// ./convert 123     # INT
// ./convert a       # CHAR