//인구이동
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;
const int MAX = 51;
int n, l, r;
int board[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pair<int,int>> change;
bool isVaild;
int ans;
void bfs(int startX,int startY){
    queue<pair<int, int>> q;
    q.push({startX,startY});
    int sum = 0, num = 1;
    bool go = false;
    visit[startX][startY] = true;
    change.push_back({startX,startY});
    sum += board[startX][startY];
    int x, y, nx, ny;
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || n <= ny)
                continue;
            int minus = abs(board[x][y] - board[nx][ny]);
            if (l > minus || minus > r || visit[nx][ny])
                continue;
            q.push({nx, ny});
            isVaild = true;
            go = true;
            change.push_back({nx,ny});
            visit[nx][ny] = true;
            num++;
            sum += board[nx][ny];
        }
    }
    if (!go)
        return;
    int move_num = sum / num;
    for(int i = 0; i < change.size(); i++){
        board[change[i].first][change[i].second] = move_num;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    while (true){
        isVaild = false;
        fill(visit[0], visit[0] + MAX * MAX, false);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (!visit[i][j]){
                    change.clear();
                    bfs(i, j);
                }
            }
        }
        if (isVaild)
            ans++;
        else
            break;
    }

    cout << ans;
    return 0;
}