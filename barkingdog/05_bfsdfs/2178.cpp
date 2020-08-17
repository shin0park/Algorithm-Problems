//2178번 미로탐색
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAX = 101;
int n, m;
string board[MAX];
int dist[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> board[i];
    }
    fill(dist[0], dist[0] + MAX * MAX, -1);

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    int x, y, nx, ny;
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m){
                if (dist[nx][ny] == -1 && board[nx][ny] == '1'){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }

    cout << dist[n - 1][m - 1];

    return 0;
}