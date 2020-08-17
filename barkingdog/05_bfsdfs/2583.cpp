//2583번 영역 구하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 101;
int n, m, k;
int square[MAX][4];
bool visit[MAX][MAX];
int num = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y){
    visit[x][y] = true;
    num++;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m){
            if (!visit[nx][ny])
                dfs(nx, ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int groupNum = 0;
    vector<int> emptNum;
    cin >> n >> m >> k;
    fill(visit[0], visit[0] + MAX * MAX, false);
    for (int i = 0; i < k; i++){
        for (int j = 0; j < 4; j++){
            cin >> square[i][j];
        }
    }
    int x, y, endX, endY;
    for (int i = 0; i < k; i++){
        x = square[i][1];
        y = square[i][0];
        endX = square[i][3];
        endY = square[i][2];
        for (int j = x; j < endX; j++){
            for (int k = y; k < endY; k++){
                visit[j][k] = true;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visit[i][j]){
                dfs(i, j);
                emptNum.push_back(num);
                num = 0;
                groupNum++;
            }
        }
    }
    cout << groupNum << '\n';
    sort(emptNum.begin(),emptNum.end());
    for (auto i : emptNum)
        cout << i << " ";
    return 0;
}