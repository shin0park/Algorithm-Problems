#include <iostream>
#include <algorithm>
using namespace std;

int s[305];
int n;
int d[305]; // 강의 내에서 설명은 1-indexed로 했지만 메모리 절약을 위해 0-indexed로 구현했습니다. 
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int tot = 0;
  for(int i = 0; i < n; i++){
    cin >> s[i];
    tot += s[i];
  }
  if(n <= 2){
    cout << tot;
    return 0;
  }
  d[0] = s[0];
  d[1] = s[1];
  d[2] = s[2];
  for(int i = 3; i < n-1; i++) d[i] = min(d[i-2],d[i-3])+s[i];
  cout << tot - min(d[n-2],d[n-3]);
}