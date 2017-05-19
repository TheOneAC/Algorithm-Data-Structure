#include <iostream>
#include <string>
using namespace std;

class A
{
    mutable int x;
public:
    A(int x =0):x(x){};
    void show()
    {
        cout <<  x << "show()" <<endl;
    }

    void show()const
    {
        x++;
        cout << x << "shiow()const" << endl;
    }

};
void test()
{
    A a;
    a.show();
    const A ca(10);
    ca.show();
}
int main()
{
    test();
}
