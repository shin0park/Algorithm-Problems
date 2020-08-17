//11729번 하노이 탑 이동 순서
#include <iostream>

using namespace std;
const int MAX = 20;
int n, k = 0;
void hanoi(int a, int b, int n){
    if (n == 1){
        cout << a << " " << b << '\n';
        k++;
        return;
    }
    int c = 6 - a - b;
    hanoi(a, c, n - 1);
    cout << a << " " << b << '\n';
    k++;
    hanoi(c, b, n - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << (1 << n) - 1 << '\n';
    hanoi(1, 3, n);

    return 0;
}