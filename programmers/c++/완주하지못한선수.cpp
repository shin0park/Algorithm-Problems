//완주하지 못한 선수
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> m;
	for (auto part : participant) {
		m[part]++;
	}
	for (auto complet : completion) {
		m[complet]--;
	}
	for (auto part : participant) {
		if (m[part] > 0)
			return part;
	}
	return answer;
}
int main() {
	vector<string> participant = { "leo", "kiki", "eden" };
	vector<string> completion={ "kiki", "eden" };
	string ans = solution(participant, completion);
	cout << ans;
	return 0;
}