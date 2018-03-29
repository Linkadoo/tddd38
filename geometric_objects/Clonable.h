#include <iostream>
#include <string>

using namespace std;

namespace my_shapes
{

class  Clonable
{
public:
    virtual ~Clonable() = default;
    virtual Clonable* clone() const = 0;
};

}
