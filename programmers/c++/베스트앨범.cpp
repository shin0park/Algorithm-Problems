//º£½ºÆ®¾Ù¹ü
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> sum_m;
	map<int, string, greater<int>> sum_temp_m;
	multimap<string, pair<int, int>> album;
	for (int i = 0; i < genres.size(); i++) {
		sum_m[genres[i]] += plays[i];
		album.insert({ genres[i] , {plays[i], i} });
	}
	for (auto sum : sum_m) {
		sum_temp_m[sum.second] = sum.first;
	}
	string genre;

	for (auto sum : sum_temp_m) {
		vector<pair<int, int>>tmp;
		genre = sum.second;
		auto range = album.equal_range(genre);
		for (auto it = range.first; it != range.second; it++) {
			tmp.push_back(it->second);
		}
		sort(tmp.begin(), tmp.end());
		int size = tmp.size();
		if (size <= 1) {
			answer.push_back(tmp[0].second);
		}
		else if (tmp[size - 1].first == tmp[size - 2].first) {
			answer.push_back(tmp[size - 2].second);
			answer.push_back(tmp[size - 1].second);
		}
		else {
			answer.push_back(tmp[size - 1].second);
			answer.push_back(tmp[size - 2].second);
		}
	}
	return answer;
}
int main() {
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 2500, 150, 800, 2500 };
	vector<int> ans = solution(genres, plays);
	for (auto v : ans) {
		cout << v << " ";
	}
}