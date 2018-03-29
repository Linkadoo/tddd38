#include <string>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;


class Slab
{
public:

  virtual ~Slab() noexcept = default;

  string get_color() const { return color;}
  double get_weight() const { return weight;}
  string get_size() const { return size;}
  virtual Slab* clone() const = 0;

protected:
  Slab(string color, double weight, string size) :
    color{move(color)}, weight{weight}, size{move(size)} {}
  Slab(Slab const &) = default;
private:
  string const color;
  double const weight;
  string const size;
};

class Concrete final : public Slab
{
public:
  Concrete(string color, double weight, string size, bool tumbled = false) :
    Slab(color,weight,size), is_tumbled{tumbled} {}
  bool tumbled() const { return is_tumbled;}
  ~Concrete() noexcept = default;

  Concrete* clone() const override
  {
    return new Concrete(get_color(), get_weight(), get_size(), is_tumbled);
  }
private:
  bool const is_tumbled;

};

class Rock final : public Slab
{
public:
  Rock(double weight, string size, string rock_type) :
    Slab("Nature", weight, size), rock_type{move(rock_type)} {}
  string get_type() const { return rock_type;}
  ~Rock() noexcept = default;

  Rock* clone() const override
  {
    return new Rock(*this);
  }
private:
  string const rock_type;
};

class Brick final : public Slab
{
public:
  Brick(string color, double weight, string size) : Slab(color, weight, size) {}
  Brick* clone() const override
  {
    return new Brick(get_color(), get_weight(), get_size());
  }
};

void test(Slab const & s)
{
  Slab const * p = s.clone();

  if(dynamic_cast<Concrete const*>(p))
    cout << "Concrete: " << p->get_color() << ", " << p->get_size() << ", "<< p->get_weight() << "\n";
  else if(auto r = dynamic_cast<Rock const*>(p))
    cout << "Rock: " << r->get_type() << ", " << p->get_color() << ", " << p->get_size() << ", "<< p->get_weight() << "\n";
  else if(dynamic_cast<Brick const*>(p))
    cout << "Brick: " << p->get_color() << ", " << p->get_size() << ", "<< p->get_weight() << "\n";
  else cout << "Unknown: ";

  delete p;
    // Create a copy of the object that s refers to
    //
    // Print the information about the copy. With objects constructed according to the
    // comments in main, the printout should be:
    // Concrete: Gray, 25x12x4, 2.8kg
    // Rock: Granite, Nature, 12x15x10, 10.5kg
    // Brick: Red, 25x10x10, 3.2kg
    // Concrete: Graphite, 20x20x6, 3.9kg, tumbled
    //
    // Destroy the copy

}

int main()
{
  vector<unique_ptr<Slab>> slabs;
  slabs.emplace_back(make_unique<Concrete>("Gray", 2.8, "25x12x4"));
  slabs.emplace_back(make_unique<Rock>(10.5,"12x15x10", "Granite"));
  slabs.emplace_back(make_unique<Brick>("Red", 3.2, "25x10x10"));
  slabs.emplace_back(make_unique<Concrete>("Graphite", 3.9, "20x20x6", true));
    // Create the following objects dynamically and store in some kind of container:
    // Type      Color    Size      Weight   type/tumbled
    // --------------------------------------------------
    // Concrete  Gray     25x12x4   2.8

    // Rock               12x15x10  10.5     Granite
    // Brick     Red      25x10x10  3.2
    // Concrete  Graphite 20x20x6   3.9      true
  for(auto && slab : slabs)
{
    test(*slab);
    // pass each object to test.
}
   return 0;
}


// Varför funkar inte unique_ptr<Slab> && istället för auto &&, men unique_ptr<Slab> & fungerar?
// Protected Slab(Slab const &) Concrete(*this)?
// Okej att skippa default-con/des samt delete?
