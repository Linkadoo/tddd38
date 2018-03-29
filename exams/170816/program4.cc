#include <vector>
#include <iostream>
#include <iomanip>

struct Any
{
    template <typename T>
    bool policy(T const &t)
    {
      return static_cast<bool>(t);
    }

    bool combine(bool a, bool b)
    {
      return (a || b);
    }
    bool done(bool res)
    {
      return res;
    }

    static bool constexpr const done_result {true};
    static bool constexpr const start {false};
};

struct All
{
    template <typename T>
    bool policy(T const &t)
    {
      return static_cast<bool>(t);
    }

    bool combine(bool a, bool b)
    {
      return (a && b);
    }
    bool done(bool res)
    {
      return !res;
    }

    static bool constexpr const done_result {false};
    static bool constexpr const start {true};
};

struct AtLeast
{
    AtLeast(int count) : count{count} {}
    int count;

    template <typename T>
    bool policy(T const &t)
    {
      return static_cast<bool>(t);
    }

    bool combine(bool, bool b)
    {
      if(b) count--;
      if(!count) return true;
      else return false;
    }
    bool done(bool res)
    {
      return res;
    }

    static bool constexpr const done_result {true};
    static bool constexpr const start {false};
};

template <typename It, typename CombType = All>
bool logic_combine(It start, It end, CombType c = {} )
{
 auto res{ CombType::start};
 for(auto it{start}; it != end; ++it)
 {
   res = c.combine(res, *it);
   if(c.done(res))
    return CombType::done_result;
 }
 return !CombType::done_result;
}
/*
Given policy P
result := P.startValue
for each element e:
val := P.policy(e)
result := P.combine(result, val)
if P.done(result):
return P.endValue
return result
*/

// Main function. The output should be
// true
// false
// false
// true
int main()
{
  std::vector<int> vals {0,0,0,1};
  auto b { begin(vals) };
  auto e { end(vals) };
  using namespace std;
  cout << boolalpha
       << logic_combine(b,e, AtLeast{1}) << '\n'
       << logic_combine(b,e, AtLeast{8}) << '\n'
       << logic_combine(b,e, Any{}) << '\n'
       << logic_combine(b,e) << '\n';
}
