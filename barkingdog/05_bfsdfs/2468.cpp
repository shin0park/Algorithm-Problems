//2468번 안전영역
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 101;
int n;
int board[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> groupnum;
void dfs(int x, int y){
    visit[x][y] = true;
    int nx, ny;
    for (int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n){
            if (!visit[nx][ny])
                dfs(nx, ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int min, max;
    int ans = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
            if (i == 0 && j == 0){
                min = board[i][j];
                max = board[i][j];
            }
            else{
                min > board[i][j] ? min = board[i][j] : min;
                max < board[i][j] ? max = board[i][j] : max;
            }
        }
    }
    int num = 0;
    for (int i = min; i < max; i++){
        fill(visit[0], visit[0] + MAX * MAX, false);
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (board[j][k] <= i)
                    visit[j][k] = true;
            }
        }
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (!visit[j][k]){
                    dfs(j, k);
                    num++;
                }
            }
        }
        ans < num ? ans = num : ans;
        num = 0;
    }
    cout << ans;
    return 0;
}