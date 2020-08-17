//2206번 벽 부수고 이동하기
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
const int MAX = 1001;
string board[MAX];
int dist[MAX][MAX][2];
int min_dist = -1;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct node{
    int x, y, w;
};
void bfs(){
    queue<node> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    int x, y, w, nx, ny;
    while (!q.empty()){
        x = q.front().x;
        y = q.front().y;
        w = q.front().w;
        q.pop();
        if(x == n-1 && y == m-1){
            min_dist = dist[x][y][w];
            return;
        }
        for (int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny][w])
                continue;
            if (board[nx][ny] == '0'){
                q.push({nx, ny,w});
                dist[nx][ny][w] = dist[x][y][w] + 1;
            }
            if (board[nx][ny] == '1' && w == 0){
                q.push({nx, ny, 1});
                dist[nx][ny][1] = dist[x][y][w] + 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> board[i];
    }
    bfs();
    cout << min_dist;
    return 0;
}