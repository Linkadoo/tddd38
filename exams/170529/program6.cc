#include <iostream>
#include <string>
using namespace std;

class Fruit
{
public:
  virtual ~Fruit() = default;
  Fruit(int mass) : mass_{mass} {}
  virtual string const name() = 0;
  virtual int const vitamin_c_content() = 0;
  virtual bool const dehiscent() = 0;
  virtual int mass()
private:

  int mass_; // Expressed in grams
  double vitamin_c_concentration; // in mg/100 gram
};

class Berry : public Fruit
{
public:
  virtual ~Berry() = default;
  Berry(int mass) : Fruit(mass) {}
  
  bool override const dehiscent(){ return true; }
};

class final Apple : public Fruit
{
public:
  Apple(int mass) : Fruit(mass) {}
  string override const name(){ return "Apple"; }
  bool override const dehiscent{ return false; }
  int override const vitamin_c_content(){ return int(4.6); } // OBS NOT int
};

class final Pea : public Fruit
{
public:
  string override const name(){ return "Pea"; }
  bool override const dehiscent{ return false; }
};

class final Lemon : public Berry
{
public:
  string override const name(){ return "Lemon"; }
  using Berry::dehiscent();
 
};




void print(Fruit const & f)
{
    // Print Berry if f is a berry or Fruit otherwise

    cout << f.name() << " with mass " << f.mass() << "g [";
    if ( !f.dehiscant() )
    {
        cout << "in";
    }
    cout << "dehiscant]\n";

}

int main()
{
    // create a vector containing the following fruits:
    //  Apple, mass: 150g
    //  Lemon, mass: 75g
    //  Pea, mass: 25g
    //

    // Iterate through the vector and pass each fruit to print above, should give the following output
    // Fruit, Apple with mass 150g [indehiscant]
    // Berry, Lemon with mass 75g [indehiscant]
    // Fruit, Pea with mass 25g [dehiscant]

   int total_content {};
    // Calculate the total vitamin C content of all fruit

    cout << "Total vitamin C content: " << total_content << endl;
}
