//낚시왕
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 101;
struct Shark {
	int r, c, s, d, z;
};
int r, c, m;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
int turn[] = { 0,2,1,4,3 };
Shark shark[10001];// 크기의 자리에 들어있음
int tmp[MAX][MAX];
int sea[MAX][MAX];
int main() {
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark[z] = { r,c,s,d,z };
		sea[r][c] = z;
	}

	int ans = 0;
	for (int tt = 1; tt <= c; tt++) {//c
		//제거
		for (int i = 1; i <= r; i++) {
			if (sea[i][tt] != 0) {//잡았다
				ans += sea[i][tt];
				sea[i][tt] = 0;
				break;
			}
		}
		//상어이동
		int nx, ny, dir, moveNum;
		fill(tmp[0], tmp[0] + MAX * MAX, 0);
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (sea[i][j] == 0)
					continue;
				int z = sea[i][j];//움직일 상어
				dir = shark[z].d;
				if (dir == 1 || dir == 2) {//위아래
					moveNum = shark[z].s % ((r - 1) * 2);
				}
				else
					moveNum = shark[z].s % ((c - 1) * 2);
				if (moveNum == 0) {
					nx = shark[z].r;
					ny = shark[z].c;
				}
				while (moveNum--) {
					nx = shark[z].r + dx[dir];
					ny = shark[z].c + dy[dir];
					if (nx < 1 || nx > r || ny < 1 || ny > c) {
						shark[z].d = turn[dir];
						dir = shark[z].d;
						nx = shark[z].r + dx[dir];
						ny = shark[z].c + dy[dir];
					}
					shark[z].r = nx;
					shark[z].c = ny;
				}
				if (tmp[nx][ny] != 0) {
					if (tmp[nx][ny] < z) {
						tmp[nx][ny] = z;
					}
				}
				else {
					tmp[nx][ny] = z;
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				sea[i][j] = tmp[i][j];
			}
		}
	}
	cout << ans;
	return 0;
}