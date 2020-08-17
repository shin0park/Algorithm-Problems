//구슬탈출2
//bfs로 풀기
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
const int MAX = 11;
int n, m;
struct INFO {
	int rx, ry, bx, by, cnt;
};
string board[MAX];
bool visited[MAX][MAX][MAX][MAX];
INFO start;
int myMin = 987987987;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int bfs() {
	int result = -1;
	queue<INFO>	q;
	q.push(start);
	visited[start.rx][start.ry][start.bx][start.by] = true;
	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();
		if (cur.cnt > 10) break;
		if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {//성공
			result = cur.cnt;
			break;
		}
		INFO next;
		for (int dir = 0; dir < 4; dir++) {
			next.rx = cur.rx;
			next.ry = cur.ry;
			next.bx = cur.bx;
			next.by = cur.by;
			while (1) {//빨강움직임
				next.rx += dx[dir];
				next.ry += dy[dir];
				if (board[next.rx][next.ry] == '#') {
					next.rx -= dx[dir];
					next.ry -= dy[dir];
					break;
				}
				else if (board[next.rx][next.ry] == 'O')
					break;
			}
			while (1) {
				next.bx += dx[dir];
				next.by += dy[dir];
				if (board[next.bx][next.by] == '#') {
					next.bx -= dx[dir];
					next.by -= dy[dir];
					break;
				}
				else if (board[next.bx][next.by] == 'O')
					break;
			}
			if (next.rx == next.bx && next.ry == next.by) {//r b가 위치같을때
				if (board[next.rx][next.ry] != 'O') {
					int distRed = (abs(next.rx - cur.rx) + abs(next.ry - cur.ry));
					int distBlue = (abs(next.bx - cur.bx) + abs(next.by - cur.by));
					if (distRed < distBlue) {
						next.bx -= dx[dir];
						next.by -= dy[dir];
					}
					else {
						next.rx -= dx[dir];
						next.ry -= dy[dir];
					}
				}
			}
			if (!visited[next.rx][next.ry][next.bx][next.by]) {
				visited[next.rx][next.ry][next.bx][next.by] = true;
				if (board[next.bx][next.by] == 'O')//실패
					continue;
				q.push({ next.rx, next.ry, next.bx, next.by,cur.cnt + 1 });
			}
		}
	}
	return result;
}
int main() {
	cin >> n >> m;
	start.cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				start.bx = i;
				start.by = j;
				board[i][j] = '.';
			}
		}
	}

	int ans = -1;
	ans = bfs();
	cout << ans;
	return 0;
}