//구슬탈출2
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 11;
int n, m;
string board[MAX];
int arr[10];
int myMin = 987987987;
bool isVaild = false;
pair<int, int> red, blue;
int run(int dir) {
	if (dir == 0) {//왼쪽
		for (int i = 0; i < n; i++) {
			bool end = false;
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'R' || board[i][j] == 'B') {
					char color = board[i][j];
					board[i][j] = '.';
					for (int k = j; k >= 0; k--) {
						if (board[i][k] != '.' && board[i][k] != 'O') {
							board[i][k + 1] = color;
							if (color == 'R')
								red = { i, k + 1 };
							else
								blue = { i, k + 1 };
							break;
						}
						else if (board[i][k] == 'O') {
							if (color == 'R') {
								end = true;
								break;
							}
							else
								return 2;
						}
					}
				}
			}
			if (end)
				return 1;
		}
	}
	else if (dir == 1) {//오른쪽
		for (int i = 0; i < n; i++) {
			bool end = false;
			for (int j = m - 1; j >= 0; j--) {
				if (board[i][j] == 'R' || board[i][j] == 'B') {
					char color = board[i][j];
					board[i][j] = '.';
					for (int k = j; k < m; k++) {
						if (board[i][k] != '.' && board[i][k] != 'O') {
							board[i][k - 1] = color;
							if (color == 'R')
								red = { i, k - 1 };
							else
								blue = { i, k - 1 };
							break;
						}
						else if (board[i][k] == 'O') {
							if (color == 'R') {
								end = true;
								break;
							}
							else
								return 2;
						}
					}
				}
			}
			if (end)
				return 1;
		}
	}
	else if (dir == 2) {//위
		for (int j = 0; j < m; j++) {
			bool end = false;
			for (int i = 0; i < n; i++) {
				if (board[i][j] == 'R' || board[i][j] == 'B') {
					char color = board[i][j];
					board[i][j] = '.';
					for (int k = i; k >= 0; k--) {
						if (board[k][j] != '.' && board[k][j] != 'O') {
							board[k + 1][j] = color;
							if (color == 'R')
								red = { k + 1, j };
							else
								blue = { k + 1, j };
							break;
						}
						else if (board[k][j] == 'O') {
							if (color == 'R') {
								end = true;
								break;
							}
							else
								return 2;
						}
					}
				}
			}
			if (end)
				return 1;
		}
	}
	else if (dir == 3) {
		for (int j = 0; j < m; j++) {
			bool end = false;
			for (int i = n - 1; i >= 0; i--) {
				if (board[i][j] == 'R' || board[i][j] == 'B') {
					char color = board[i][j];
					board[i][j] = '.';
					for (int k = i; k < n; k++) {
						if (board[k][j] != '.' && board[k][j] != 'O') {
							board[k - 1][j] = color;
							if (color == 'R')
								red = { k - 1, j };
							else
								blue = { k - 1, j };
							break;
						}
						else if (board[k][j] == 'O') {
							if (color == 'R') {
								end = true;
								break;
							}
							else
								return 2;
						}
					}
				}
			}
			if (end)
				return 1;
		}
	}
	return 0;
}
void getResult(int inx) {
	if (inx >= 10) {
		return;
	}
	string tmp[MAX];
	for (int i = 0; i < n; i++) {
		tmp[i] = board[i];
	}
	int result = 0;
	for (int dir = 0; dir < 4; dir++) {
		bool isSame = true;
		arr[inx] = dir;
		result = run(dir);
		if (result == 1) {//성공
			isVaild = true;
			myMin = min(myMin, (inx + 1));
			return;
		}
		else if (result == 2) {//실패
			for (int i = 0; i < n; i++) {
				board[i] = tmp[i];
			}
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (board[i] != tmp[i]) {
				isSame = false;
			}
		}
		if (isSame)
			continue;
		getResult(inx + 1);
		for (int i = 0; i < n; i++) {
			board[i] = tmp[i];
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	getResult(0);

	if (isVaild)
		cout << myMin;
	else
		cout << -1;
	return 0;
}