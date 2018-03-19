#ifndef SHAPE_ARRAY_INCLUDED
#define SHAPE_ARRAY_INCLUDED
#include <iostream>
#include <fstream>
#include "Shape.h"
#include "Circle.h"

class ShapeArray
{
public:
	ShapeArray();
	ShapeArray(const ShapeArray&);
	ShapeArray& operator=(const ShapeArray&);
	~ShapeArray();

	void addShape(const Shape*, std::ostream&);
	void removeShape(int, std::ostream&);
	void printWithinCircle(const Circle*, std::ostream&) const;
	void printWithinRectangle(const Rectangle*, std::ostream&) const;
	void printShapes(std::ostream&) const;
	void translateAll(double, double); /// da napravq abs !!!
	void translateOne(int, double, double);
	void saveInFile(std::ofstream&) const;


private:
	void copyFrom(const ShapeArray&);
	void resize();
	void clear();

private:
	Shape** figures;
	int count;
	int capacity;
};

#endif // !SHAPE_ARRAY_INCLUDED