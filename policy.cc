#include <iostream>
using namespace std;
template <typename FooPolicy>
class  Base
{
public:
    void foo()
    {
        FooPolicy::do_foo();
    }
};
struct FooPolicy1
{
    static void do_foo()
    {
        cout << "Foo according to policy 1\n";
    }
};
struct FooPolicy2
{
    static void do_foo()
    {
        cout << "Foo according to policy 2\n";
    }
};
int main()
{
    Base<FooPolicy1> fp1;
    fp1.foo();
    Base<FooPolicy2> fp2;
    fp2.foo();
}
