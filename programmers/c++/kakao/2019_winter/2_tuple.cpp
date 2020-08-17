//Æ©ÇÃ
#include<iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int MAX = 501;
bool check[100001];
vector<int> solution(string s) {
	vector<int> answer;
	vector<int> input[MAX];
	vector<int> v;

	int len = 0;
	int size;
	string tmp;
	for (int i = 0; i < s.size()-1; i++) {
		if (isdigit(s[i])) {
			tmp += s[i];
		}
		if (s[i] == ',' && s[i-1] != '}') {
			v.push_back(stoi(tmp));
			tmp.clear();
		}
		if (s[i] == '}') {
			v.push_back(stoi(tmp));
			tmp.clear();
			size = (int)v.size();
			len = max(len, size);
			input[size] = v;
			v.clear();
		}
	}
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j < input[i].size(); j++) {
			if (!check[input[i][j]]) {
				answer.push_back(input[i][j]);
				check[input[i][j]] = true;
			}
		}
	}
	return answer;
}
int main() {
	string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	vector<int> ans = solution(s);
	cout << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}