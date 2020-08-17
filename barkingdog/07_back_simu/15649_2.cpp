//15649번 N과 M (1) stl 이용하는 방법 permutation
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 9;
int num[MAX];
int select[MAX];
int ans[MAX];
bool include[MAX];
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int c = 1;
    vector<int> seq;
    for(int i = 0; i<n;i++){
        num[i] = i;
        seq.push_back(0);
        if(i >=n-m)
            select[i] = c++;
        else
            select[i] = 0;
    }
    do{
        for(int i = 0; i<n;i++){
            if(select[i]) seq[select[i]-1] = num[i];
        }
        for(int i = 0; i<m;i++){
            cout << seq[i]<<" ";
        }
        cout <<"\n";
    }while(next_permutation(select,select+n));

    return 0;
}