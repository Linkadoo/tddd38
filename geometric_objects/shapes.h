#include <iostream>
#include <sstream>
#include <math.h>
#include "GeometricObject.h"

using namespace std;


namespace my_shapes
{
const double pi = atan(1) * 4;


class Point final : public GeometricObject 
{
public:
    Point(){}
    Point(double x, double y): x_{x}, y_{y} {}

    string to_str() const override
    { 
        ostringstream sstream;
        sstream << "Point: [" << x_ << ", "<< y_ << "]\n";
        return  sstream.str();
    }
    Point* clone() const override { return new Point(x_,y_); }
    
    double x_ = 0;
    double y_ = 0;
};

class Line : public GeometricObject
{
public:
    Line(){}
    Line(double x1,double y1, double x2, double y2) 
        : x1_{x1}, y1_{y1}, x2_{x2}, y2_{y2} {}

    string to_str() const override
    {
       ostringstream sstream;
      sstream  << "Line: p1(" << x1_ << ", " << y1_ << ") -> (" << x2_ << ", " << y2_ << ")\n";  
        return sstream.str();
    }
    Line* clone() const override{ return new Line(x1_,y1_, x2_, y2_); }  

    double x1_ = 0.0, y1_ = 0.0;
    double x2_ = 1.0, y2_ = 1.0;
};

class Circle : public GeometricObject, public Plane
{
public:
    Circle(){} 
    Circle(double radius) : radius_{radius} {}

    string to_str() const override { return "Circle: R=" + to_string(radius_); }
    double get_area() const override{ return pow(radius_,2)*pi; }
    double get_radius() const { return radius_; }
    double get_perimiter()const override{ return 2*radius_ * pi; }
    
    Circle* clone() const override{ return new Circle{radius_}; }
protected:
    double radius_{1.0};
};

class Rectangle : public GeometricObject, public Plane
{
public:
    Rectangle(){}
    Rectangle(double height, double width) :  width_{width}, height_{height} {}

    string to_str() const override
    {
        ostringstream sstream;
        sstream << "Rectangle W=" << width_ << ", H=" << height_ << "\n";
        return sstream.str();
    }
    Rectangle* clone() const override{ return new Rectangle(width_,height_); }
    double get_area() const override{ return width_*height_; }
    double get_perimiter() const override{ return 2*width_ + 2*height_; }
    double get_width() const { return width_;}
    double get_height() const { return height_;}

private:
    double width_ = 1.0, height_ = 1.0;
};

class Cylinder : public Circle, public Solid
{
public:
    Cylinder(){}
    Cylinder(double radius, double height) : Circle{radius}, height_{height} {}

    string to_str() const override
    {
        ostringstream sstream;
        sstream << "Cylinder; R=" << radius_;
        return sstream.str();
    }
    Cylinder* clone() const override{ return new Cylinder(radius_, height_);}
    double get_area() const override{ return 8*pi*pow(radius_,2) + 2*radius_*height_; }
    double get_volume() const override{ return 4*pi*pow(radius_,2)*height_; }
private:
    double height_{1.0};
};
} // namespace my_shape
