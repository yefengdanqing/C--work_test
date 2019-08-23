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
    auto a = func(2,2);
    auto res = add1(4,4);
    cout << res <<endl;
}

