//새로운 게임2
//stack으로 풀이
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 13;
int n, horse_num;
int board[MAX][MAX];
stack<int> curMap[MAX][MAX];
struct Horse
{
	int x, y, dir;
};
Horse h[11];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
int main() {
	cin >> n >> horse_num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			stack<int> s;
			cin >> board[i][j];
			curMap[i][j] = s;
		}
	}
	for (int i = 1; i <= horse_num; i++) {
		int a, b, c;
		Horse horse;
		cin >> a >> b >> c;
		horse = { a - 1,b - 1,c };
		h[i] = horse;
		curMap[horse.x][horse.y].push(i);
	}
	int ans = 1;
	int x, y, nx, ny, dir;
	bool gameEnd = false;
	while (ans) {
		bool isVaild = true;
		for (int hh = 1; hh <= horse_num; hh++) {
			x = h[hh].x;
			y = h[hh].y;
			dir = h[hh].dir;
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 2) {//파란색이거나 벽
				if (isVaild) {
					if (dir == 1 || dir == 3)
						h[hh].dir += 1;
					else
						h[hh].dir -= 1;
					hh--;
					isVaild = false;
					continue;
				}
			}
			else if (board[nx][ny] == 0) {//흰
				stack<int> tmp;
				while (1) {
					int t = curMap[x][y].top();
					curMap[x][y].pop();
					tmp.push(t);
					if (t == hh)
						break;
				}
				while (!tmp.empty())
				{
					int t = tmp.top();
					tmp.pop();
					h[t].x = nx;
					h[t].y = ny;
					curMap[nx][ny].push(t);
				}
			}
			else if (board[nx][ny] == 1) {// 빨
				while (1) {
					int t = curMap[x][y].top();
					curMap[x][y].pop();
					h[t].x = nx;
					h[t].y = ny;
					curMap[nx][ny].push(t);
					if (t == hh)
						break;
				}

			}
			isVaild = true;
			for (int i = 1; i <= horse_num; i++) {
				if (curMap[h[i].x][h[i].y].size() >= 4)
					gameEnd = true;
			}
		}
		if (gameEnd)
			break;
		if (ans > 1000) {
			ans = -1;
			break;
		}
		ans++;
	}
	cout << ans;
	return 0;
}