//ÁÖ»çÀ§ ±¼¸®±â
#include <iostream>

using namespace std;

const int MAX = 21;
int board[MAX][MAX];
int n, m, x, y, k;
int run[1001];
int diceUp[4];
int diceSide[3];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
void rotat(int dir) {
	if (dir == 1) {//µ¿
		int tmp = diceUp[3];
		diceUp[3] = diceSide[2];//¹Ù´Ú
		diceSide[2] = diceSide[1];
		diceSide[1] = diceSide[0];
		diceSide[0] = tmp;
		diceUp[1] = diceSide[1];
	}
	else if (dir == 2) {//¼­
		int tmp = diceUp[3];
		diceUp[3] = diceSide[0];//¹Ù´Ú
		diceSide[0] = diceSide[1];
		diceSide[1] = diceSide[2];
		diceSide[2] = tmp;
		diceUp[1] = diceSide[1];
	}
	else if (dir == 3) {//ºÏ
		int tmp = diceUp[0];
		for (int i = 0; i < 3; i++) {
			diceUp[i] = diceUp[i + 1];
		}
		diceUp[3] = tmp;
		diceSide[1] = diceUp[1];
	}
	else {//³²
		int tmp = diceUp[3];
		for (int i = 3; i > 0; i--) {
			diceUp[i] = diceUp[i - 1];
		}
		diceUp[0] = tmp;
		diceSide[1] = diceUp[1];
	}
}
int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> run[i];
	}
	int dir,nx,ny;
	for (int i = 0; i < k; i++) {
		dir = run[i];
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		rotat(dir);
		if (board[nx][ny] == 0) {
			board[nx][ny] = diceUp[3];
		}
		else {
			diceUp[3] = board[nx][ny];
			board[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		cout << diceSide[1] << '\n';
	}
	return 0;
}