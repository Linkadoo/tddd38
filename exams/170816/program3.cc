#include <vector>
#include <algorithm>
#include <functional>
#include <forward_list>
#include <iostream>
#include <iterator>
void ssort(std::vector<int> & values)
{
    for ( size_t idx {}; idx < values.size(); ++idx )
    {
        size_t smallest_at_index {idx};
        for ( size_t cur {idx+1}; cur < values.size(); ++cur )
        {
            if ( values[smallest_at_index] > values[cur] )
            {
                smallest_at_index = cur;
            }
        }
        std::swap(values[idx], values[smallest_at_index]);
    }
}
using namespace std;

template<typename Iter, typename Comp = less<typename iterator_traits<Iter>::value_type>>
void ssort(Iter start, Iter end, Comp comparator = {})
{
  for (Iter it{start}; it != end; it++)
  {
    auto pos = min_element(it, end, comparator);
    iter_swap(pos, it);
  }
  //copy(start,end,ostream_iterator<string>(cout, " "));
  //cout << endl;
}

int main()
{
  vector<int> vals {3,21,5,8,0,4,2,67};
    ssort(begin(vals), end(vals));
  forward_list<string> lst {"hello", "this", "is", "a", "test"};
  ssort(begin(lst), end(lst),
  [](string a, string b){
    return a.length() < b.length();
  });
}
