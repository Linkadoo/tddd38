#include <iostream>
#include "Clonable.h"
#include "Serializible.h"

using namespace std;

namespace my_shapes
{

class GeometricObject : public Serializible, public Clonable
{
public:
    ~GeometricObject() = default;

protected:
    GeometricObject() = default;
    GeometricObject(const GeometricObject&) = default;
    GeometricObject( GeometricObject&&) = default;

private:
    GeometricObject& operator=(const GeometricObject&) = delete;
};

class Plane
{
public:
    ~Plane() = default;

    virtual double get_area() const = 0;
    virtual double get_perimiter() const = 0;

    Plane() = default;
    Plane(const Plane&) = default;
    Plane(Plane&&) = default;
    Plane& operator=(const Plane&) = default;
    Plane& operator=(Plane&&) = default;
};  

class Solid
{
public:
    ~Solid() = default;
    Solid() = default;
    Solid(Solid&) = default;
    Solid(Solid&&) = default;

    Solid& operator=(const Solid&) = default;
    Solid& operator=(Solid&&) = default;

    virtual double get_area() const = 0;
    virtual double get_volume() const = 0;

};

}
