#include <iostream>
#include <string>

using namespace std;

/*template <typename StringType, // We want to remove stuff taht cant become a string
          typename = enable_if_t<is_construcatible<string, decay_t<StringType>>::value>
          >
auto to_string (StringType && s)
{
  string t{forward<StringType>(s)};
  return t;
}*/

template<typename ST>
auto to_string(ST && s) -> decltype(string{s})
{
  string t{forward<ST>(s)};
  return t;
}
template <typename ...Args>
string concat(Args &&...args)
{
  return (to_string(forward<Args>(args)) + ...);
}

struct C {};
int main(){
  string s{"hello"};
  cout << concat(C{}, 2, s, "hi", 3 ,"asd") << endl;
  return 0;
}


// -> decltype(std::cout << first, void()) // If the first argument instanciates then we return void

// How the compiler finds a suitable function:
// 1. Try standard type functions
// 2. Check for templates and instantiate those
// 3. Try type conversions
