//감시
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 9;
int n, m, k;
int board[MAX][MAX];
int tmpBoard[MAX][MAX];
struct CCTV {
	int x, y, num;
};
vector<CCTV> cctv;
int dir[6][4] = { {0,0,0,0},{0,1,0,0},{0,1,0,1},{1,1,0,0},{1,1,0,1},{1,1,1,1} };
int arr[9];
int tmpDir[4] = { 0,0,0,0 };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int myMin = 987987987;
void rotation(int cctvNum, int num) {
	for (int i = 0; i < 4; i++) {
		tmpDir[i] = dir[cctvNum][i];
	}
	for (int i = 0; i < num; i++) {
		int tmp = tmpDir[3];
		for (int j = 3; j > 0; j--) {
			tmpDir[j] = tmpDir[j - 1];
		}
		tmpDir[0] = tmp;
	}
}
int simulation() {
	int x, y, nx, ny;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int cctvNum = cctv[i].num;
		int startX = cctv[i].x;
		int startY = cctv[i].y;
		int rotatNum = arr[i];
		rotation(cctvNum, rotatNum);
		for (int j = 0; j < 4; j++) {
			x = startX;
			y = startY;
			if (tmpDir[j] == 1) {//cctv 작동
				while (1) {
					nx = x + dx[j];
					ny = y + dy[j];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 6)//벽이 있거나 범위 넘었을때 중단.
						break;
					x = nx;
					y = ny;
					if (board[nx][ny] == 0)//cctv 일때 지나감
						tmpBoard[nx][ny] = 9;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmpBoard[i][j] == 0)//빈칸: 사각지대
				cnt++;
		}
	}
	return cnt;
}
void getResult(int inx) {
	if (inx >= k) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmpBoard[i][j] = board[i][j];
			}
		}
		int si = simulation();
		myMin = min(myMin, si);
		return;
	}
	if (cctv[inx].num == 5) {//cctv가 5라면
		arr[inx] = 0;
		getResult(inx + 1);
	}
	else {
		for (int i = 0; i < 4; i++) {
			arr[inx] = i;
			getResult(inx + 1);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			tmpBoard[i][j] = board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5) {//cctv
				cctv.push_back({ i,j,board[i][j] });
			}
		}
	}
	k = cctv.size();
	getResult(0);
	cout << myMin;
	return 0;
}