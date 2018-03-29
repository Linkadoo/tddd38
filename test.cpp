#include <algorithm>
#include <iostream>

using namespace std;

void foo(int )
{
    cout << 1;
}

int main()
{
    int i;
    foo(2);
}
/* TEST FOR DOUBLE CONSTRUCTOR 
template<typename T>
T max(T a,T b){
    return std::max(a,b);
}
int main()
{
    int i;
    double d;
    std::cout << std::to_string( max(double(i),d));
}
*/
/*
// TEST FOR CALLING CLASS MEMBER FUNCTIONS AND STATIC FUNCTIONS IN CLASSES
#include <iostream>

using namespace std;

struct Base
{
  static void fun() {
    cout << "Base::fun";
  }
};

struct Derived: Base
{
  static void fun() { // OBS; static
    cout << "Derived::fun";
  }
};

void foo(Base & b) {
  b.fun();
}

void foo(Derived & b) {
  b.fun();
  Derived::fun();
  Base::fun();
}

int main() {
  Derived d;
  foo(d);
  int a{'*'};
  cout << endl << to_string(a) << endl;
}
*/
/*
    TEST FOR RVALUEREF AND MOVE / BUILT IN TYPES
#include <iostream>
#include <utility>
#include <stdexcept>
#include <memory>
using namespace std;

class C{
public:
  int i = 3;
};
class D{
public:
  int val1, val2, val3 = 2, val4;
  int* pval1,*pval2, *pval3 = new int{123}, *pval4;
  // D(unique_ptr<C> && Cp): uCp {Cp} {
  //   //uCp = Cp;
  // }
  double f_val;
  D *d1,*d2,*d3,*d4;
  D(double val) : f_val{val}{}

  // Test of r-value reference
  D(int && v): val1{v}, val2{v}, val3{std::move(v)}, val4{v}
  {
    std::cout << "D constructed!\n val1:" << val1 <<"\n val2:" << val2 <<"\n val3:" << val3<<"\n val4:" << val4 << std::endl;
    val2 = 123;
    val2 = std::move(v);
    val3 = v;
    std::cout << "new val2:" << val2 << " and val3:" << val3 << std::endl;
    // Note: everything is 3.

    pval1 = new int{v};
    pval2 = new int{v};
    pval3 = std::move(&v);
    pval4 = new int{v};
    std::cout << "Pointer values \n*pval1: " << *pval1 << "\n*pval2: "<< *pval2 << "\n*pval3: " << *pval3 << "\n*pval4: " << *pval4 << std::endl;

  }

  D(D&& d){
    d1 = new D{1.0};
    d2 = new D{2.0};
    d3 = new D{3.0};
    d4 = new D{4.4};

    //TODO: BEhöver overloada && och &..
    //TODO: Fråga om move semantics i konstruktorer vs funktioner??


    // Call is ambiguous med D(int &&v) och D(int v). Kan man inte ha en konstruktorer för reference r-value och en för value?

    // Hur fungerar std::move med unique_ptr med unique_ptr?

  }

};


int main()
{

D * dp {new D(3)};
}

*/

//Notes unique_ptr:

// Enda(?) sättet ett l-value unique_ptr kan flyttas in i en funktion är via std::move(name) som inargument.
// Detta gör om contentet till ett R-value reference. Skulle funktionen ta in en unique_ptr by value skulle move-konstruktorn tillkallas
// (eftersom inargumentet är ett r-value reference) och sättas till inargumentets namn. Därefter kan t.ex. std::move användas på
// inargumentets funktionsnamn i funktionen för att flytta ägandeskapet till en variabel i funktionen.
