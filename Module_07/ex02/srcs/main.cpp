#include "Array.hpp"

int main()
{
    try
    {
        std::cout << CYAN << "---- DEFAULT TESTS ---- " << RESET << std::endl;

        Array<int> emptyArray;
        std::cout << YELLOW << std::endl << "* Empty intArray *" << RESET << std::endl;
        std::cout << "size = " << emptyArray.size() << std::endl;
		std::cout << emptyArray;

        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); ++i)
            intArray[i] = i * 10;
        std::cout << YELLOW << std::endl << "* intArray (size 5) *" << RESET << std::endl;
        std::cout << intArray;

        Array<float> floatArray(10);
        for (unsigned int i = 0; i < floatArray.size(); ++i)
            floatArray[i] = i * 1.1f;
        std::cout << YELLOW << std::endl << "* floatArray (size 10) *" << RESET << std::endl;
        std::cout << floatArray;

        Array<char> charArray(1);
        charArray[0] = 'a';
        std::cout << YELLOW << std::endl << "* charArray (size 1) *" << RESET << std::endl;
        std::cout << charArray;


		Array<std::string> stringArray(3);
		stringArray[0] = "first string !";
		stringArray[1] = "Hola que tal ?";
		stringArray[2] = "Hello !!!!!!!!!!!!";
        std::cout << YELLOW << std::endl << "* stringArray (size 3) *" << RESET << std::endl;
        std::cout << stringArray;

        std::cout << std::endl << CYAN << "---- COPY TESTS ---- " << RESET << std::endl;
        std::cout << CYAN << "---- INT ---- " << RESET << std::endl;

        Array<int> intCopy(intArray);

		std::cout << YELLOW << "Original intArray : " << RESET << std::endl << intArray << std::endl;
        std::cout << YELLOW << "Copy intArray : " << RESET << std::endl << intCopy << std::endl;

		std::cout << RED << "!!!!!! Modifying Original array  !!!!" << RESET  << std::endl;
		intArray[0] = 42;
		std::cout << YELLOW << "Original intArray : " << RESET << std::endl << intArray << std::endl;
        std::cout << YELLOW << "Copy intArray : "<< RESET  << std::endl << intCopy << std::endl;

        std::cout << CYAN << "---- FLOAT ---- " << RESET << std::endl;

        Array<float> floatOrig(3);
        floatOrig[0] = 1.1f; floatOrig[1] = 2.2f; floatOrig[2] = 3.3f;
        Array<float> floatCopy(floatOrig);

		std::cout << YELLOW << "Original floatArray : "<< RESET  << std::endl << floatOrig << std::endl;
        std::cout << YELLOW << "Copy floatArray : " << RESET << std::endl << floatCopy << std::endl;

		std::cout << RED << "!!!!!! Modifying Original array  !!!!" << RESET  << std::endl;
        floatOrig[2] = 9.9f;
		std::cout << YELLOW << "Original floatOrig : " << RESET << std::endl << floatOrig << std::endl;
        std::cout << YELLOW << "Copy floatArray : "<< RESET  << std::endl << floatCopy << std::endl;

        std::cout << CYAN << "---- CHAR ---- " << RESET << std::endl;

        Array<char> charOrig(3);
        charOrig[0] = 'x'; charOrig[1] = 'y'; charOrig[2] = 'z';
        Array<char> charCopy(charOrig);
		std::cout << YELLOW << "Original charArray : " << RESET << std::endl << charOrig << std::endl;
        std::cout << YELLOW << "Copy charArray : "<< RESET  << std::endl << charCopy << std::endl;

		std::cout << RED << "!!!!!! Modifying Original array  !!!!" << RESET  << std::endl;
		charOrig[1] = 'q';
		std::cout << YELLOW << "Original charArray : " << RESET << std::endl << charOrig << std::endl;
        std::cout << YELLOW << "Copy charArray : "<< RESET  << std::endl << charCopy << std::endl;

        std::cout << CYAN << "---- STRING ---- " << RESET << std::endl;

        Array<std::string> strOrig(2);
        strOrig[0] = "A"; strOrig[1] = "B";
        Array<std::string> strCopy(strOrig);
		std::cout << YELLOW << "Original stringArray : " << RESET << std::endl << strOrig << std::endl;
        std::cout << YELLOW << "Copy stringArray : "<< RESET  << std::endl << strCopy << std::endl;

		std::cout << RED << "!!!!!! Modifying Original array  !!!!" << RESET  << std::endl;
        strOrig[0] = "Z";
		std::cout << YELLOW << "Original stringArray : " << RESET << std::endl << strOrig << std::endl;
        std::cout << YELLOW << "Copy stringArray : "<< RESET  << std::endl << strCopy << std::endl;


        std::cout << CYAN << "---- COPY ASSIGNMENT TEST ---- " << RESET << std::endl;

        Array<int> assignedArray;
        assignedArray = intArray;               // opérateur =
        assignedArray[4] = 99;
		std::cout << YELLOW << "Original intArray : " << RESET << std::endl << intArray << std::endl;
        std::cout << YELLOW << "Assigned intArray : " << RESET << std::endl << assignedArray << std::endl;

        std::cout << CYAN << "---- OUT OF BOUNDS TEST ---- " << RESET << std::endl;
        std::cout << "trying intArray[10] on size " << intArray.size() << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception : " << RED << e.what() << RESET << std::endl;
    }
    return 0;
}
