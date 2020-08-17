//1182번 부분수열의 합
#include <iostream>

using namespace std;

const int MAX = 21;
int num[MAX];
int n, s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int subNum = 1 << n;
    int cnt = 0;
    for (int i = 1; i < subNum; i++){
        int tmp = i;
        int sum = 0;
        for (int j = 0; j < n; j++){
            if (tmp % 2 == 1)
                sum += num[j];
            tmp /= 2;
        }
        if (s == sum)
            cnt++;
    }
    cout << cnt;
    return 0;
}