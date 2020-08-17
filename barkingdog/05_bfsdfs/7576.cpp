//7576번 토마토
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1001;
int n, m;
int dist[MAX][MAX];
int box[MAX][MAX];
int time = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool isGreen(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (box[i][j] == 0)
                return true;
    return false;
}
void bfs(vector<pair<int, int>> start){
    queue<pair<int, int>> q;
    for (int i = 0; i < start.size(); i++){
        q.push({start[i].first, start[i].second});
        dist[start[i].first][start[i].second] = 0;
    }
    int x, y, nx, ny;
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m){
                if (dist[nx][ny] == -1 && box[nx][ny] == 0){
                    box[nx][ny] = 1;
                    dist[nx][ny] = dist[x][y] + 1;
                    time < dist[nx][ny] ? time = dist[nx][ny]:time;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    fill(dist[0], dist[0] + MAX * MAX, -1);
    vector<pair<int, int>> start;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> box[i][j];
            if (box[i][j] == 1)
                start.push_back({i, j});
        }
    }
    if (!isGreen()){
        cout << 0;
        return 0;
    }
    bfs(start);
    if (isGreen()){
        cout << -1;
        return 0;
    }
    
    cout << time;
    return 0;
}