//1149번 RGB거리
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1001;
int n;
int d[MAX][3];
struct price
{
    int r, g, b;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<price> s;
    cin >> n;
    int r, g, b;
    s.push_back({0, 0, 0});
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        cin >> g;
        cin >> b;
        s.push_back({r, g, b});
    }
    d[1][1] = s[1].r;
    d[1][2] = s[1].g;
    d[1][3] = s[1].b;
    for (int i = 2; i <= n; i++)
    {
        d[i][1] = s[i].r + min(d[i - 1][2], d[i - 1][3]);
        d[i][2] = s[i].g + min(d[i - 1][1], d[i - 1][3]);
        d[i][3] = s[i].b + min(d[i - 1][1], d[i - 1][2]);
    }
    cout << min(d[n][1], min(d[n][2], d[n][3]));
    return 0;
}