//체육복
// 뭘먼저 하는게 더 효율적인지 꼭생각하기
//16분
#include <string>
#include <vector>

using namespace std;
int check[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	answer = n - lost.size();
	for (auto r : reserve) {
		for (auto l : lost) {
			if (check[l])
				continue;
			if (r == l) {
				answer++;
				check[l] = true;
				break;
			}
		}
	}
	for (auto r : reserve) {
		if (check[r])
			continue;
		for (auto l : lost) {
			if (check[l])
				continue;
			if (r - 1 == l || r + 1 == l) {
				answer++;
				check[l] = true;
				break;
			}
		}
	}
	return answer;
}

//다른사람 코드

#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	//총 인원수만큼 벡터를 생성하고 체육복갯수 1로 설정
	vector<int> check(n, 1);
	//체육복을 잃어버린 사람은 1개 마이너스
	for (auto l : lost)        check[l - 1]--;
	//체육복을 여분으로 가져왔다면 1개 플러스
	for (auto r : reserve)        check[r - 1]++;
	//처음부터 돌면서 순회하기
	for (size_t i = 0; i < check.size(); i++) {
		//체육복이 0개라면
		if (!check[i]) {
			//앞의 사람이 여분이 있나 확인하고 있다면 빌리기
			if (i != check.size() - 1 && check[i + 1] == 2) {
				check[i + 1]--;
				check[i]++;
			}
			//뒤에 사람이 여분이 있나 확인하고 있다면 빌리기
			else if (i && check[i - 1] == 2) {
				check[i - 1]--;
				check[i]++;
			}
		}
	}
	//체육복이 몇명이 있나 체크하기
	for (auto a : check)
		if (a != 0)    answer++;
	return answer;
}