#include <iostream>
#include <string>

using namespace std;

struct tag1{};
struct tag2{};

struct A {
  using tag1;
};

struct B {
  using tag2;
}

template <typename T>
void do_Stuff(T & t)
{
  using tag_type = 
}
