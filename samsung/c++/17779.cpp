//게리맨더링2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 21;
int board[MAX][MAX];
int area[MAX][MAX];
int n;
struct Divide
{
	int x, y, d1, d2;
};
vector<Divide> v;
vector<int> startY;
vector<int> endY;
int sum[6];
int myMax = -987987987;
int myMin = 987987987;
void oneArea(int x, int y, int d1, int d2) {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (r < x + d1 && c <= y)
				area[r][c] = 1;
		}
	}
}
void twoArea(int x, int y, int d1, int d2) {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (r <= x + d2 && y < c && c <= n)
				area[r][c] = 2;
		}
	}
}
void threeArea(int x, int y, int d1, int d2) {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (x + d1 <= r && r <= n && c < y - d1 + d2)
				area[r][c] = 3;
		}
	}
}
void fourArea(int x, int y, int d1, int d2) {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (x + d2 < r && r <= n && y - d1 + d2 <= c && c <= n)
				area[r][c] = 4;
		}
	}
}
void fifthArea(int x, int y, int d1, int d2) {
	for (int i = 0; i <= d1; i++) {
		area[x + i][y - i] = 5;
		area[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		area[x + i][y + i] = 5;
		area[x + d1 + i][y - d1 + i] = 5;
	}
	bool isStart = false;
	for (int i = x + 1; i < x + d1 + d2; i++) {
		isStart = false;
		for (int j = 1; j <= n; j++) {
			if (area[i][j] == 5) {
				isStart = !isStart;
				continue;
			}
			if (isStart)
				area[i][j] = 5;
		}
	}
}
void getResult() {
	for (int x = 1; x <= n - 2; x++) {
		for (int y = 2; y <= n; y++) {
			for (int d1 = 1; d1 <= n - 2; d1++) {
				for (int d2 = 1; d2 <= n - 2; d2++) {//  x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
					if (x < x + d1 + d2 && x + d1 + d2 <= n && 1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= n) {
						Divide d;
						d = { x,y,d1,d2 };
						v.push_back(d);
					}
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	getResult();
	for (int i = 0; i < v.size(); i++) {
		int x, y, d1, d2;
		x = v[i].x;
		y = v[i].y;
		d1 = v[i].d1;
		d2 = v[i].d2;
		fill(area[0], area[0] + MAX * MAX, 0);
		fill(sum, sum + 6, 0);
		oneArea(x, y, d1, d2);
		twoArea(x, y, d1, d2);
		threeArea(x, y, d1, d2);
		fourArea(x, y, d1, d2);
		fifthArea(x, y, d1, d2);
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				int areaNum = area[r][c];
				sum[areaNum] += board[r][c];
			}
		}
		sort(sum + 1, sum + 6);
		myMin = min(myMin, sum[5] - sum[1]);
	}
	cout << myMin;
	return 0;
}