//2504번 괄호의 값
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	stack<char> s;
	vector<int> value;
	int temp = 0;
	int result = 0;
	bool isVaild = true;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(' || input[i] == '[') {
			s.push(input[i]);
			if (input[i] == '(')
				value.push_back(2);
			else
				value.push_back(3);
		}
		else if (input[i] == ')') {
			if (s.empty() || s.top() != '(') {
				isVaild = false;
				break;
			}
			s.pop();
			value.pop_back();
			if (input[i - 1] == '[' || input[i - 1] == '(') {
				temp = 2;
				for (int j = 0; j < value.size(); j++) {
					temp *= value[j];
				}
				result += temp;
			}
		}
		else if (input[i] == ']') {
			if (s.empty() || s.top() != '[') {
				isVaild = false;
				break;
			}
			s.pop();
			value.pop_back();
			if (input[i - 1] == '[' || input[i - 1] == '(') {
				temp = 3;
				for (int j = 0; j < value.size(); j++) {
					temp *= value[j];
				}
				result += temp;
			}
		}
	}
	if (!s.empty())
		isVaild = false;
	if (!isVaild)
		cout << 0;
	else
		cout << result;

	return 0;
}