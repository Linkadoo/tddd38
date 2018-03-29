#include <iostream>
#include "smart_pointer.h"

using namespace my_smart_pointer;
using std::cout;
using std::endl;

int main()
{
    smart_pointer sp1; // OBS: Gives munmap_chunk(): invalid pointer error
    smart_pointer sp2{new int{2}}; //
    smart_pointer sp3{new int{3}};
    smart_pointer sp4{new int{2}};

    //TODO: test construction
    
    // Test operator !, == and !=
    cout << "Test of sp2 == sp4: " << (int)(sp2 == sp4) << std::endl;
    cout << "Test of sp2 == sp3: " << (int)(sp3 == sp4) << std::endl;
      
    cout << "Test of int* == sp: " << (int)(new int{2} == sp4) << std::endl;
    cout << "Test of int* == sp: " << (int)(new int{3} == sp4) << std::endl;
    
    cout << "Test of sp == int*: " << (int)(sp4 == new int{2}) << std::endl;
    cout << "Test of sp == int*: " << (int)(sp4 == new int{3}) << std::endl;
   
    cout << "Test of sp1 == nullptr: " << (int)(sp1 == nullptr) << std::endl;
    cout << "Test of sp2 == nullptr: " << (int)(sp2 == nullptr) << std::endl;
     
    cout << "Test of sp2 != sp4: " << (int)(sp2 != sp4) << std::endl;
    cout << "Test of sp2 != sp3: " << (int)(sp3 != sp4) << std::endl;
      
    cout << "Test of int* != sp: " << (int)(new int{2} != sp4) << std::endl;
    cout << "Test of int* != sp: " << (int)(new int{3} != sp4) << std::endl;
    
    cout << "Test of sp != int*: " << (int)(sp4 != new int{2}) << std::endl;
    cout << "Test of sp != int*: " << (int)(sp4 != new int{3}) << std::endl;
   
    cout << "Test of sp1 != nullptr: " << (int)(sp1 != nullptr) << std::endl;
    cout << "Test of sp2 != nullptr: " << (int)(sp2 != nullptr) << std::endl;
    
    cout << "Test of !sp2: " << (int)(!sp2) << std::endl;
    cout << "Test of !sp1: " << (int)(!sp1) << std::endl;
      
    return 0;

}
