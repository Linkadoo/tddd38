#include <iostream>
#include <string>

using namespace std;

// Week 1
/*
    1.
    fix 1: for (i=0; i<n; n--)
    fix 2: for (i=0; i+n; i--)
    fix 3: for (i=0;-i<n; i--)

    2. 
    Comma expressions and argument delimiters,
    function patethesis and expression(?) parenthesis
    in comma expressions the last value is returned if withing parentheses
    (not the case for examples like 
    int a = 2,5; )
    fun (f,o,u,r) 4 parameters
    
    3.
*/
 

int main()
{
int i;
cout << (i = 1, i++, i++) << endl;
cout << i << endl;
                                        
i = 6;
cout << i << i++ << --i << endl;
                                                           
i = 0;
cout << (i--- --i)  << endl;
cout << i-(--(--i)) << endl;
cout << ((i--)---i) << endl;
return 0;
}
    /*
    QUESTION: Why is the fourth and fifth expression undefined?
    Is it about the parsing of i-----i?
    (-- has higher predecence than -) but that doesnt matter in the parsing?
*/

    
