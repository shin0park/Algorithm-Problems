//원판돌리기
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 51;
int board[MAX][MAX];
bool check[MAX][MAX];
int n, m, T;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
void rotation(int x, int dir, int k) {
	if (dir == 0) {//시계
		while (k--) {
			int tmp = board[x][m - 1];
			for (int j = m - 1; j > 0; j--) {
				board[x][j] = board[x][j - 1];
			}
			board[x][0] = tmp;
		}
	}
	else {//반시계
		while (k--) {
			int tmp = board[x][0];
			for (int j = 0; j < m - 1; j++) {
				board[x][j] = board[x][j + 1];
			}
			board[x][m - 1] = tmp;
		}
	}
}
int main() {
	cin >> n >> m >> T;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int tt = 0; tt < T; tt++) {
		int x, d, k;
		cin >> x >> d >> k;
		//회전
		for (int i = 0; i < n; i++) {
			if ((i + 1) % x == 0) {
				rotation(i, d, k);
			}
		}
		//지우기
		int nx, ny;
		bool isVaild = false;
		bool flag = false; //한번도 인접한게 나타난적 있는가
		fill(check[0], check[0] + MAX * MAX, false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0)
					continue;
				for (int dir = 0; dir < 4; dir++) {
					nx = i + dx[dir];
					ny = j + dy[dir];
					if (nx < 0 || nx >= n)
						continue;
					if (ny < 0 || ny >= m) {
						if (ny == -1)
							ny = m - 1;
						if (ny == m)
							ny = 0;
					}
					if (board[i][j] == board[nx][ny]) {// 인접한게 있을때
						check[nx][ny] = true;
						isVaild = true;
						flag = true;
					}	
				}
				if (isVaild) 
					check[i][j] = true;
				isVaild = false;
			}
		}
		if (flag) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (check[i][j])
						board[i][j] = 0;
				}
			}
		}
		else {//인접한게 없었던 경우
			int sum = 0, num = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (board[i][j] == 0)
						continue;
					sum += board[i][j];
					num++;
				}
			}
			float avg = (float)sum / num;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (board[i][j] == 0)
						continue;
					if ((float)board[i][j] > avg) {
						board[i][j] -= 1;
					}
					else if ((float)board[i][j] < avg) {
						board[i][j] += 1;
					}
				}
			}
		}
	}
	int ans = 0;
	//다 돌린 이후
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += board[i][j];
		}
	}
	cout << ans;
	return 0;
}