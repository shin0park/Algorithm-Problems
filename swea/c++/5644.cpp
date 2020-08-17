//무선충전
#pragma warning(disable:4996)
#include<iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAX = 102;
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };
struct ap {
	int x, y, c, p;
};
bool cmp(ap a, ap b) {
	return a.p < b.p;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<ap> board[11][11];
		int m, a;
		int move_a[MAX], move_b[MAX];
		cin >> m >> a;
		int t;
		for (int i = 1; i <= m; i++) {
			cin >> t;
			move_a[i] = t;
		}
		for (int i = 1; i <= m; i++) {
			cin >> t;
			move_b[i] = t;
		}
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= 10; k++) {
				board[j][k].push_back({ 0,0,0,0 });
			}
		}
		int x, y, c, p;
		for (int i = 1; i <= a; i++) {
			cin >> y >> x >> c >> p;
			for (int j = 1; j <= 10; j++) {
				for (int k = 1; k <= 10; k++) {
					if (abs(x - j) + abs(y - k) <= c) {
						board[j][k].push_back({ x,y,c,p });
					}
				}
			}
		}
		int ax = 1, ay = 1, bx = 10, by = 10;
		int battery_a = 0, battery_b = 0;
		int size1, size2, second_ap1, second_ap2;
		int apx1, apy1, apx2, apy2;
		for (int i = 0; i <= m; i++) {
			if (i != 0) {
				ax += dx[move_a[i]];
				ay += dy[move_a[i]];
				bx += dx[move_b[i]];
				by += dy[move_b[i]];
			}
			sort(board[ax][ay].begin(), board[ax][ay].end(), cmp);
			sort(board[bx][by].begin(), board[bx][by].end(), cmp);
			size1 = board[ax][ay].size();
			size2 = board[bx][by].size();
			if (size1 == 1 && size2 == 1)
				continue;
			apx1 = board[ax][ay][size1 - 1].x;
			apy1 = board[ax][ay][size1 - 1].y;
			apx2 = board[bx][by][size2 - 1].x;
			apy2 = board[bx][by][size2 - 1].y;
			if (apx1 == apx2 && apy1 == apy2) {
				//겹치는 ap 보유
				if (size1 <= 2 || size2 <= 2) {
					if (size1 < size2) {
						battery_a += board[ax][ay][size1 - 1].p;
						battery_b += board[bx][by][size2 - 2].p;
					}
					else if (size2 < size1) {
						battery_a += board[ax][ay][size1 - 2].p;
						battery_b += board[bx][by][size2 - 1].p;
					}
					else {
						battery_a += (board[ax][ay][size1 - 1].p / 2);
						battery_b += (board[bx][by][size2 - 1].p / 2);
					}
				}
				else {
					second_ap1 = board[ax][ay][size1 - 2].p;
					second_ap2 = board[bx][by][size2 - 2].p;
					if (second_ap1 > second_ap2) {
						battery_a += second_ap1;
						battery_b += board[bx][by][size2 - 1].p;
					}
					else {
						battery_a += board[ax][ay][size1 - 1].p;
						battery_b += second_ap2;
					}
				}
			}
			else {
				//다른 ap
				battery_a += board[ax][ay][size1 - 1].p;
				battery_b += board[bx][by][size2 - 1].p;
			}
		}
		cout << "#" << test_case << " " << battery_a + battery_b << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}