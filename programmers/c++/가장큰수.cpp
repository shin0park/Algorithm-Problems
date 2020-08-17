//���� ū��
//�� ��
//���� ������ ���ڸ��� �״����ڸ� �񱳺���
//��Ʈ������ ���ļ� ���ϴ°� �ξ� �����ϴ�
// ��Ʈ�� ��ü�� ���ϸ� ���� ũ��� �񱳰����ϴ�

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