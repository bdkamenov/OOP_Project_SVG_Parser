#ifndef INPUT_INCLUDED
#define INPUT_INCLUDED

#include <iostream>
#include <fstream>
#include "Point.h"
#include "ShapeArray.h"
#include "ShapeFactory.h"



class Input
{

public:
	static Input& getInstance();
	bool inputFromFile(std::ostream&);
	bool inputFromKeybord(std::istream&);
	bool readFile(ShapeFactory&, ShapeArray&);
	const char* getHead() const;
	const DataForFigure& getDataForFig() const;
	const char* getPath() const;


private:
	Input();
	Input(const Input&);
	void operator=(const Input&) = delete;
	~Input();

	bool isContentRead();
	void readHead();
	void inputError();

private:
	char path[_MAX_PATH];
	std::ifstream input;
	char* headData;
	DataForFigure data;
};


#endif // !INPUT_INCLUDED