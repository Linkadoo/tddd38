#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main(){
  list<int> vals {213,124,5,14,15,1,2};
  //vector vals{2,24,5,16,166,2};
  //for (size_t idx{}; idx < vals.size(); ++idx){
  for(auto it= begin(vals); it != vals.end(); ++it)
    //cout << vals[idx] << ' ';
    cout << *it << ' ';

  }

  vector<int> val{2};
  copy(begin(vals), end(vals), begin(val));

  return 0;
}
