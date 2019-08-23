#include<iostream>
using namespace std;
auto add(int a, int b) -> decltype(a + b)
{
    return a + b;
}
template<typename T> auto
add1(T a, T b) -> decltype(a)
{
    return a + b;
}
int main()
{
    auto func = add;
    auto a = add1(2,2);
    cout << func(1,2) <<endl;
}
