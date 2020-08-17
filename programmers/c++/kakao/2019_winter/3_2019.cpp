//불량 사용자
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 9;
bool check[MAX];
vector<int> ava[MAX];
vector<vector<int>> all;
int arr[MAX];
void getResult(int inx, int end) {
	if (inx > end) {
		vector<int> result;
		for (int i = 1; i <= end; i++) {
			result.push_back(arr[i]);
		}
		sort(result.begin(), result.end());
		bool isVaild = false;
		bool same = true;
		for (auto a : all) {
			same = true;
			for (int i = 0; i < result.size(); i++) {
				if (result[i] != a[i])
					same = false;
			}
			if (same) {
				isVaild = true;
				break;
			}
		}
		if (all.size() == 0 || !isVaild)
			all.push_back(result);
		return;
	}
	for (int i = 0; i < ava[inx].size(); i++) {
		int num = ava[inx][i];
		if (!check[num]) {
			arr[inx] = num;
			check[num] = true;
			getResult(inx + 1, end);
			check[num] = false;
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	for (int b = 0; b < banned_id.size(); b++) {
		for (int u = 0; u < user_id.size(); u++) {
			bool isVaild = true;
			if (banned_id[b].size() != user_id[u].size())
				continue;
			for (int i = 0; i < banned_id[b].size(); i++) {
				if (banned_id[b][i] == '*')
					continue;
				if (banned_id[b][i] != user_id[u][i]) {
					isVaild = false;
					break;
				}
			}
			if (isVaild) {
				ava[b + 1].push_back(u + 1);
			}
		}
	}

	getResult(1, banned_id.size());

	answer = all.size();
	return answer;
}

int main() {
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
	int ans = solution(user_id, banned_id);
	cout << ans;
	return 0;
}