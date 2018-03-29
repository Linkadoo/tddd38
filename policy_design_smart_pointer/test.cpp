#include <iostream>
#include "policies.h"

using namespace std;

namespace my_smart_pointer
{


int main(){
    
    select_type<true, int, incompatible>::result res1;
    select_type<false,int, incompatible>::result res2;

    cout << "res1: " << to_string(res1) << std::endl;
    cout << "res2: " << to_string(res2) << std::endl;
    return 0;
}
};
