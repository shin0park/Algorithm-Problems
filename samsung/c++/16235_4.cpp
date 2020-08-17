//나무 재테크
//vector로 풀기
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
typedef pair<pair<int, int>, int> pp;
vector<pp> plant[2];
vector<pp> die_tree, new_tree, birth_tree;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> given[i][j];
			board[i][j] = 5;
		}
	}
	int cur = 0, next = 0;
	int x, y, age, nx, ny;
	vector<pp> init_tree;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> age;
		init_tree.push_back({ {x,y }, age });
	}
	sort(init_tree.begin(), init_tree.end());
	for (pp e : init_tree) {
		plant[cur].push_back(e);
	}

	while (k--)
	{
		//spring
		next = (cur + 1) % 2;
		plant[next].clear();
		birth_tree.clear();
		die_tree.clear();
		for (pp e : new_tree) {
			x = e.first.first;
			y = e.first.second;
			age = e.second;
			if (age <= board[x][y])
			{
				board[x][y] -= age;
				plant[next].push_back({ {x,y},++age });
				if (age % 5 == 0) {
					for (int i = 0; i < 8; i++)
					{
						nx = x + dx[i];
						ny = y + dy[i];
						if (nx <= 0 || nx > n || ny <= 0 || ny > n)
							continue;
						birth_tree.push_back({ {nx, ny}, 1 });
					}
				}
			}
			else
				die_tree.push_back({ {x,y},age });
		}
		new_tree.clear();
		for (pp e : plant[cur]) {
			x = e.first.first;
			y = e.first.second;
			age = e.second;
			if (age <= board[x][y])
			{
				board[x][y] -= age;
				plant[next].push_back({ {x,y},++age });
				if (age % 5 == 0) {
					for (int i = 0; i < 8; i++)
					{
						nx = x + dx[i];
						ny = y + dy[i];
						if (nx <= 0 || nx > n || ny <= 0 || ny > n)
							continue;
						birth_tree.push_back({ {nx, ny}, 1 });
					}
				}
			}
			else
				die_tree.push_back({ {x,y},age });
		}
		//summer
		for (pp e : die_tree) {
			x = e.first.first;
			y = e.first.second;
			board[x][y] += (e.second / 2);
		}
		//fall
		for (pp e : birth_tree) {
			new_tree.push_back(e);
		}
		//winter
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				board[i][j] += given[i][j];
			}
		}
		cur = next;
	}
	cout << plant[next].size() + new_tree.size();
	return 0;
}