//N으로 표현
//실패
//다시한번 보기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minValue = 987987987;
void dfs(int count, int N, int number, int currentNum) {
	int nextNum = 0;
	if (number == currentNum) {
		minValue = min(minValue, count);
		return;
	}
	if (count > 8)
		return;
	for (int i = 0; i < 9; i++) {
		nextNum = nextNum * 10 + N;
		if (currentNum == 0)
			dfs(count + 1 + i, N, number, nextNum);
		else {
			dfs(count + 1 + i, N, number, currentNum + nextNum);
			dfs(count + 1 + i, N, number, currentNum - nextNum);
			dfs(count + 1 + i, N, number, currentNum * nextNum);
			dfs(count + 1 + i, N, number, currentNum / nextNum);
		}
	}
}
int solution(int N, int number) {
	int answer = 0;
	dfs(0, N, number, 0);
	if (minValue == 987987987)
		answer = -1;
	else
		answer = minValue;
	return answer;
}