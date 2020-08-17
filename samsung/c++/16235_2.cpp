//나무 재테크
//이차원 배열 vector타입으로 풀기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 11;
int board[MAX][MAX];
int given[MAX][MAX];
int n, m, k;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<int> tree[MAX][MAX];
int ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> given[i][j];
			board[i][j] = 5;
		}
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		tree[a][b].push_back(c);
		ans++;
	}

	while (k--) {
		//spring
		int age;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				vector<int> tmp;
				int sum_die = 0;
				if (tree[i][j].size() == 0)
					continue;
				if (tree[i][j].size() > 1)
					sort(tree[i][j].begin(), tree[i][j].end());
				for (int k = 0; k < tree[i][j].size(); k++) {
					age = tree[i][j][k];
					if (age <= board[i][j]) {
						board[i][j] -= age;
						tmp.push_back(age + 1);
					}
					else
					{
						sum_die += (age / 2);
						ans--;
					}
				}
				//summer
				tree[i][j].clear();
				for (int k = 0; k < tmp.size(); k++) {
					tree[i][j].push_back(tmp[k]);
				}
				board[i][j] += sum_die;
			}
		}
		//fall
		int nx, ny;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (tree[i][j].size() == 0)
					continue;
				for (int k = 0; k < tree[i][j].size(); k++)
				{
					if (tree[i][j][k] % 5 == 0)
					{
						for (int cur = 0; cur < 8; cur++)
						{
							nx = i + dx[cur];
							ny = j + dy[cur];
							if (nx <= 0 || nx > n || ny <= 0 || ny > n)
								continue;
							tree[nx][ny].push_back(1);
							ans++;
						}
					}
				}
			}
		}
		//winter
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
			{
				board[i][j] += given[i][j];
			}
		}

	}

	cout << ans;
	return 0;
}