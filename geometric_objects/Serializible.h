#include <string>
#include <iostream>

using namespace std;

namespace my_shapes
{

class Serializible
{   
public: 
    virtual ~Serializible() = default;
    string str() const { return to_str(); }

private:
    virtual string to_str() const = 0;
};

}
