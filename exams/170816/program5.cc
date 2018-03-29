#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{
  // 1.
  vector<int> values { istream_iterator<int>{cin}, istream_iterator<int>{} };
  cout << "initial size: " << values.size() << endl;
  // 2.
  cout << values.size() << " values read." << "\n";
  copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  // 3.
  sort(values.rbegin()-1, values.rend());

  //4.
  values.erase(unique(values.begin(), values.end()), values.end());

  //5.
  copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  //6.
  int five_percent = 0.05*values.size();
  cout << "5%: " << five_percent << endl;
  cout << "now size: " << values.size() << endl;

  //7.
  values.erase(values.begin(), values.begin()+five_percent);
  values.erase(values.end()-five_percent, values.end());
  cout << "Largest and smallest values removed.\n";
  copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  //8.
  double mean{0.0};
  mean = accumulate(values.begin(), values.end(),mean)/values.size();
  cout << "Remaining mean: " << mean << endl;
  
}
