//1926번 그림
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 500;
int draw[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool range(int nx, int ny){
    return (0 <= nx && nx < n && 0 <= ny && ny < m);
}
int bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int area = 1;
    int x, y;
    int nx, ny;
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (range(nx, ny)){
                if (draw[nx][ny] == 1 && visited[nx][ny] == false)
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    area++;
                }
            }
        }
    }
    return area;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int num = 0;
    int maxArea = 0;
    int tempArea = 0;
    fill(visited[0], visited[0] + MAX * MAX, false);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> draw[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (draw[i][j] == 1 && visited[i][j] == false){
                tempArea = bfs(i, j);
                maxArea < tempArea ? maxArea = tempArea : maxArea;
                num++;
            }
        }
    }
    cout << num << '\n'
         << maxArea;
    return 0;
}