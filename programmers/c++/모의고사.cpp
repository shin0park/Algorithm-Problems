//모의고사
//33분
//%= 조심히 사용하기 = 있으면 그값자체가 변하는 거 조심!! 실수 노노

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int one[] = { 1,2,3,4,5 };
	int two[] = { 2,1,2,3,2,4,2,5 };
	int three[] = { 3,3,1,1,2,2,4,4,5,5 };
	int n1 = 5;
	int n2 = 8;
	int n3 = 10;
	int score[3] = { 0,0,0 };
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == one[i % n1])
			score[0]++;
		if (answers[i] == two[i % n2])
			score[1]++;
		if (answers[i] == three[i % n3])
			score[2]++;
	}
	int max_score = 0;
	for (int i = 0; i < 3; i++)
		max_score = max(max_score, score[i]);
	for (int i = 0; i < 3; i++) {
		if (max_score == score[i])
			answer.push_back(i + 1);
	}
	return answer;
}