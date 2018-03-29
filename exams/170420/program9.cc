/*
 * program9.cc
 */
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

// Define Ordered_vector here!
template <typename T, typename Comparsion = std::less<T>>
class Ordered_Vector : public std::vector<T>
{
public:
  using std::vector<T>::const_iterator;
  using std::vector<T>::size;
  using std::vector<T>::empty;
  using std::vector<T>::clear;
  using std::vector<T>::cbegin;
  using std::vector<T>::cend;

  T const & operator[](size_t idx) const
  {
      return std::vector<T>::operator[](idx);
  }
  auto begin() const
  {
    return std::vector<T>::begin();
  }
  auto end() const
  {
    return std::vector<T>::end();
  }

  void insert(T value)
  {
    auto pos = lower_bound(std::vector<T>::begin(), std::vector<T>::end(), value, Comparsion{});
    std::vector<T>::insert(pos, std::move(value));
  }

  //~Ordered_Vector(); // TODO
  //Ordered_Vector() = default;
  //Ordered_Vector(& Ordered_Vector); //TODO
  //Ordered_Vector(&& Ordered_Vector); //TODO

};

int main()
{
   using namespace std;


   Ordered_Vector<int, std::greater<int>> v1;

   // cout << v1.front();  // Not allowed to access, as many other vector members

   if (v1.empty())
      cout << "v1 is empty.\n";
   else
      cout << "v1 is not empty.\n";

   v1.insert(5);
   v1.insert(2);
   v1.insert(8);
   v1.insert(3);
   v1.insert(4);
   v1.insert(1);
   v1.insert(9);
   cout << "7 values inserted into v1.\n";
   cout << "v1.size() = " << v1.size() << '\n';
   cout << "v1: ";
   for (unsigned i = 0; i < v1.size(); ++i)
   {
      cout << v1[i] << ' ';  // indexing
   }
   cout << '\n';

   cout << "v2 is copy initialized from v1\n";
   Ordered_Vector<int, std::greater<int>> v2{v1};

   cout << "v2: ";
   copy(begin(v2), end(v2), std::ostream_iterator<int>{cout, " "});
   cout << '\n';
   cout << "v1: ";
   copy(begin(v1), end(v1), std::ostream_iterator<int>{cout, " "});
   cout << '\n';

   cout << "v2 is cleared\n";
   v2.clear();
   cout << "v2.size() = " << v2.size() << '\n';

   cout << "v2 is assigned from v1.\n";
   v2 = v1;
   cout << "v2: ";
   for (auto x : v2)
   {
      cout << x << ' ';
   }
   cout << '\n';
   cout << "v1: ";
   copy(begin(v1), end(v1), std::ostream_iterator<int>{cout, " "});
   cout << '\n';

   return 0;
}
