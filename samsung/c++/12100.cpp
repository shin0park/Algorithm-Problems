//2048
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 21;
int board[MAX][MAX];
int tmp[MAX][MAX];
int n;
int myMax = -987987987;
int arr[5];
void moving(int dir) {
	if (dir == 0) {//À§
		for (int c = 0; c < n; c++) {
			queue<int> q;
			for (int r = 0; r < n; r++) {
				if (board[r][c] == 0)
					continue;
				q.push(board[r][c]);
			}
			queue<int> nextQ;
			int fir, se;
			while (!q.empty())
			{
				if (q.size() == 1) {
					nextQ.push(q.front());
					break;
				}
				fir = q.front();
				q.pop();
				se = q.front();
				if (fir == se) {
					nextQ.push(fir * 2);
					q.pop();
				}
				else {
					nextQ.push(fir);
				}
			}
			for (int r = 0; r < n; r++) {
				if (!nextQ.empty()) {
					board[r][c] = nextQ.front();
					nextQ.pop();
				}
				else {
					board[r][c] = 0;
				}
			}
		}

	}
	else if (dir == 1) {//¿À
		for (int r = 0; r < n; r++) {
			queue<int> q;
			for (int c = n - 1; c >= 0; c--) {
				if (board[r][c] == 0)
					continue;
				q.push(board[r][c]);
			}
			queue<int> nextQ;
			int fir, se;
			while (!q.empty())
			{
				if (q.size() == 1) {
					nextQ.push(q.front());
					break;
				}
				fir = q.front();
				q.pop();
				se = q.front();
				if (fir == se) {
					nextQ.push(fir * 2);
					q.pop();
				}
				else {
					nextQ.push(fir);
				}
			}
			for (int c = n - 1; c >= 0; c--) {
				if (!nextQ.empty()) {
					board[r][c] = nextQ.front();
					nextQ.pop();
				}
				else {
					board[r][c] = 0;
				}
			}
		}
	}
	else if (dir == 2) {//¾Æ·¡
		for (int c = 0; c < n; c++) {
			queue<int> q;
			for (int r = n-1 ; r >= 0; r--) {
				if (board[r][c] == 0)
					continue;
				q.push(board[r][c]);
			}
			queue<int> nextQ;
			int fir, se;
			while (!q.empty())
			{
				if (q.size() == 1) {
					nextQ.push(q.front());
					break;
				}
				fir = q.front();
				q.pop();
				se = q.front();
				if (fir == se) {
					nextQ.push(fir * 2);
					q.pop();
				}
				else {
					nextQ.push(fir);
				}
			}
			for (int r = n - 1; r >= 0; r--) {
				if (!nextQ.empty()) {
					board[r][c] = nextQ.front();
					nextQ.pop();
				}
				else {
					board[r][c] = 0;
				}
			}
		}
	}
	else if (dir == 3) {//¿Þ
		for (int r = 0; r < n; r++) {
			queue<int> q;
			for (int c = 0; c < n; c++) {
				if (board[r][c] == 0)
					continue;
				q.push(board[r][c]);
			}
			queue<int> nextQ;
			int fir, se;
			while (!q.empty())
			{
				if (q.size() == 1) {
					nextQ.push(q.front());
					break;
				}
				fir = q.front();
				q.pop();
				se = q.front();
				if (fir == se) {
					nextQ.push(fir * 2);
					q.pop();
				}
				else {
					nextQ.push(fir);
				}
			}
			for (int c = 0; c < n; c++) {
				if (!nextQ.empty()) {
					board[r][c] = nextQ.front();
					nextQ.pop();
				}
				else {
					board[r][c] = 0;
				}
			}
		}
	}
}
void getResult(int inx) {
	if (inx >= 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = tmp[i][j];
			}
		}
		for (int i = 0; i < 5; i++) {
			moving(arr[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0)
					continue;
				myMax = max(myMax, board[i][j]);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		arr[inx] = i;
		getResult(inx + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			tmp[i][j] = board[i][j];
		}
	}
	getResult(0);
	cout << myMax;
	return 0;
}