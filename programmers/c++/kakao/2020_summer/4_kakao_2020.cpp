#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 26;
int n;
int dist[MAX][MAX];
int corner[MAX][MAX];
int dir[MAX][MAX];// 0 1 2 3
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int turn[] = { 2,3,0,1 };
int myMin = 987987987;
struct REMOVE {
	int dist, corner;
	bool check;
};
REMOVE remove_route[MAX][MAX];
void bfs(vector<vector<int>> board) {
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	dist[0][0] = 0;
	corner[0][0] = 0;
	int x, y, nx, ny;
	while (!q.empty()) {
		bool isVaild = true;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == n - 1 && y == n - 1) {//도착지
			myMin = min(myMin, (dist[x][y] * 100 + corner[x][y] * 500));
			continue;
		}
		if (remove_route[x][y].check) {
			if (remove_route[x][y].dist != dist[x][y] && remove_route[x][y].corner != corner[x][y]) {
				isVaild = false;
			}
		}
		if (!isVaild) {
			remove_route[x][y].check = false;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1)
				continue;
			if (turn[dir[x][y]] == i)
				continue;
			if (dist[nx][ny] != -1) {//이미 들렸을 경우
				int tmp_dist = dist[x][y] + 1;
				int tmp_corner;
				if (!(x == 0 && y == 0) && abs(dir[x][y] - dir[nx][ny]) == 1)
					tmp_corner = corner[x][y] + 1;
				else
					tmp_corner = corner[x][y];
				int pre_value, new_value;
				pre_value = dist[nx][ny] + 5 * corner[nx][ny];
				new_value = tmp_dist + 5 * tmp_corner;
				if (pre_value <= new_value) {
					continue;
				}
				else {//새로운 루트가 차지
					REMOVE r = { tmp_dist,tmp_corner,true };
					remove_route[nx][ny] = r;
				}
			}
			q.push({ nx,ny });
			dist[nx][ny] = dist[x][y] + 1;
			dir[nx][ny] = i;
			if (!(x == 0 && y == 0) && abs(dir[x][y] - dir[nx][ny]) == 1) {
				corner[nx][ny] = corner[x][y] + 1;
			}
			else
				corner[nx][ny] = corner[x][y];
		}
	}
}
int solution(vector<vector<int>> board) {
	int answer = 0;
	n = board.size();
	fill(dist[0], dist[0] + MAX * MAX, -1);
	bfs(board);
	answer = myMin;
	return answer;
}
int main() {
	vector<vector<int>> board = { {0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0} };
	int ans = solution(board);
	cout << ans;
	return 0;
}