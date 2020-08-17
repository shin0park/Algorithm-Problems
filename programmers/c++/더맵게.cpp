//더 맵게
//9분
//문제 조건 꼭 체크해서 잘읽기
//모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다
//위의 조건 생각 안함 ㅡㅡ;; 조심하기
//priority_queue 
//vector나 array의 sort의 경우 삭제가 어렵다.
// priority_queue는 삽입 삭제가 쉬운 queue인데 최소 최대값을 산출해주니
// 최대 최소 필요한데 삽입 삭제 많이 해야될 경우 유용하다.
//확인은 1 삽입 삭제는 nlogn
//우선순위 큐는 기본이 max
//min으로 하려면 priority_queue<int, vector<int>, greater<int>> pq;
//하거나 아님 priority_queue<int> pq; pq.push(-a); b = -pq.top(); -를 붙여서 넣고 -붙여서 뺀다.
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int t = 0;
	int fir, se, tmp = 0;
	bool isVaild = true;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto s : scoville) {
		pq.push(s);
	}
	while (++t) {
		if (pq.size() == 1) {
			isVaild = false;
			break;
		}
		fir = pq.top();
		pq.pop();
		se = pq.top();
		pq.pop();
		tmp = fir + se * 2;
		pq.push(tmp);
		if (K <= pq.top())
			break;
	}
	if (isVaild)
		answer = t;
	else
		answer = -1;
	return answer;
}
//수정한 코드
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int t = 0;
	int fir, se, tmp = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto s : scoville) {
		pq.push(s);
	}
	while (++t) {
		if (pq.size() == 1) {
			return -1;// 불가능할때 그냥 -1을 리턴하면된다 true false로 할필요가 없음
		}
		fir = pq.top();
		pq.pop();
		se = pq.top();
		pq.pop();
		tmp = fir + se * 2;
		pq.push(tmp);
		if (K <= pq.top())
			break;
	}
	answer = t;
	return answer;
}

//다른사람 코드
#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue <int> pq;

int scovile_mix(int first, int second) {
	int value = 0;
	value = first + second * 2;
	return value;
}

int solution(vector<int> scoville, int K) {
	int answer = 0;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push({ -scoville[i] }); //음수로 만들어서 넣는다.
	}

	while (1) {
		int minimum_scobil = -pq.top();
		if (minimum_scobil < K) {
			pq.pop();
			if (pq.empty()) {
				return -1;
			}

			int second_scobil = -pq.top();
			pq.pop();
			int new_scobill = scovile_mix(minimum_scobil, second_scobil);
			pq.push(-new_scobill);
			answer++;
		}
		else {
			break;
		}
	}


	return answer;
}