//2579번 다른 dp방법 2차원배열 사용.
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 301;
int d[MAX][MAX];
int s[MAX];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    d[0][1] = 0;
    d[0][2] = 0;
    d[1][1] = s[1];
    d[1][2] = 0;
    for (int i = 2; i <= n; i++){
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
        d[i][2] = d[i - 1][1] + s[i];
    }
    cout << max(d[n][1], d[n][2]);
    return 0;
}