//1629번 곱셈
#include <iostream>

using namespace std;
typedef long long ll;
ll a, b, c;
ll myPow(ll a, ll b, ll c)
{
    if (b == 1)
    {
        return a % c;
    }
    ll val = myPow(a, b / 2, c);
    val = (val * val) % c;
    if (b % 2 == 0)
        return val;
    return (val * a) % c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << myPow(a, b, c);
    return 0;
}