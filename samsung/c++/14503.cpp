//로봇청소기
#include <iostream>

using namespace std;
int n, m;
int startX, startY, startDir;
const int MAX = 51;
int board[MAX][MAX];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int turn[] = { 2,3,0,1 };
int main() {
	cin >> n >> m;
	cin >> startX >> startY >> startDir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int x, y, dir, nx, ny;
	x = startX;
	y = startY;
	dir = startDir;
	bool isClean = false;
	while (1) {
		isClean = false;
		board[x][y] = 2;//1. 청소
		for (int i = 0; i < 4; i++) {
			if (dir == 0)
				dir = 3;
			else
				dir = dir - 1;//현재방향 기준 왼쪽방향
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (board[nx][ny] == 0) {//청소안함
				x = nx;
				y = ny;
				isClean = true;
				break;
			}
		}
		if (!isClean) {
			//후진
			x = x + dx[turn[dir]];
			y = y + dy[turn[dir]];
			if (board[x][y] == 1) {//벽
				break;
			}

		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 2)
				ans++;
		}
	}
	cout << ans;
	return 0;
}