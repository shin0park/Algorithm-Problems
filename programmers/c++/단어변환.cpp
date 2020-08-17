//단어변환
//dfs로 품
//37분

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[51];
int diff = 0;
int minValue = 987987987;
void dfs(int cnt, string word, vector<string> words, string target) {
	if (word == target) {
		minValue = min(minValue, cnt);
		return;
	}
	for (int j = 0; j < words.size(); j++) {
		if (check[j])
			continue;
		diff = 0;
		for (int i = 0; i < words[j].length(); i++) {
			if (word[i] != words[j][i])
				diff++;
		}
		if (diff == 1) {
			check[j] = true;
			dfs(cnt + 1, words[j], words, target);
			check[j] = false;
		}
	}
	return;
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	dfs(0, begin, words, target);
	if (minValue == 987987987)
		answer = 0;
	else
		answer = minValue;
	return answer;
}