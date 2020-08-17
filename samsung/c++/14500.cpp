//테트로미노
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 501;
int n, m;
int board[MAX][MAX];
int myMax = -987987987;
int shape[19][8] = {//모양별로 위치
	{0,0,0,0,0,1,2,3},
	{0,-1,-2,-3,0,0,0,0},

	{0,0,1,1,0,1,0,1},

	{0,1,2,2,0,0,0,1},
	{0,0,0,-1,0,1,2,2},
	{0,-1,-2,-2,0,0,0,-1},
	{0,0,0,1,0,-1,-2,-2},
	{0,1,2,2,0,0,0,-1},
	{0,0,0,-1,0,-1,-2,-2},
	{0,-1,-2,-2,0,0,0,1},
	{0,0,0,1,0,1,2,2},

	{0,1,1,2,0,0,1,1},
	{0,0,-1,-1,0,1,1,2},
	{0,1,1,2,0,0,-1,-1},
	{0,0,-1,-1,0,-1,-1,-2},

	{0,0,1,0,0,1,1,2},
	{0,-1,-1,-2,0,0,1,0},
	{0,0,-1,0,0,-1,-1,-2},
	{0,1,1,2,0,0,-1,0}
};
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int x, y, nx, ny;
	bool isVaild = true;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {//각각의 테트로미노 올려놓기 
				isVaild = true;
				sum = board[i][j];
				x = i;
				y = j;
				for (int h = 1; h < 4; h++) {
					nx = x + shape[k][h];
					ny = y + shape[k][h + 4];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) {// 테트로미노가 범위밖
						isVaild = false;
						break;
					}
					sum += board[nx][ny];
				}
				if (isVaild) {
					myMax = max(myMax, sum);
				}
			}
		}
	}
	cout << myMax;
	return 0;
}