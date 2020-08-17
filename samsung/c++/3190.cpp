//��
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
		board[a][b] = 1;//���
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
	for (time = 1;; time++) {//1�ʸ��� ����
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == 2) {//���ӳ�
			break;
		}
		if (board[nx][ny] != 1) {//��� ������
			board[snake.front().first][snake.front().second] = 0;//���� ����
			snake.pop();
		}
		board[nx][ny] = 2;
		snake.push({ nx,ny });//����� �߰�
		if (rotat[time] != NULL) {//��ȯ
			if (rotat[time] == 'D') {//������
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
