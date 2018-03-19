#ifndef SHAPE_FACTORY_INCLUDED
#define SHAPE_FACTORY_INCLUDED

#include <cmath>
#include "ShapeArray.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"

struct DataForFigure
{
	char figType;
	double data[4];
	char colour[20];
};

class ShapeFactory
{
public:
	static ShapeFactory& getInstance();
	Shape* whatToCreate(const DataForFigure&);

private:
	ShapeFactory();
	ShapeFactory(const ShapeFactory&);
	void operator=(const ShapeFactory&);
	~ShapeFactory();

private:
	Shape* createLine(const DataForFigure&);
	Shape* createRect(const DataForFigure&);
	Shape* createCircle(const DataForFigure&);
};

#endif // !SHAPE_FACTORY_INCLUDED