#include <iostream>
#include <string>

using namespace std;

// Takes any built-in type
template <typename T>
T sum1(T a, T b){
  return a+b;
}

template <typename T, typename U>
//auto sum2(T a, T b) -> decltype(a+b)
//common_type_t sum2(T a, T b) //error
// Needs default constructors
//decltype(T{} + U{}) sum2(T a, U b)
// Doesnt create an instance, just checks what type it should have been
decltype(declval<T>() + declval<U>()) sum2(T a, U b)
{
  // Problem: We always trucate to int. There are a lot of solutions
  // You can use auto instead of T in return type
  // decltype returns the type from the operation
  return a+b;
}

//template <typename T, typename U, typename Ret>
template <typename Ret, typename U, typename T>
Ret sum3(T a, U b)
{
  return a+b;
}

template <typename U, typename T,
typename Ret = std::common_type_t<T,U>>
Ret sum4(T a, U b)
{
  return a+b;
}

//Base case for variadic
template <typename Single>
auto sum_impl(Single t)
{
  return t;
}
// Recursivly sum
template <typename First, typename ...Tail>
auto sum_impl(First f, Tail ...tail)
{
  return f + sum_impl(tail...);
}
//variadic template: This is the old way
template <typename ...Args>
auto sum5(Args ...vals)
{
  return sum_impl(vals...);
}

// Alternative with variadic template:
template <typename ... Args>
auto sum6(Args ...vals)
{
  // We can remove 0 if we want to.
  return( 0 + ... + vals);
}

//====================================

void fun(string &)
{
  cout << __PRETTY_FUNCTION__ << '\n';
}

void fun(string &&)
{
  cout << __PRETTY_FUNCTION__ << '\n';
}

template <typename T>
void foo(T && v) // This is not an R-value reference! Its a forwarding reference! Binds to whatever is necessary (because Template)
{ // This is called reference collapsing
  //fun(t);
  fun(forward<T>(v)); // Forwards if it is an R-value reference. Does nothing for L-value
}

int main(){

  //cout << sum1(3,5) << endl;
  //cout << sum1(3.3, 5.7) << endl;

  // But we only made a template for one type, not two?
  //cout << sum1(3.3,5) << endl;
  // You can choose what typename you want to use:
  //cout << sum1<double>(3.3,5) << endl;

  //cout << sum1<int,double,double>(3.3,4) << endl;

  //cout << sum3<double>(3.3,4) << endl;
  //cout << sum4(3.3,4) << endl;

  //We want a functions that can take a lot of values. Soultion variadic templates:
  //cout << sum5(3.3,4,34,23.2,25,23.0) << endl;
  //cout << sum6(2,4,34,23.2,25,23.0) << endl;

  string s;
  fun(s);
  foo(s);
  fun("hello"s);
  /*
  for( auto && c: s) // Can have && here for forwarding reference
  {
    cout << c;
  }
  */
  return 0;
}


// TODO: literals?
//TODO: Concatinate?
//TODO: Deduce
