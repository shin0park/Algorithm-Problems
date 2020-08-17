//�� �ʰ�
//9��
//���� ���� �� üũ�ؼ� ���б�
//��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return �մϴ�
//���� ���� ���� ���� �Ѥ�;; �����ϱ�
//priority_queue 
//vector�� array�� sort�� ��� ������ ��ƴ�.
// priority_queue�� ���� ������ ���� queue�ε� �ּ� �ִ밪�� �������ִ�
// �ִ� �ּ� �ʿ��ѵ� ���� ���� ���� �ؾߵ� ��� �����ϴ�.
//Ȯ���� 1 ���� ������ nlogn
//�켱���� ť�� �⺻�� max
//min���� �Ϸ��� priority_queue<int, vector<int>, greater<int>> pq;
//�ϰų� �ƴ� priority_queue<int> pq; pq.push(-a); b = -pq.top(); -�� �ٿ��� �ְ� -�ٿ��� ����.
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
//������ �ڵ�
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
			return -1;// �Ұ����Ҷ� �׳� -1�� �����ϸ�ȴ� true false�� ���ʿ䰡 ����
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

//�ٸ���� �ڵ�
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
		pq.push({ -scoville[i] }); //������ ���� �ִ´�.
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