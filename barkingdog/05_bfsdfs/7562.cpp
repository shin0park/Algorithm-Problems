//7562번 나이트의 이동
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 301;
int t, l;
int dist[MAX][MAX];
int dx[] = {1, 2, -1, -2, -2, -1, 1, 2};
int dy[] = {2, 1, 2, 1, -1, -2, -2, -1};
pair<int, int> start, arrive;
void bfs(int startX, int startY){
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;
    if (startX == arrive.first && startY == arrive.second){
        cout << 0 << '\n';
        return;
    }
    int x, y, nx, ny;
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < l && 0 <= ny && ny < l){
                if (dist[nx][ny] == -1){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                    if (nx == arrive.first && ny == arrive.second){
                        cout << dist[nx][ny] << '\n';
                        return;
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++){
        fill(dist[0], dist[0] + MAX * MAX, -1);
        cin >> l;
        cin >> start.first >> start.second;
        cin >> arrive.first >> arrive.second;
        bfs(start.first, start.second);
    }
}
