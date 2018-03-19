#ifndef OUTPUT_INCLUDED
#define OUTPUT_INCLUDED

#include <iostream>
#include <fstream>
#include "Input.h"
#include "ShapeArray.h"

class Output
{
public:
	static Output& getInstance();
	void save(const Input &, const ShapeArray&);
	void saveAs(const Input &, const ShapeArray&);

private:
	Output();
	Output(const Output&);
	void operator=(const Output&);
	~Output();

	void writeInFile(const Input& in, const ShapeArray&);
	bool openFile(const char*);

private:
	std::ofstream output;
};

#endif // !OUTPUT_INCLUDED