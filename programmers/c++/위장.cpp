//¿ß¿Â
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int clothe_sum = 0;

	for (auto clothe : clothes) {
		++m[clothe[1]];
	}
	for (auto mm : m) {
		answer *= (mm.second + 1);
	}
	answer--;
	return answer;
}
int main() {
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } };
	int ans = solution(clothes);
	cout << ans;
	return 0;
}