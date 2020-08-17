//짝지어 제거하기
//효율성 실패 코드 23분
// string erase할때 s.erase(시작index, 지울문자개수)임
//같은거 나올때마다 지우고 그런로직은 스택이 효율성 갑
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
//효율성 성공 13분
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
//풀이보고 한 더 간략한 코드
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