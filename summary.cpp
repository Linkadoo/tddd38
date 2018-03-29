#include <iostream>
#include <string>

using namespace std;

// 1. if(a=0)
// 2. int a = 3.5; cout << a;
// 3. same with ()
// 4. what about {} (list initialization),  Undefined/Doesn't compile, narrowing conversion is ill-informed
// 5. fun(23) is R-value ref, int a{}; fun(a) us r-value, const int b{}; fun(b) is pr(pure-R) 
// 6. Now with struct T{} instead. T a; T const c {};  fun(T{}); fun(a); fun(c); gives  R-value, const ref, const ref.
// 7. Now with a template function, and an (int const &). The result is 222! We try to find the matching call will always start with a normal function with perfect match, can i instantiate a perfect template? Can I...
// 8. Now with template ref fuction. 121
// 9. Now with template ref ref. (T &&) This is a forwarding reference! The compiler does reference collapsing! &&-> & for a, && for 3, perfect for b
//
//Inheritance
//10. What happens in void foo(Base const &b) { b.fun} with derived class Derived : class base | struct always public, class always private as default. Answer Undefined (const cant call non-const)
//11. What about without const? Still doesn't compile! Can't pass a temporary object into L-value reference!
//12. What about if we create the object before. Prints base::fun() (Will always call base-version
//13. With virtual on both classes? One is marked const (doesnt override the base implementation)
//14. Question: What happened if not override? Use virtual and override
//
//
//15. Derived classes construction/destruction. What order for derived and base? base->derived | derived->base 
//16. What about a data member in a class? Always start by inistializing every sub object, then the constructor | Reverse for destruction
//17. template with is_integral , true for int, not for int & 
int main()
{

};











// Question: Is auto OK to use ont he exam?
// Question: static_cast vs dynamic_cast?
// Question: is assert OK to use?
// What is slicing?
// Braces vs parathesis for construction
//
//
// Good keywords:   const:
//                  use correctly (preferably) or dont use at all
//                  
//                  default/delete:
//                  delete for constructors you dont want and default for the ones that should be generated with the default
//                  Foo(int)
//                  template <typename T>
//                  Foo(T const &) = delete; Gives access to a constuctor taking int but not for types convertible to int
//
//                  virtual and override:
//                  polymorphic behaviour costs! (Therefore the keywords to tell the compiler)
//                  virtual to tell that the function can be overridden
//                  override is not necessary but checks if the function actually overrides
//
//                  auto:
//                  Guarantees that your variavles is initialized
//                  you get the correct type: now and if stuff changes
//                  
//                  smart_pointes(not really a keyword):
//                  Represent ownership
//
//Object Ooriented Programming is great, but dont overuse it.
//
//
//
//
