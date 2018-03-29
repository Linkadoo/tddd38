/*
 * program8.cc
 */
#include <string>
#include <iostream>
#include "demangle.h"
using namespace std;

template <typename T>
struct Object_Tracer
{
  Object_Tracer();
  ~Object_Tracer();
};

template <typename T>
Object_Tracer<T>::Object_Tracer()
{
  cout << "Object created " << demangle_name(typeid(T))
      << " (" << this << " )\n";
}

template <typename T>
Object_Tracer<T>::~Object_Tracer()
{
  cout << "Object destroyed " << demangle_name(typeid(T))
      << " (" << this << " )\n";
}

template <typename T>
class Wrapper : public Object_Tracer<Wrapper<T>>
{
public:
   Wrapper(T value = T{}) : value_{ value } {}

private:
   T value_;
};

int main()
{
  Wrapper wi{ 1 };                  // to be Wrapper<int>

   Wrapper<int>* wip = new Wrapper{ 2 };  // to be Wrapper<int>*

   Wrapper<double> wd{ 2.3 };

   delete wip;

   Wrapper<char> wch;

   return 0;
}
