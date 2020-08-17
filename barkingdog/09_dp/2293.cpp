//2293번 동전 1
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 101;
int n, k;
vector<int> a, b;
int s[MAX];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    a.resize(k + 1);
    b.resize(k + 1);
    fill(a.begin(), a.end(), 0);
    fill(b.begin(), b.end(), 0);
    for (int i = 0; i <= k; i += s[1]){
        b[i] = 1;
    }
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= k; j++){
            a[j] = b[j];
            if (j >= s[i])
                a[j] = b[j] + a[j - s[i]];
        }
        b = a;
    }
    cout << b[k];
    return 0;
}
