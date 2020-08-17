//연구소
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
const int MAX = 9;
int board[MAX][MAX];
int tmp[MAX][MAX];
vector<pair<int, int>> virus;
pair<int, int> newWall[3];
int myMax = -987987987;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int bfs() {
	int emptyNum = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first,virus[i].second });//바이러스
	}
	int x, y, nx, ny;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (tmp[nx][ny] != 0)
				continue;
			tmp[nx][ny] = 2;
			q.push({ nx,ny });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {//안전지역
				emptyNum++;
			}
		}
	}

	return emptyNum;
}
void getResult(int inx) {
	if (inx >= 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = board[i][j];
			}
		}
		for (int i = 0; i < 3; i++) {//벽 만듬
			tmp[newWall[i].first][newWall[i].second] = 1;
		}
		myMax = max(myMax, bfs());
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0)
				continue;
			if (inx == 0 
				|| (newWall[inx - 1].first == i && newWall[inx - 1].second < j)
				|| (newWall[inx - 1].first < i)) {
				newWall[inx] = { i,j };
				getResult(inx + 1);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			tmp[i][j] = board[i][j];
			if (board[i][j] == 2)
				virus.push_back({ i,j });
		}
	}
	getResult(0);
	cout << myMax;
	return 0;
}