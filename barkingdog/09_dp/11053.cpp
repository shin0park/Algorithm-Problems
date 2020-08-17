//11053번 가장 긴 증가하는 부분 수열
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1001;
int n;
int s[MAX];
int d[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    d[1] = 1;
    int maxD = 0, ans = d[1];
    bool check = false;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j < i; j++){
            if (s[i] > s[j]){
                maxD = max(maxD, d[j]);
                check = true;
            }
        }
        if (check)
            d[i] = maxD + 1;
        else
            d[i] = 1;
        ans = max(ans, d[i]);
        check = false;
        maxD = 0;
    }
    cout << ans;
    return 0;
}