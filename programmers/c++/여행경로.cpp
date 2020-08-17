#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int k, string start, vector<vector<string>>& tickets, vector<string>& answer, vector<bool>& isUsed) {
	answer.push_back(start);

	if (k == tickets.size())
		return true;
	for (int i = 0; i < tickets.size(); i++) {
		if (!isUsed[i] && start == tickets[i][0]) {
			isUsed[i] = true;
			bool result = dfs(k + 1, tickets[i][1], tickets, answer, isUsed);
			if (result)
				return true;
			isUsed[i] = false;
		}
	}
	answer.pop_back();
	return false;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> isUsed(tickets.size(), false);

	sort(tickets.begin(), tickets.end());
	dfs(0, "ICN", tickets, answer, isUsed);

	return answer;
}
int main() {
	vector<vector<string>> tickets = { {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} };
	vector<string> ans = solution(tickets);
	for (auto a : ans) {
		cout << a << " ";
	}
	return 0;
}