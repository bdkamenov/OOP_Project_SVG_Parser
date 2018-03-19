#include "Output.h"


Output::Output()
{
}


Output::~Output()
{
}

void Output::writeInFile(const Input & in, const ShapeArray& arr)
{
		output << in.getHead();
		output << "\n<svg>\n";
		arr.saveInFile(output);
		output << "</svg>\n";
		output.close();
}

Output & Output::getInstance()
{
	static Output instance;
	return instance;
}

void Output::save(const Input & in, const ShapeArray & arr)
{
	if (openFile(in.getPath()))
	{
		writeInFile(in, arr);
		std::cout << "Successfully saved the changes to " << in.getPath() << std::endl;
	}
	else
	{
		std::cerr << "File wasn't open!\n";
		output.close();
	}
}

void Output::saveAs(const Input & in, const ShapeArray& arr)
{
	std::cout << "Enter file path and name: ";
	char path[_MAX_PATH];
	std::cin.getline(path, _MAX_PATH);

	if (openFile(path))
	{
		writeInFile(in, arr);
		std::cout << "Successfully saved the changes to " << path << std::endl;
	}
	else
	{
		std::cerr << "File wasn't open!\n";
		output.close();
	}
}

bool Output::openFile(const char* path)
{
	output.open(path, std::ios::trunc);
	return output.good();
}
