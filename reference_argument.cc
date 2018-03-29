#include <memory>
#include <iostream>

using namespace std;

void fun(int const & val){
  cout << val << endl;
}

int main()
{
  fun(8);
  return 0;
}
