//치킨배달
//bfs 시간초과
//애초에 말이안됨 거리를 계산하는 방법도 주어졌음
//굳이 그래프를 그리며 그곳까지 갈 필요가 애초에 없다.
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stdlib.h>

using namespace std;
const int MAX = 51;
int n, m, removeNum;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int selected[14];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int myMin = 987987987;
int bfs(int startX, int startY) {
	int dist = 0;
	fill(visited[0], visited[0] + MAX * MAX, false);
	queue<pair<int, int>> q;
	q.push({ startX,startY });
	visited[startX][startY] = true;
	bool isVaild = false;
	int x, y, nx, ny;
	while (!q.empty()) {
		if (isVaild)
			break;
		vector<pair<int, int>> tmp;
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			tmp.push_back({ x,y });
		}
		for (int t = 0; t < tmp.size(); t++) {
			x = tmp[t].first;
			y = tmp[t].second;
			//
			if (board[x][y] == 2) {//치킨집
				isVaild = true;
				dist = abs(startX - x) + abs(startY - y);
				break;
			}
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 1 || nx > n || ny < 1 || ny > n)
					continue;
				if (visited[nx][ny])
					continue;
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	return dist;
}
void getResult(int inx) {
	if (inx >= removeNum) {
		int x, y;
		for (int i = 0; i < removeNum; i++) {//치킨집 제거
			cout << selected[i] << " ";
		}
		cout << '\n';
		for (int i = 0; i < removeNum; i++) {//치킨집 제거
			x = chicken[selected[i]].first;
			y = chicken[selected[i]].second;
			board[x][y] = 0;
		}
		int cityDist = 0;
		for (int i = 0; i < house.size(); i++) {
			cityDist += bfs(house[i].first, house[i].second);
		}
		myMin = min(myMin, cityDist);
		for (int i = 0; i < removeNum; i++) {//치킨집 복구
			x = chicken[selected[i]].first;
			y = chicken[selected[i]].second;
			board[x][y] = 2;
		}
		return;
	}
	for (int i = 0; i < chicken.size(); i++) {
		if (inx == 0 || selected[inx - 1] < i) {
			selected[inx] = i;
			getResult(inx + 1);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				chicken.push_back({ i,j });
			else if (board[i][j] == 1)
				house.push_back({ i,j });
		}
	}
	removeNum = chicken.size() - m;
	getResult(0);
	cout << myMin;
	return 0;
}