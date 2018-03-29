#include <memory>
using namespace std;
//Base class
class A
{
public:
  //If this is marked virtual it tells the compiler to look at the dynamic type
  //not just the static type. Will then call the inherited function.
  void foo(){}
  // Override will override the base class function

  //Use override if they should override baseclass function, virtual if they
  //CAN.

  virtual void fun(){}
  // Pure virtual, has no functionallity on this level.
  //This function has to be overidden to be able to compile.
  virtual void bar() = 0;

  // See line ~78
  virtual ~A() = default;
};

// Everything that is accessible in A is accessible in A
class B1 : public A
{
public:
  void fun() override{}
  void foo() {}
  void bar() override {}
};

class B2 : public A
{

};

class C2: public B2
{
private:
  //Not using public here..
  void bar() override {}

public:
  void fun(){}
};


// Will only copy the static type A if & is not used. This is called slicing
//(Takes a part of a class inherited by another class)
void foo(A & a)
{

}

int main(){
  B1 b;
  //Will call the function in B1, not A.
  b.foo();
  b.fun();

  A & ar{b};
  ar.foo();

  //OBS: Very important to distingush between static and dynamic type
  A* const ap{ new C2};
  ap->bar();

  //Will not work since A doesnt have the function. Have to cast to C2
  //ap->fun();
  {

    auto p = dynamic_cast<C2*>(ap);
    p->fun();
  }
  //This works as well as the lines above. Will not create a new resource
  // "Suppose p is a C2 pointer"
  if(auto p = dynamic_cast<C2*>(ap)){
    p->fun();
  }

  // C++17 initializers for selection statements (also switch)
  if(auto p = dynamic_cast<C2*>(ap); p != nullptr ){ //TODO: Why does this work?
    p->fun();
  }

  // With reference instead:
  auto r = dynamic_cast<B1&>(ar); // WIll throw a std::bad_cast if this wont work

  // This will be a memory leak. Only A's destructor will be called. A does
  //not have a virtual destructor as default

  foo(ar);
  delete ap;

  //cumbersome to delete things we dont wanna use anymore.
  //C++ got smart pointers

  unique_ptr<A> up {new C2};
  up->foo();
  unique_ptr<A> up2 {move(up)};
  // up2 still thinks it has the responsibility. If it gets deleted the thing
  // below wont work
  A* a{ up2.get() };
  //There's also a shared pointer.

}



//GDB + ctrl+x+1 graphical information with -g flag
// (n=next, s=step in)
