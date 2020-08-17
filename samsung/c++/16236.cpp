//아기상어

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 21;
int board[MAX][MAX];
int dist[MAX][MAX];
int shark_size = 2;
int n;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> n;
	pair<int, int> start;
	fill(dist[0], dist[0] + MAX * MAX, -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				start.first = i;
				start.second = j;
				board[i][j] = 0;
				dist[i][j] = 0;
			}
		}
	}
	int x, y, nx, ny;
	int size_num = 0;
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty())
	{
		int size = q.size();
		vector<pair<int, int>> v;
		for (int i = 0; i < size; i++)
		{
			v.push_back(q.front());
			q.pop();
		}
		sort(v.begin(), v.end());
		int idx = 0;
		while (size--)
		{

			x = v[idx].first;
			y = v[idx].second;
			idx++;
			if (board[x][y] != 0 && shark_size > board[x][y]) {
				size_num++;
				board[x][y] = 0;
				while (!q.empty()) q.pop();
				q.push({ x, y });
				int tmp = dist[x][y];
				fill(dist[0], dist[0] + MAX * MAX, -1);
				dist[x][y] = tmp;
				ans = dist[x][y];
				if (size_num == shark_size) {
					shark_size++;
					size_num = 0;
				}
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || n <= nx || ny < 0 || n <= ny)
					continue;
				if ((board[nx][ny] != 0 && shark_size < board[nx][ny]) || dist[nx][ny] != -1)
					continue;
				q.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	cout << ans;
	return 0;
}