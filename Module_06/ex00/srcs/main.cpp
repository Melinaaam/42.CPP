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


// # erreurs d’arguments
// ./convert
// ./convert a b

// # littéraux invalides
// ./convert hello
// ./convert 42..0

// # char
// ./convert c
// ./convert '#'
// ./convert ' '        # espace

// # int dans les bornes
// ./convert 0
// ./convert 42
// ./convert -42
// ./convert 2147483647     # INT_MAX
// ./convert -2147483648    # INT_MIN

// # int hors bornes
// ./convert 2147483648
// ./convert -2147483649

// # float “normaux”
// ./convert 0.0f
// ./convert 3.14f
// ./convert -3.14f
// ./convert 42.000f
// ./convert +0.5f

// # float pseudo-littéraux
// ./convert nanf
// ./convert inff
// ./convert +inff
// ./convert -inff

// # double “normaux”
// ./convert 0.0
// ./convert 3.1415
// ./convert -3.1415
// ./convert 42.000
// ./convert +0.5

// # double pseudo-littéraux
// ./convert nan
// ./convert inf
// ./convert +inf
// ./convert -inf

// # overflow en double/float
// ./convert 99999999999
// ./convert 9999999999999999

