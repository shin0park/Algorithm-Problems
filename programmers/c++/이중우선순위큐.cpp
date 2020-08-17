//이중우선순위큐
//priority_queue 를 두개 써서 하는 로직은 잘못 된것같다.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I') {
			string num = operations[i].substr(2);
			int number = stoi(num);
			max_pq.push(number);
			min_pq.push(number);
		}
		else {
			if (operations[i][2] == '1') {//최대
				if (!max_pq.empty())
					max_pq.pop();
			}
			else {
				if (!min_pq.empty())
					min_pq.pop();
			}
		}
	}
	if (max_pq.empty() || min_pq.empty() || (max_pq.top() < min_pq.top())) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (max_pq.top() == min_pq.top()) {
		answer.push_back(max_pq.top());
		answer.push_back(max_pq.top());
	}
	else {
		answer.push_back(max_pq.top());
		answer.push_back(min_pq.top());
	}
	return answer;
}
int main() {
	vector<string> operations = { "I 7", "I 5", "I -5", "D -1" };
	vector<int> ans = solution(operations);
	return 0;
}

//다른 코드
//deque로 풀기
//deque도 sort할 수 있다
//queue도 sort할 수 있을까?

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> dq;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I') {
			string num = operations[i].substr(2);
			int number = stoi(num);
			dq.push_back(number);
			sort(dq.begin(), dq.end());
		}
		else {
			if (operations[i][2] == '1') {//최대
				if (!dq.empty())
					dq.pop_back();
			}
			else {
				if (!dq.empty())
					dq.pop_front();
			}
		}
	}
	if (dq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(dq.back());
		answer.push_back(dq.front());
	}
	return answer;
}