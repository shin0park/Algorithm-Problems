//¦���� �����ϱ�
//ȿ���� ���� �ڵ� 23��
// string erase�Ҷ� s.erase(����index, ���﹮�ڰ���)��
//������ ���ö����� ����� �׷������� ������ ȿ���� ��
#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
	int answer = 0;
	char tmp;
	for (int i = 0; i < s.length(); i++) {
		if (s.empty())
			return 1;
		if (i == 0) {
			tmp = s[0];
			continue;
		}
		if (s[i] == tmp) {
			;
			s.erase(i - 1, 2);
			i = -1;
		}
		else
			tmp = s[i];
	}
	if (s.empty())
		return 1;
	return answer;
}
//ȿ���� ���� 13��
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (i == 0 || st.empty()) {
			st.push(s[i]);
			continue;
		}
		if (!st.empty() && st.top() != s[i]) {
			st.push(s[i]);
		}
		else if (!st.empty() && st.top() == s[i])
			st.pop();
	}
	if (st.empty())
		return 1;
	return answer;
}
//Ǯ�̺��� �� �� ������ �ڵ�
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (st.empty() || st.top() != s[i]) {
			st.push(s[i]);

		}
		else
			st.pop();
	}
	if (st.empty())
		return 1;
	return answer;
}