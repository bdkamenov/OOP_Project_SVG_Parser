#include "ShapeFactory.h"


ShapeFactory::ShapeFactory()
{
}


ShapeFactory::~ShapeFactory()
{
}

ShapeFactory & ShapeFactory::getInstance()
{
	static ShapeFactory instance;
	return instance;
}

Shape* ShapeFactory::whatToCreate(const DataForFigure& inputData)
{
	switch (inputData.figType)
	{
	case 'l':
	case 'L':
		return createLine(inputData);
		break;
	case 'r':
	case 'R':
		return createRect(inputData);
		break;
	case 'c':
	case 'C':
		return createCircle(inputData);
		break;
	default:
		std::cerr << "Input data Error in Creating\n";
		return nullptr;
		break;
	}
}

Shape* ShapeFactory::createLine(const DataForFigure & data)
{
	return new Line(data.data[0], data.data[1], data.data[2], data.data[3]);
}

Shape* ShapeFactory::createRect(const DataForFigure& data)
{
	return new Rectangle(data.data[0], data.data[1], data.data[2], data.data[3], data.colour);
}

Shape* ShapeFactory::createCircle(const DataForFigure & data)
{
	return new Circle(data.data[0], data.data[1], data.data[2], data.colour);
}
