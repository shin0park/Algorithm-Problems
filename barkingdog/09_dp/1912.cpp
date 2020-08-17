//1912번 연속합
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 100001;
int n;
int d[MAX];
int s[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    d[1] = s[1];
    int maxSum = d[1];
    for (int i = 2; i <= n; i++){
        if (d[i - 1] > 0)
            d[i] = d[i - 1] + s[i];
        else
        {
            d[i] = s[i];
        }
        maxSum = max(maxSum,d[i]);
    }
    cout << maxSum;

    return 0;
}