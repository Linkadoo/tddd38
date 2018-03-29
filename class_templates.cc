#include <iostream>
#include <string>

using namespace std;
//Pair is std.
/*
template<class T1, class T2> struct pair {
  typedef T1 first_type;
  typedef T2 second_type;
};*/

int main()
{

  pair <int, char> pa { 3, 'a'};
  cout << pa.first << " " << pa.second << endl;
  // Compiler cant automatically create a pair, needs types..
  auto p = make_pair(4, "hello");

  //From c++17: Can look on initialization to figure out types
  pair p2 {4,4};

  //using actual_type = decltyp(2);


/*
  integral_constant <int, 7> ic;
  cout << ic << " " << ic() << endl; // Can call both as class or function (?)
  ic.value = 5;
*/
  // True and false are built as integral_constants with type bool,true or bool,false
  // is_same and similar functions then inherits from false_type etc

  // _make_unsigned - a helper type that makes an in fo uint for example.

}

// TODO: typename

//TODO: __ or _T starts of names are
