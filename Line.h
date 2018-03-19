#ifndef LINE_INCLUDED
#define LINE_INCLUDED

#include "Shape.h"
#include "Point.h"

class Line :
	public Shape
{
public:
	Line(double = 0, double = 0, double = 0, double = 0);
	Line(const Point&, const Point&);
	Line& operator=(const Line&);
	~Line();

//	void setBase(double, double); имаме я от Shape
	void setEnd(double, double);


	bool withinCircle(Point, double) const override;
	bool withinRect(Point, double, double)  const override;
	void translate(double, double) override;

//	const Point getBase() const; имаме я от Shape
	const char* getName() const override;
	const Point& getEnd() const;
	void print(std::ostream&) const override;
	Shape* clone() const override;
	void saveAsSVG(std::ofstream&) const override;

private:
	Point end;
};

#endif // !LINE_INCLUDED
