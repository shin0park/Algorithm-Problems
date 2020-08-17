//9663번 N-Queen
#include <iostream>

using namespace std;
const int MAX = 14 * 14 + 1;
int n;
bool used1[MAX];
bool used2[MAX];
bool used3[MAX];
int ans = 0;
void fun(int r){
    if (r == n){
        ans++;
        return;
    }
    for (int c = 0; c < n; c++){
        if (!used1[c] && !used2[r + c] && !used3[r - c + n - 1]){
            used1[c] = true;
            used2[r + c] = true;
            used3[r - c + n - 1] = true;
            fun(r + 1);
            used1[c] = false;
            used2[r + c] = false;
            used3[r - c + n - 1] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fun(0);
    cout << ans;
    return 0;
}