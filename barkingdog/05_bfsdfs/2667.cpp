//2667번 단지번호붙이기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int MAX = 25;
int n;
string map[MAX];
bool visit[MAX][MAX];
int num = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
    int nx, ny;
    visit[x][y] = true;
    num++;
    for (int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n){
            if (!visit[nx][ny] && map[nx][ny] == '1'){
                dfs(nx, ny);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> houseNum;
    int groupNum = 0;
    fill(visit[0], visit[0] + MAX * MAX, false);
    for (int i = 0; i < n; i++){
        cin >> map[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (map[i][j] == '1' && !visit[i][j]){
                dfs(i, j);
                houseNum.push_back(num);
                groupNum++;
                num = 0;
            }
        }
    }
    sort(houseNum.begin(), houseNum.end());
    cout << groupNum << '\n';
    for (int i = 0; i < houseNum.size(); i++){
        cout << houseNum[i] << '\n';
    }
    return 0;
}