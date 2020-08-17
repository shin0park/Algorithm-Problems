//연구소
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 51;
int n, m;
int board[MAX][MAX];
int dist[MAX][MAX];
int emptyNum = 0;
vector<pair<int, int>> virus;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int openVirus[11];
bool isVaild = false;
int myMin = 987987987;
int bfs(int start[]) {
	int cnt = 0;
	queue<pair<int, int>> q;
	int virusNum;
	for (int i = 0; i < m; i++) {
		virusNum = openVirus[i];
		q.push(virus[virusNum]);
		dist[virus[virusNum].first][virus[virusNum].second] = 0;
	}
	int x, y, nx, ny;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (dist[nx][ny] != -1 || board[nx][ny] == 1)//이미 방문했거나 벽일경우
				continue;
			q.push({ nx,ny });
			dist[nx][ny] = dist[x][y] + 1;
			if (board[nx][ny] == 0)
				cnt++;
			if (board[nx][ny] == 0 && cnt == emptyNum) {
				return dist[nx][ny];
			}
		}
	}
	return -1;
}
void getResult(int inx) {
	if (inx >= m) {
		fill(dist[0], dist[0] + MAX * MAX, -1);
		int time = bfs(openVirus);
		if (time != -1) {
			isVaild = true;
			myMin = min(myMin, time);
		}
		return;
	}
	for (int i = 0; i < virus.size(); i++) {
		if (inx == 0 || openVirus[inx - 1] < i) {//조합
			openVirus[inx] = i;
			getResult(inx + 1);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				emptyNum++;//빈칸의 수
			else if (board[i][j] == 2)
				virus.push_back({ i,j });//바이러스 
		}
	}
	if (emptyNum == 0) {// 빈칸이 없을때 
		cout << 0;
		return 0;
	}
	getResult(0);
	if (!isVaild)
		cout << -1;
	else
		cout << myMin;
	return 0;
}