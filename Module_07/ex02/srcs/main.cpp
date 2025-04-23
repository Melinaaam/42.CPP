#include"Array.hpp"


// int main( void ) 
// {
//     int *a = new int();
//     float b = 2.2f;
//     char c = 'c';
//     std::string d = "Hello you";
//     int e = 123;

//     std::cout << "a : " << a << std::endl;
//     std::cout << "b : " << b << std::endl;
//     std::cout << "c : " << c << std::endl;
//     std::cout << "d : " << d << std::endl;
//     std::cout << "e : " << e << std::endl;

//     delete a;
//     return 0;
// }

#include <iostream>
#include <cstdlib>
#include "Array.hpp"
// #include "Array.tpp"

#define MAX_VAL 750

int main(int, char**)
{
    try
	{
		std::cout << CYAN << "---- DEFAULT TESTS ---- " << RESET << std::endl;

		Array<int> emptyArray;
		std::cout << MAGENTA << "* Empty array * " << RESET << std::endl;
		std::cout << YELLOW << " empty Array getSize : "  << RESET << emptyArray.getSize() << std::endl;

		Array<int> intArray(5);
		std::cout << YELLOW << " int Array getSize : " << RESET << intArray.getSize() << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
		{
			intArray[i] = i * 10;
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;
		}

        std::cout << MAGENTA << "* float array * " << RESET << std::endl;
        Array<float> floatArray(10);
		std::cout << YELLOW << " floatArray getSize : " << RESET << floatArray.getSize() << std::endl;
		for (unsigned int i = 0; i < floatArray.getSize(); ++i)
		{
			floatArray[i] = i * 1.1f;
			std::cout << "index[" << i << "] = " << floatArray[i] << std::endl;
		}

        std::cout << MAGENTA << "* char array * " << RESET << std::endl;
        Array<char> charArray(1);
		std::cout << YELLOW << " charArray getSize : " << RESET << charArray.getSize() << std::endl;
		for (unsigned int i = 0; i < charArray.getSize(); ++i)
		{
			charArray[i] = 'a';
			std::cout << "index[" << i << "] = " << charArray[i] << std::endl;
		}

        // std::cout << MAGENTA << "* string array * " << RESET << std::endl;
        // Array<std::string> stringArray(20);
		// std::cout << YELLOW << " stringArray getSize : " << RESET << stringArray.getSize() << std::endl;
        // stringArray[0] = "Hola";
		// for (unsigned int i = 0; i < charArray.getSize(); ++i)
		// {
		// 	std::cout << "index[" << i << "] = " << charArray[i] << std::endl;
		// }
        /*************************************************************************************** */
		std::cout << CYAN << "---- COPY TESTS ---- " << RESET << std::endl;
		Array<int> copiedArray(intArray);
		copiedArray[0] = 42;

        std::cout << YELLOW << "Original :" << RESET << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;
        std::cout << YELLOW << "Copy :" << RESET << std::endl;
		for (unsigned int i = 0; i < copiedArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << copiedArray[i] << std::endl;

        std::cout << CYAN << "---- COPY ASSIGMENT TEST ---- " << RESET << std::endl;
		Array<int> assignedArray;
		assignedArray = intArray;
		std::cout << YELLOW << "Original :" << RESET << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;
		assignedArray[4] = 42;
		std::cout << YELLOW << "Assigment :" << RESET << std::endl;
		for (unsigned int i = 0; i < assignedArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << assignedArray[i] << std::endl;

        std::cout << CYAN << "---- OUT OF BOUNDS TEST ---- " << RESET << std::endl;
		std::cout << YELLOW << "Size of array[" << intArray.getSize() << RESET << "trying to access index 10 " << std::endl;
		std::cout << intArray[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception : " << RED << e.what() << RESET << std::endl << std::endl;
	}
    return (0);
}