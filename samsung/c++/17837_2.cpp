//새로운게임
//vector로 풀이 
//vector의 reverse erase iterator 활용도 높이기
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
const int MAX = 13;
int board[MAX][MAX];
vector<int> info[MAX][MAX];
int n, k;
struct Horse
{
	int x, y, dir;
};
Horse h[11];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
int turn[] = { 0,2,1,4,3 };
int moving(int i) {//i번째 말이 이동.
	int x, y, nx, ny, dir;
	x = h[i].x;
	y = h[i].y;
	dir = h[i].dir;
	nx = x + dx[dir];
	ny = y + dy[dir];
	if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 2) {//파란색이거나 벽
		dir = turn[dir];
		h[i].dir = dir;//방향 바뀜.
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 2) {//또 파란색이거나 벽
			return 0;
		}
	}
	vector<int> &cur = info[x][y];
	vector<int> &next = info[nx][ny];
	auto my = find(cur.begin(), cur.end(), i);

	if (board[nx][ny] == 1) {// 빨- 뒤집기
		reverse(my, cur.end());
	}
	//이동
	for (auto it = my; it != cur.end(); it++) {
		h[*it].x = nx;
		h[*it].y = ny;
		next.push_back(*it);
	}
	cur.erase(my, cur.end());
	return next.size();
}
int simulation() {
	//게임 시작
	int stack_cnt = 0;
	for (int tt = 1; tt <= 1000; tt++) {
		for (int i = 1; i <= k; i++) {
			stack_cnt = moving(i);
			if (stack_cnt >= 4) {
				return tt;
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		h[i] = { x - 1,y - 1,d };
		info[x - 1][y - 1].push_back(i);
	}
	cout << simulation();
	return 0;
}