//��ɰ���
//13��
//ó�� Ǭ Ǯ��
//�ε�ȣ �Ǽ� ��������
//for������ üũ�Ҷ� �������κ� ���� �غ���
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> dday;
	int day = 0;
	queue <int> q;
	for (int i = 0; i < progresses.size(); i++) {
		day = (100 - progresses[i]) / speeds[i];
		if ((100 - progresses[i]) % speeds[i] != 0)
			day++;
		dday.push_back(day);
	}
	q.push(dday[0]);
	for (int i = 1; i < dday.size(); i++) {
		if (q.front() >= dday[i])
			q.push(dday[i]);
		else {
			answer.push_back(q.size());
			while (!q.empty()) q.pop();
			q.push(dday[i]);
		}
	}
	if (!q.empty()) {
		answer.push_back(q.size());
	}
	return answer;
}

//�ٸ���� Ǯ�� ����
//queue��� ���� Ǯ�� ������
//�ø��Լ� #include <cmath>  -- ceil()
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> dday;
	float day = 0;
	int max = 0;
	int cnt = 1;
	for (int i = 0; i < progresses.size(); i++) {
		day = speeds[i];
		day = (100 - progresses[i]) / day;
		max = (int)ceil(day);
		dday.push_back(max);
	}
	max = dday[0];
	for (int i = 1; i < dday.size(); i++) {
		if (max >= dday[i])
			cnt++;
		else {
			answer.push_back(cnt);
			cnt = 1;
			max = dday[i];
		}
	}
	answer.push_back(cnt);
	return answer;
}