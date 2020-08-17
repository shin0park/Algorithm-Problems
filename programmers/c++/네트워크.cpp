#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 201;
bool visited[MAX];

void dfs(int start, int n, vector<vector<int>> computers) {
	visited[start] = true;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && computers[start][i])
			dfs(i, n, computers);
	}
	return;
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, n, computers);
			answer++;
		}
	}

	return answer;
}