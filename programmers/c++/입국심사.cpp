//이분탐색
//틀림
//이분탐색의 원리의 이해가 부족했던것같다
//나올수 있는 답의 최소와 최대를 설정하여 답의 범위를 좁혀나간다
//답을 끼워맞추는 느낌
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