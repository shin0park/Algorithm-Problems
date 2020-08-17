//1920번 수 찾기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 100000;
int n, m;
vector<int> a;
vector<int> num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> m;
    num.resize(m);
    for (int i = 0; i < m; i++){
        cin >> num[i];
    }
    for (int i = 0; i < m; i++){
        cout << binary_search(a.begin(), a.end(), num[i]) << '\n';
    }
    return 0;
}