//11726번 2*n 타일링
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1001;
int n;
int d[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++){
        d[i] = d[i - 1] + d[i - 2];
        d[i] %= 10007;
    }
    cout << d[n];
    return 0;
}