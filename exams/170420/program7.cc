#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;



int main()
{
  //1.
  vector<string> words{istream_iterator<string>(cin), istream_iterator<string>()};

  //2.
  map<string,int> frequencies;
  for_each(begin(words), end(words),
    [&frequencies](string s){(frequencies[s])++; }
  );

  //3.
  vector<pair<string,int>> wl{make_move_iterator(begin(frequencies)), make_move_iterator(end(frequencies))};
  sort(begin(wl),end(wl),
    [](pair<string,int> & s1, pair<string,int> & s2){ return s1.second > s2.second; });
  //4.
  vector<string> replace(10);
  transform(begin(wl), next(begin(wl),10), begin(replace),
    [](pair<string,int> p){ return p.first;});

  //5.
  transform(begin(words), end(words), begin(words),
    [&replace](string s)
    {
      auto it = find(begin(replace),end(replace), s);
      if(it != end(replace))
        return "$" + to_string(distance(begin(replace), it));
      return s;
    }
  );

  //6.
  transform(begin(replace), end(replace),ostream_iterator<string>(cout, ";"),
    [index{0}](string s) mutable
    {
      ostringstream oss;
      oss << "$" << index++ << "=" << s;
      return oss.str();
    }
  );

  //7.
  copy(begin(words), end(words), ostream_iterator<string>(cout, " "));
  cout << endl;
  return 0;
}
