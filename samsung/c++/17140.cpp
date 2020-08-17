//이차원 배열과 연산
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 101;
int board[MAX][MAX];
int r, c, k;
int n = 3, m = 3;
bool isVaild = false;//rc 위치의 값 k될때 true
int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	if (board[r - 1][c - 1] == k) {
		cout << 0;
		return 0;
	}
	for (int tt = 1; tt <= 100; tt++) {//100으로 바꾸기
		int cMax = -987987987;
		int rMax = -987987987;
		if (n >= m) {//r연산
			for (int i = 0; i < n; i++) {//행

				vector<pair<int, int>> v;//(횟수, 숫자)
				for (int j = 0; j < m; j++) {
					if (board[i][j] == 0)
						continue;
					bool flag = false;
					for (auto &e : v) {
						if (e.second == board[i][j]) {
							e.first++;
							flag = true;
						}
					}
					if (!flag)
						v.push_back({ 1, board[i][j] });
				}
				sort(v.begin(), v.end());
				if (v.size() > 50) {
					v.erase(v.begin() + 50, v.end());
				}
				for (int j = 0; j < v.size(); j++) {
					board[i][j * 2] = v[j].second;
					board[i][j * 2 + 1] = v[j].first;
				}
				for (int j = v.size() * 2; j < 100; j++) {
					board[i][j] = 0;
				}
				cMax = max(cMax, (int)v.size() * 2);

			}
			m = cMax;
		}
		else {//c연산
			for (int i = 0; i < m; i++) {//열

				vector<pair<int, int>> v;//(횟수, 숫자)
				for (int j = 0; j < n; j++) {//행
					if (board[j][i] == 0)
						continue;
					bool flag = false;
					for (auto &e : v) {
						if (e.second == board[j][i]) {
							e.first++;
							flag = true;
						}
					}
					if (!flag)
						v.push_back({ 1, board[j][i] });
				}
				sort(v.begin(), v.end());
				if (v.size() > 50) {
					v.erase(v.begin() + 50, v.end());
				}
				for (int j = 0; j < v.size(); j++) {
					board[j * 2][i] = v[j].second;
					board[j * 2 + 1][i] = v[j].first;
				}
				for (int j = v.size() * 2; j < 100; j++) {
					board[j][i] = 0;
				}
				rMax = max(rMax, (int)v.size() * 2);

			}
			n = rMax;
		}
		if (board[r - 1][c - 1] == k) {
			cout << tt;
			return 0;
		}
	}
	if (!isVaild) {
		cout << -1;
		return 0;
	}
	return 0;
}