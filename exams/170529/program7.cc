#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

int main()
{
    //1.
    vector<string> words{istream_iterator<string>(cin), istream_iterator<string>()};
  
    //2.
    cout << words.size() << " words read.\n";
    
    //3.
    for_each(words.begin(),words.end(),
        [](string & str){ transform(begin(str), end(str), begin(str), ::tolower); }
        );
    //4.
    sort(words.begin(), end(words));

    //5.
    words.erase(unique(words.begin(), words.end()), end(words));

    //6.
    cout << words.size() << " unique words remaining.\n\n";

    //7.
    cout << "The unique words in alfabetical order.\n";
    copy(words.begin(), words.end(),ostream_iterator<string>(cout, " "));
    cout << endl << endl;   
  
    //8.
    sort(words.begin(), end(words),
        [](string const & s1, string const & s2)
        {   
            if(s1.length() == s2.length()) return s1 < s2;
            else return s1.length() < s2.length();
        });

    //9.
    cout << "The unique words ordered by length.\n";
    copy(words.begin(), words.end(),ostream_iterator<string>(cout, " "));
    cout << endl;   
}
