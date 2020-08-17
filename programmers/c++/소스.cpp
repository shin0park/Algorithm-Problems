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
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
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