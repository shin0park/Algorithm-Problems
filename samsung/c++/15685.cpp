//�巡��Ŀ��
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 101;
int board[MAX][MAX];
int n;
struct Curve {
	int x, y, d, g;
};
Curve curves[21];
vector<pair<int, int>> locCurve[21];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
vector<pair<int, int>> getLocCurve(Curve c) {
	int startX, startY, d, g;
	startX = c.x;
	startY = c.y;
	d = c.d;
	g = c.g;
	vector<pair<int, int>> cv;
	cv.push_back({ startX, startY });
	cv.push_back({ startX + dx[d], startY + dy[d] });
	int x, y, mx, my, rx, ry;
	for (int gg = 1; gg <= g; gg++) {
		int moveX = -(cv[cv.size() - 1].first);
		int moveY = -(cv[cv.size() - 1].second);
		for (int i = cv.size() - 2; i >= 0; i--) {
			x = cv[i].first;
			y = cv[i].second;
			mx = x + moveX;//������ �������� �̵�
			my = y + moveY;
			//ȸ����ȯ
			rx = -1 * my;
			ry = mx;
			x = rx - moveX;//�������� �̵�
			y = ry - moveY;
			cv.push_back({ x,y });
		}
	}
	return cv;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> curves[i].x >> curves[i].y >> curves[i].d >> curves[i].g;
	}
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> cv;
		cv = getLocCurve(curves[i]);
		for (int j = 0; j < cv.size(); j++) {//Ŀ�� �׸���
			board[cv[j].second][cv[j].first] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < MAX-1; i++) {
		for (int j = 0; j < MAX-1; j++) {
			if (board[i][j] == 0)
				continue;
			if (board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1) {
				//�簢�� ����
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}