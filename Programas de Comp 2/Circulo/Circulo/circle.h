#ifndef CIRCLE_H
#define CIRCLE_H

class circle
{
private:
	double radius;
public:
	circle();
	circle(double);
	circle(const circle &);
	void setRadius(double);
	double getRadius() const;
	double getArea() const;		
	double getCircumference() const;
	void display() const;
};

#endif // !CIRCLE_H
