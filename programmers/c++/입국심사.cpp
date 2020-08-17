//�̺�Ž��
//Ʋ��
//�̺�Ž���� ������ ���ذ� �����ߴ��Ͱ���
//���ü� �ִ� ���� �ּҿ� �ִ븦 �����Ͽ� ���� ������ ����������
//���� �������ߴ� ����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long minTime = 1, avgTime, maxTime, num = 0;
	maxTime = *max_element(times.begin(), times.end()) * (long long)n;
	while (minTime <= maxTime) {
		avgTime = (minTime + maxTime) / 2;
		for (auto time : times) {
			num += avgTime / time;
		}
		if (n <= num) {
			answer = avgTime;
			maxTime = avgTime - 1;
		}
		else {
			minTime = avgTime + 1;
		}
		num = 0;
	}
	return answer;
}
int main() {
	int n = 6;
	vector<int> times = { 7,10 };
	long long ans = solution(n,times);
	cout << ans;
	return 0;
}