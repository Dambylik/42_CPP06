

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Enter a value to convert\n" << std::endl;
		return (0);
	}

	std::string str(argv[1]);

	ScalarConverter::convert(str);
}