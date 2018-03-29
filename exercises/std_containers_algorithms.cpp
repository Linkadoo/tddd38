#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

const char letters[]{"abcdefghijklmnoprqstuvxyz"};

#include <cassert>
bool first_letter_exist (const string& first,const string& second)
{
  char const comparator (first.front());
  for (auto letter : second)
    if(comparator == letter )
      return true;

  return false;
}

int main()
{
  // 1.
  cout << "1." << endl;
  vector<char> vec(begin(letters), end(letters));
  copy(cbegin(vec), cend(vec), ostream_iterator<char>(cout, " "));
  cout << endl;
  copy(crbegin(vec) + 1, crend(vec), ostream_iterator<char>(cout, " "));
  cout << endl;

  // 2.
  cout << "2." << endl;
  vector<string> car_brands{istream_iterator<string>(cin), istream_iterator<string>()};
  sort(begin(car_brands), end(car_brands));
  copy(cbegin(car_brands), cend(car_brands), ostream_iterator<string>(cout, "\n"));
  cout << endl;

  //3.
  cout << "3." << endl;
  char certain_letter = 'f';
  for(auto car : car_brands)
  {
    if (certain_letter == car.front())
      cout << car << endl;
  }

  for( auto it = car_brands.begin(); it < car_brands.end(); it++)
    if( certain_letter == (*it).front())
      cout << *it << endl;


  return 0;
}
