//2579번 계단오르기
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 301;
int d[MAX];
int score[MAX];
int cnt[MAX];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> score[i];
    }
    d[0] = 0;
    d[1] = score[1];
    cnt[1] = 1;
    for (int i = 2; i <= n; i++){
        d[i] = d[i - 2] + score[i];
        if (cnt[i - 1] < 2)
            d[i] = max(d[i], d[i - 1] + score[i]);
        else
            d[i] = max(d[i], d[i - 3] + score[i - 1] + score[i]);
        if (d[i] == d[i - 2] + score[i])
            cnt[i] = 1;
        else
            cnt[i] = 2;
    }
    cout << d[n];
    return 0;
}
