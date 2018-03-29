#include <iostream>
using namespace std;

class Base
{
public:
  Base(int v) :  val{v}{}

  void foo(int){}
  void foo(double){}
  void foo(){}
private:
protected: //Can be accessed by inherited members
  int val;
};

class Derived : public Base
{
public:
  //Only way to catch init exception
  Derived() try :Base{5}, v2{}// Start with initializing base classes, then data members
  {

  } catch(...){
    throw;
  }

  void fun(){
    cout <<  val << endl;
  }
  using Base::foo;
  void foo(string){}

  //Which one will be used, derived or base?
  void foo(int){}


  void foo() = delete;
private:
  int v2;

};


class Derived2 : public Base
{
  using Base::Base;
  void asd(){
    Base::val = 2;
    val = 'c';
  }
private:
  char val;
};

//Exceptions
void thrower()
{
  throw std::logic_error("error!"); // <- initializes what
}

void t2(){
  throw 5;
}

// Can make your own exceptions, ofcourse
class My_exception : public logic_error
{
  using logic_error::logic_error;
};

int main()
{

  //Wont work without initialize Base.
  //Derived d;
  //d.foo(5); // Won't work since we have a foo(string). Works if we weire using Base::foo in Derived

  //Derived2 d2{6};

  // OBS; Let only the constructor containing a value initialize it. Let the constructor do its job

  //Exceptions now. All inherits from std::exception which contains copy operator and what (returning a string)
  try{
    //thrower();
    t2();
  }
  catch(std::range_error &a){ //Catch by reference since class
    cerr << a.what() << endl;
  }
  catch(std::logic_error &a){ //Catch by reference since class
    cerr << "logic error: " << a.what() << endl;
  }
  catch(... ){ //Catch by reference since class
    cerr << "catch everything" << endl;
  }

  //NP to nest try-catch blocks
}


// Type ID?
// WIll not touch multiple inhertiance hopefully..
