#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

int arr[3];// +:0, -:1, *:2
bool selected[3];
deque<long long> q;
deque<long long> start_q;
long long result = 0;
void getResult(int inx, int operator_num) {
	if (inx >= operator_num) {
		q = start_q;
		for (int i = 0; i < operator_num; i++) {
			deque<long long> tmp_q;
			while (!q.empty()) {
				if (q.size() == 1)
				{
					tmp_q.push_back(q.front());
					q.pop_back();
					break;
				}
				long long fir = q.front();
				q.pop_front();
				long long oper = q.front();
				q.pop_front();
				if (oper == arr[i]) {
					long long se = q.front();
					if (oper == 0)
						fir += se;
					else if (oper == 1)
						fir -= se;
					else
						fir *= se;
					q.pop_front();
					q.push_front(fir);
				}
				else {
					tmp_q.push_back(fir);
					tmp_q.push_back(oper);
				}
			}
			q = tmp_q;

		}

		long long tmp_result = abs(q.front());
		q.pop_back();
		result = max(result, tmp_result);
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (!selected[i]) {
			arr[inx] = i;
			selected[i] = true;
			getResult(inx + 1, operator_num);
			selected[i] = false;
		}
	}
}
long long solution(string expression) {
	long long answer = 0;
	string s_num;
	int tmp;
	for (int i = 0; i < expression.size(); i++) {
		if (isdigit(expression[i]))
			s_num += expression[i];
		else {
			tmp = stoi(s_num);
			q.push_back(tmp);
			s_num.clear();
			if (expression[i] == '+') {
				q.push_back(0);
			}
			else if (expression[i] == '-') {
				q.push_back(1);
			}
			else {
				q.push_back(2);
			}
		}
		if (i == expression.size() - 1) {
			tmp = stoi(s_num);
			q.push_back(tmp);
			s_num.clear();
		}
	}
	start_q = q;
	getResult(0, 3);
	answer = result;
	return answer;
}

int main() {
	string expression = "50*6-3*2";
	long long ans = solution(expression);
	cout << ans;
	return 0;
}