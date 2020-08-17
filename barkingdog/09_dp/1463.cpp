//1463번 1로만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1000001;
int n;
int d[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 0;
    for (int i = 2; i <= n; i++){
        int minD = d[i - 1] + 1;
        if (i % 3 == 0)
            minD = min(minD, d[i / 3] + 1);
        else if (i % 2 == 0)
            minD = min(minD, d[i / 2] + 1);
        d[i] = minD;
    }
    cout << d[n];
    return 0;
}