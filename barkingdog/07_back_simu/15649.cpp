//15649번 N과 M (1)
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 9;
int ans[MAX];
bool include[MAX];
int n, m;

void fun(int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!include[i]){
            ans[k] = i;
            include[i] = true;
            fun(k + 1);
            include[i] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    bool include[MAX];
    fun(0);
    return 0;
}