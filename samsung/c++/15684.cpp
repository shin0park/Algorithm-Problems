//��ٸ�����
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 32;
int board[MAX][12];
int tmp[MAX][12];
int n, m, h;
int num = 1;
bool isVaild;
pair<int, int> arr[4];
bool simulation() {
	int curN;
	int nextN;
	for (int i = 1; i <= n; i++) {//���μ�
		curN = i;
		for (int j = 1; j <= h; j++) {//���μ�
			nextN = curN - 1;
			if (nextN > 0 && board[j][nextN] == 1){//���ʿ� ��ٸ�
				curN = nextN;
				continue;
			}
			nextN = curN;
			if (nextN < n && board[j][nextN] == 1) {//�����ʿ� ��ٸ�
				curN = nextN + 1;
			}
		}
		if (curN != i) {
			return false;
		}
	}
	return true;
}
void getResult(int inx) {
	if (isVaild)
		return;
	if (inx >= num) {
		bool result;
		for (int i = 0; i < num; i++) {
			board[arr[i].first][arr[i].second] = 1;
		}
		result = simulation();
		if (result) {
			isVaild = true;
		}
		for (int i = 0; i < num; i++) {
			board[arr[i].first][arr[i].second] = 0;
		}
		return;
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (board[i][j] == 1 || board[i][j] == 2 )//�̹� �������� �ִ°��� ����
				continue;
			if (inx == 0
				|| (arr[inx - 1].first == i && arr[inx - 1].second < j)
				|| (arr[inx - 1].first < i)) {
				arr[inx].first = i;
				arr[inx].second = j;
				getResult(inx + 1);
			}
		}
	}
}
int main() {
	cin >> n >> m >> h;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		board[a][b] = 1;
		tmp[a][b] = 1;
	}
	if (m == 0) {
		cout << 0;
		return 0;
	}
	if (simulation()) {
		cout << 0;
		return 0;
	}
	int ny;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (tmp[i][j] == 1) {//������ ���� �翷�� �߰��Ҽ� ����
				ny = j + 1;
				if (ny < n)
					board[i][ny] = 2;
				ny = j - 1;
				if (ny > 0)
					board[i][ny] = 2;
			}
		}
	}
	for (int i = 1; i <= 3; i++) {
		num = i;
		getResult(0);
		if (isVaild) {
			cout << num;
			return 0;
		}
	}
	if (!isVaild)
		cout << -1;
	return 0;
}