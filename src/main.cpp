#include <iostream>
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <exception>

int main()
{
	try
	{
		Controller c;
		c.run();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown exception!" << std::endl;
	}

	return EXIT_SUCCESS;
}