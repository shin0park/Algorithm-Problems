//�κ�û�ұ�
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
		board[x][y] = 2;//1. û��
		for (int i = 0; i < 4; i++) {
			if (dir == 0)
				dir = 3;
			else
				dir = dir - 1;//������� ���� ���ʹ���
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (board[nx][ny] == 0) {//û�Ҿ���
				x = nx;
				y = ny;
				isClean = true;
				break;
			}
		}
		if (!isClean) {
			//����
			x = x + dx[turn[dir]];
			y = y + dy[turn[dir]];
			if (board[x][y] == 1) {//��
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