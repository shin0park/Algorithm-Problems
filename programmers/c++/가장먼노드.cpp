//가장 먼 노드
//bfs로 품
//최단거리 구할때
//check는 queue에 push할때
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 20001;
int dist[MAX];
bool check[MAX];
vector<int> graph[MAX];
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int maxLen = 0;
	queue<int> q;
	for (auto e : edge) {
		graph[e[0]].push_back(e[1]);
		graph[e[1]].push_back(e[0]);
	}
	q.push(1);
	dist[1] = 0;
	check[1] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		vector<int> tmp = graph[node];
		for (int i = 0; i < tmp.size(); i++) {
			if (check[tmp[i]])
				continue;
			dist[tmp[i]] = dist[node] + 1;
			maxLen = max(maxLen, dist[tmp[i]]);
			check[tmp[i]] = true;
			q.push(tmp[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == maxLen)
			answer++;
	}
	return answer;
}
int main() {
	int n = 6;
	vector<vector<int>> edge = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };
	int ans = solution(n, edge);
	cout << ans;
	return 0;
}