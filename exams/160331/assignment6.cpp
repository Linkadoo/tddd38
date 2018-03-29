#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Score_Variant
{
public:
  virtual string name() const = 0;
  virtual int score(vector<int>) const = 0;
  Score_Variant() = default;
private:
  Score_Variant( Score_Variant &) = delete;
  Score_Variant( Score_Variant &&) = delete;
  //Score_Variant operator=(Score_Variant&) = delete;
  //Score_Variant operator=(Score_Variant&&) = delete;
protected:
  virtual ~Score_Variant() = default;

};

class Counted_Dice : public Score_Variant
{
public:
  Counted_Dice(int number) : number_{number} {}
  virtual ~Counted_Dice() = default;
  int get_number() { return number_;}
  int score(vector<int> die) const override
  {
    return number_ * count(die.begin(), die.end(), number_);
  }
private:
  int number_;
};

class Pair : public Score_Variant
{
public:
  virtual ~Pair() = default;
  string name() const override { return "Pair";}
  int score( vector<int> die) const override
  {
    vector<int> pairs{6,0}; // 6 containers with zeros
    for(int i=0; i<die.size(); ++i)
    {
      int dice = die[i];
      ++(pairs[dice]);
    }
    for(int i=0; i<pairs.size(); ++i)
    {
      ; // TODO
    }
  }
};

class Ones : public Counted_Dice
{
public:
  virtual ~Ones() = default;
  Ones() : Counted_Dice(1) {}
  string name() const override{ return "Ones";}
};

class Twos : public Counted_Dice
{
public:
  virtual ~Twos() = default;
  Twos() : Counted_Dice(2) {}
  string name() const override { return "Twos";}
};

int main()
{
  unique_ptr<Ones> ones{new Ones};
  vector<int> vec{1,2,3,1,2,2};
  cout << "Result: " << to_string(ones->score(vec)) << endl;

}
