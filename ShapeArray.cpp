#include "ShapeArray.h"



ShapeArray::ShapeArray()
	: figures(nullptr)
	, count(0)
	, capacity(0)
{
}

ShapeArray::ShapeArray(const ShapeArray& other)
{
	copyFrom(other);
}

ShapeArray & ShapeArray::operator=(const ShapeArray & other)
{
	if (this != &other)
	{
		clear();
		copyFrom(other);
		return *this;
	}
	return *this;
}


ShapeArray::~ShapeArray()
{
	clear();
}

void ShapeArray::addShape(const Shape * obj, std::ostream& out)
{
	if (count >= capacity)
		resize();

	figures[count++] = const_cast<Shape*>(obj);
	out << "Successfully created " << figures[count - 1]->getName() << " (" << count << ")\n";
}

void ShapeArray::removeShape(int index, std::ostream& out)     // index - 1 dava broeneto ot 0
{
	if (index - 1 < count)
	{
		std::swap(figures[index - 1], figures[count - 1]);
		out << "Erased a " << figures[count - 1]->getName() << " (" << index << ")\n";
		delete figures[count - 1];
		figures[--count] = nullptr;
	}
	else
		out << "There is no figure number " << index << "\n";
}

void ShapeArray::printWithinCircle(const Circle * circle, std::ostream& out) const
{
	bool thereAre = false;
	int cnt = 0;
	for (int i = 0; i < count; i++)
	{
		if (figures[i]->withinCircle(circle->getBase(), circle->getRadius()))
		{
			cnt++;
			out << cnt << ". ";
			figures[i]->print(out);
			thereAre = true;
		}
	}

	if (!thereAre)
	{
		std::cerr << "No figures are located within ";
		circle->print(std::cerr);
	}

	delete circle;
}

void ShapeArray::printWithinRectangle(const Rectangle * rect, std::ostream& out) const
{
	bool thereAre = false;
	int cnt = 0;
	for (int i = 0; i < count; i++)
	{
		if (figures[i]->withinRect(rect->getBase(), rect->getHeight(), rect->getWidth()))
		{
			cnt++;
			out << cnt << ". ";
			figures[i]->print(out);
			thereAre = true;
		}
	}

	if (!thereAre)
	{
		std::cerr << "No figures are located within ";
		rect->print(std::cerr);
	}

	delete rect;
}

void ShapeArray::printShapes(std::ostream& out) const
{
	if (figures == nullptr)
		std::cout << "There are no figures yet\n";
	else
	{
		for (int i = 0; i < count; i++)
		{
			out << i + 1 << ". ";
			figures[i]->print(out);
		}
	}
}

void ShapeArray::translateAll(double hor, double vert)
{
	for (int i = 0; i < count; i++)
		figures[i]->translate(hor, vert);
	std::cout << "Translated all figures\n";
}

void ShapeArray::translateOne(int index, double hor, double vert)
{
	if (index - 1 < count)
	{
		figures[index - 1]->translate(hor, vert);
		std::cout << figures[index - 1]->getName() << " traslated\n";
	}
	else
		std::cerr << "There is no figure number " << index << "\n";
}

void ShapeArray::saveInFile(std::ofstream & output) const
{
	for (int i = 0; i < count; i++)
	{
		figures[i]->saveAsSVG(output);
	}
}

void ShapeArray::copyFrom(const ShapeArray & other)
{
	for (int i = 0; i < other.count; i++)
		addShape(other.figures[i]->clone(), std::cout);
}

void ShapeArray::resize()
{
	capacity == 0 ? capacity = 2 : capacity *= 2;

	Shape** buff = new Shape*[capacity];

	for (int i = 0; i < capacity; i++)
		buff[i] = nullptr;

	for (int i = 0; i < count; i++)
		buff[i] = figures[i];

	delete[] figures;
	figures = buff;
}

void ShapeArray::clear()
{
	for (int i = 0; i < capacity; i++)
	{
		delete figures[i];
	}

	delete[] figures;
	figures = nullptr;
}
