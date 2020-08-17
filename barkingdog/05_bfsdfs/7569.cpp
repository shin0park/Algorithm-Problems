//7569번 토마토
//7576번 토마토
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 101;
int n, m, h;
int dist[MAX][MAX][MAX];
int box[MAX][MAX][MAX];
int time = 0;
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
struct Node{
    int x;
    int y;
    int z;
};
bool isGreen(){
    for (int k = 0; k < h; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (box[i][j][k] == 0)
                    return true;
    return false;
}
void bfs(vector<Node> start){
    queue<Node> q;
    for (int i = 0; i < start.size(); i++){
        q.push(start[i]);
        dist[start[i].x][start[i].y][start[i].z] = 0;
    }
    int x, y, z, nx, ny, nz;
    while (!q.empty()){
        x = q.front().x;
        y = q.front().y;
        z = q.front().z;
        q.pop();
        for (int i = 0; i < 6; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            nz = z + dz[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h){
                if (dist[nx][ny][nz] == -1 && box[nx][ny][nz] == 0){   
                    box[nx][ny][nz] = 1;
                    dist[nx][ny][nz] = dist[x][y][z] + 1;
                    time < dist[nx][ny][nz] ? time = dist[nx][ny][nz] : time;
                    q.push({nx, ny, nz});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    
    vector<Node> start;
    Node node;
    for (int k = 0; k < h; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                dist[i][j][k] = -1;
                cin >> box[i][j][k];
                if (box[i][j][k] == 1){
                    node = {i, j, k};
                    start.push_back(node);
                }
            }
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