#include <iostream>

using namespace std;

namespace my_smart_pointer
{

class incompatible{};

template<bool selector, typename T1, typename T2>
struct select_type
{   //non-specialized
    typedef T1 result;
};

template <typename T1, typename T2>
struct select_type <false, T1, T2>
{   //specialized
    typedef T2 result;
};

struct allow_conversion { bool allow{true}; };
struct disallow_conversion { bool allow{false}; };

};
