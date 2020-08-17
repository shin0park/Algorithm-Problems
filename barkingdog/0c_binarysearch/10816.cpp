//10816번 숫자카드2
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 500000;
vector<int> a;
vector<int> num;
int n, m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    num.resize(m);
    for (int i = 0; i < m; i++)
        cin >> num[i];
    sort(a.begin(),a.end());
    vector<int>::iterator low, up;
    for (int i = 0; i < m; i++)
    {
        low = lower_bound(a.begin(), a.end(), num[i]);
        up = upper_bound(a.begin(), a.end(), num[i]);
        cout << up - low << " ";
    }
    return 0;
}