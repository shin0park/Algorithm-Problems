//미세먼지
#include <iostream>

#include <vector>

using namespace std;
const int MAX = 51;
int board[MAX][MAX];
int tmp[MAX][MAX];
int r, c, T;
vector<pair<int, int>> air;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
void moving2(int x, int y) {//아래로 
	//오
	int temp = board[x][c - 1];
	for (int i = c - 1; i > 1; i--) {
		board[x][i] = board[x][i - 1];
	}
	board[x][1] = 0;
	//아
	int temp2 = board[r - 1][c - 1];
	for (int i = r - 1; i > x+1; i--) {
		board[i][c-1] = board[i - 1][c-1];
	}
	board[x+1][c-1] = temp;
	//왼
	int temp3 = board[r-1][0];
	for (int i = 0; i < c - 2; i++) {
		board[r-1][i] = board[r-1][i + 1];
	}
	board[r-1][c - 2] = temp2;
	//업
	for (int i = x+1; i < r-2; i++) {
		board[i][0] = board[i + 1][0];
	}
	board[r-2][0] = temp3;

}
void moving(int x,int y) {//위로
	//오
	int temp = board[x][c - 1];
	for (int i = c - 1; i > 1; i--) {
		board[x][i] = board[x][i - 1];
	}
	board[x][1] = 0;
	//업
	int temp2 = board[0][c-1];
	for (int i = 0; i < x-1; i++) {
		board[i][c-1] = board[i+1][c-1];
	}
	board[x - 1][c-1] = temp;
	//왼
	int temp3 = board[0][0];
	for (int i = 0; i < c - 2; i++) {
		board[0][i] = board[0][i+1];
	}
	board[0][c - 2] = temp2;
	//아
	for (int i = x-1; i > 1; i--) {
		board[i][0] = board[i-1][0];
	}
	board[1][0] = temp3;
}
int main() {
	cin >> r >> c >> T;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1)//공기 청정기
				air.push_back({ i,j });
		}
	}
	int nx, ny;
	int curAmount = 0, spread = 0;
	for (int tt = 0; tt < T; tt++) {
		//확산 시작
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				tmp[i][j] = board[i][j];//초기상태 tmp에 저장
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (tmp[i][j] == 0 || tmp[i][j] == -1)
					continue;
				//미세먼지
				curAmount = tmp[i][j];
				spread = curAmount / 5;
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					nx = i + dx[dir];
					ny = j + dy[dir];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c || tmp[nx][ny] == -1)//칸아니거나 공기청정기는 확산 안됨
						continue;
					cnt++;
					board[nx][ny] += spread;
				}
				board[i][j] -= spread * cnt; //퍼진만큼 감소
			}
		}
		moving(air[0].first, air[0].second);
		moving2(air[1].first, air[1].second);
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == -1)
				continue;
			ans += board[i][j];
		}
	}
	cout << ans;
	return 0;
}
