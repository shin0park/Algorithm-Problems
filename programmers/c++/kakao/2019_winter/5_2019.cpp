//징검다리 건너기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200001;
bool check[MAX];
int group_num[MAX];
struct STONE
{
	int num, index;
};
bool cmp(STONE a, STONE b) {
	return a.num < b.num;
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	int cnt = 0;
	vector<STONE> tmp;
	vector<vector<STONE>> sorted;
	for (int i = 0; i < stones.size(); i++) {
		STONE s = { stones[i],i };
		tmp.push_back(s);
	}
	sort(tmp.begin(), tmp.end(), cmp);
	vector<STONE> v;
	for (int s = 0; s < tmp.size(); s++) {
		v.push_back(tmp[s]);
		if (s == tmp.size() - 1 || (tmp[s + 1].num != tmp[s].num)) {
			sorted.push_back(v);
			v.clear();
		}
	}
	for (int t = 0; t < sorted.size(); t++) {
		for (auto s : sorted[t]) {
			int i = s.index;
			check[i] = true;
			group_num[i]++;
		}
		answer = sorted[t][0].num;
		for (auto s : sorted[t]) {
			int i = s.index;
			if (i != 0 && check[i - 1]) {
				group_num[i] += group_num[i - 1];
				group_num[i - 1] = group_num[i];
			}
			if (i != (stones.size() - 1) && check[i + 1]) {
				group_num[i] += group_num[i + 1];
				group_num[i + 1] = group_num[i];
			}
			if (i != 0 && check[i - 1] && i != (stones.size() - 1) && check[i + 1])
				group_num[i - 1] = group_num[i];
			cnt = max(cnt, group_num[i]);
		}
		if (k <= cnt)
			break;
	}
	return answer;
}
int main() {
	vector<int> stones = { 2, 5, 5, 3, 2, 1, 5, 2, 5, 1 };
	int k = 4;
	int answer = solution(stones, k);
	cout << answer;
	return 0;
}