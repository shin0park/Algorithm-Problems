//뱀
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;
int board[MAX][MAX];
int n, k, l, x, c;
char rotat[10001];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int main() {
	cin >> n >> k;
	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		board[a][b] = 1;//사과
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> a;
		cin >> rotat[a];
	}
	queue<pair<int, int>> snake;
	int x = 1, y = 1;
	snake.push({ 1,1 });
	board[1][1] = 2;
	int nx, ny;
	int dir = 0;
	int time;
	for (time = 1;; time++) {//1초마다 실행
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == 2) {//게임끝
			break;
		}
		if (board[nx][ny] != 1) {//사과 없을떄
			board[snake.front().first][snake.front().second] = 0;//꼬리 비우기
			snake.pop();
		}
		board[nx][ny] = 2;
		snake.push({ nx,ny });//뱀길이 추가
		if (rotat[time] != NULL) {//변환
			if (rotat[time] == 'D') {//오른쪽
				if (dir == 3)
					dir = 0;
				else
					dir++;
			}
			else {
				if (dir == 0)
					dir = 3;
				else
					dir--;
			}
		}
		x = nx;
		y = ny;
	}
	cout << time;
	return 0;
}
