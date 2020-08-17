//가장 큰수
//답 봄
//실제 정수로 앞자리비교 그다음자리 비교보다
//스트링으로 합쳐서 비교하는게 훨씬 간단하다
// 스트링 자체를 비교하면 숫자 크기로 비교가능하다

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string n1, string n2) {
	return n1 + n2 > n2 + n1;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> s_numbers;
	for (auto n : numbers) {
		s_numbers.push_back(to_string(n));
	}
	sort(s_numbers.begin(), s_numbers.end(), cmp);
	if (s_numbers[0] == "0") return "0";
	for (auto s : s_numbers) {
		answer += s;
	}
	return answer;
}