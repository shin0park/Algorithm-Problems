//나무 재테크
//queue struct use
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 11;
int board[MAX][MAX];
int given[MAX][MAX];
int n, m, k;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int ans;
struct tree {
	int x, y, age;
};
queue<tree> t[2];
vector<tree> init_tree;
queue<tree> die_tree, birth_tree, new_tree;
bool cmp(tree a, tree b) {
	return a.age < b.age;
}
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
	int x, y, age;
	int cur = 0, next = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> age;
		init_tree.push_back({ x,y,age });
	}
	sort(init_tree.begin(), init_tree.end(), cmp);
	for (int i = 0; i < m; i++) {
		t[cur].push(init_tree[i]);
	}
	while (k--) {
		//spring
		next = (cur + 1) % 2;

		while (!new_tree.empty()) {
			x = new_tree.front().x;
			y = new_tree.front().y;
			age = new_tree.front().age;
			new_tree.pop();
			if (age <= board[x][y]) {
				board[x][y] -= age;
				t[next].push({ x,y,++age });
				if (age % 5 == 0) {
					birth_tree.push({ x,y,age });
				}
			}
			else
			{
				die_tree.push({ x,y,age });
			}
		}
		while (!t[cur].empty()) {
			x = t[cur].front().x;
			y = t[cur].front().y;
			age = t[cur].front().age;
			t[cur].pop();
			if (age <= board[x][y]) {
				board[x][y] -= age;
				t[next].push({ x,y,++age });
				if (age % 5 == 0) {
					birth_tree.push({ x,y,age });
				}
			}
			else
			{
				die_tree.push({ x,y,age });
			}
		}
		//summer
		while (!die_tree.empty()) {
			x = die_tree.front().x;
			y = die_tree.front().y;
			age = die_tree.front().age;
			die_tree.pop();
			board[x][y] += (age / 2);
		}
		//fall
		int nx, ny;
		while (!birth_tree.empty()) {
			x = birth_tree.front().x;
			y = birth_tree.front().y;
			age = birth_tree.front().age;
			birth_tree.pop();
			for (int cur = 0; cur < 8; cur++)
			{
				nx = x + dx[cur];
				ny = y + dy[cur];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n)
					continue;
				new_tree.push({ nx,ny,1 });
			}
		}
		//winter
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
			{
				board[i][j] += given[i][j];
			}
		}
		cur = next;
	}

	cout << t[next].size() + new_tree.size();
	return 0;
}