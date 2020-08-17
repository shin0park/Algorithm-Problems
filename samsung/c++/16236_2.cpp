//아기상어
//bfs 함수로 풀기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 21;
int board[MAX][MAX];
int dist[MAX][MAX];
int n, startX, startY, shark_size = 2, eaten;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int ans;
void bfs(){
    queue<pair<int, int>> q;
    int x, y, nx, ny;
    q.push({startX, startY});
    while (!q.empty()){
        vector<pair<int, int>> v;
        int size = q.size();
        for (int i = 0; i < size; i++){
            v.push_back(q.front());
            q.pop();
        }
        sort(v.begin(), v.end());
        int idx = 0;
        while (size--){
            x = v[idx].first;
            y = v[idx].second;
            idx++;
            if (board[x][y] != 0 && board[x][y] < shark_size){
                eaten++;
                if (eaten == shark_size){
                    shark_size++;
                    eaten = 0;
                }
                board[x][y] = 0;
                startX = x;
                startY = y;
                ans = dist[x][y];
                fill(dist[0], dist[0] + MAX * MAX, -1);
                dist[x][y] = ans;
                bfs();
                return;
            }
            for (int i = 0; i < 4; i++){
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx < 0 || n <= nx || ny < 0 || n <= ny)
                    continue;
                if ((board[nx][ny] != 0 && board[nx][ny] > shark_size) || dist[nx][ny] != -1)
                    continue;
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(dist[0], dist[0] + MAX * MAX, -1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
            if (board[i][j] == 9){
                startX = i;
                startY = j;
                board[i][j] = 0;
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    cout << ans;
    return 0;
}