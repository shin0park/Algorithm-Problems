//다리를 지나는 트럭
// 처음 푼 내 풀이
//36분
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int sum = 0;
	int order = 0;
	vector<int> cnt;
	cnt.resize(truck_weights.size(), bridge_length);
	queue <int> q;
	while (++answer) {
		if (!q.empty() && cnt[q.front()] <= 0) {
			sum -= truck_weights[q.front()];
			q.pop();
		}
		if (q.empty() && order == truck_weights.size())
			break;
		if (order < truck_weights.size() && (sum + truck_weights[order]) <= weight) {
			q.push(order);
			sum += truck_weights[order];
			order++;
		}
		for (int i = q.front(); i < order; i++) {
			cnt[i]--;
		}
	}
	return answer;
}

//다른사람 풀이
// 더 효율적이고 메모리 적게
// 큐의 성질을 이용해서 각각 트럭이 다리위에 올라간지 얼만큼 됐는지 체크해줌

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<int> q;
	int time = 0;
	int sum = 0;
	int truckIdx = 0;

	while (1)
	{
		time++;

		// 큐 사이즈 = 다리길이 -> 트럭 도착
		if (q.size() == bridge_length)
		{
			sum -= q.front();
			q.pop();
		}

		// 트럭의 무게가 다리의 무게보다 작으면, 트럭을 삽입
		if (sum + truck_weights[truckIdx] <= weight)
		{
			// 마지막 트럭이 삽입되면 종료
			if (truckIdx == truck_weights.size() - 1)
			{
				// 마지막 트럭 도착시간 추가
				time += bridge_length;
				break;
			}

			q.push(truck_weights[truckIdx]);
			sum += truck_weights[truckIdx];
			truckIdx++;
		}
		// 트럭의 무게가 다리의 무게보다 크면, 0을 삽입해서 트럭을 도착점으로 민다
		else
		{
			q.push(0);
		}
	}

	return time;
}
//다른 풀이

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<int> q;
	queue<int> t;
	int time = 0;
	int sum = 0;
	int truckIdx = 0;

	while (1)
	{
		time++;

		// 현재시간 - 트럭 삽입 시간 = 다리길이  -> 트럭 도착
		if (time - t.front() == bridge_length)
		{
			sum -= q.front();
			q.pop();
			t.pop();
		}

		// 트럭의 무게가 다리의 무게보다 작으면, 트럭을 삽입
		if (sum + truck_weights[truckIdx] <= weight)
		{
			// 마지막 트럭이 삽입되면 종료
			if (truckIdx == truck_weights.size() - 1)
			{
				// 마지막 트럭 도착시간 추가
				time += bridge_length;
				break;
			}

			q.push(truck_weights[truckIdx]);
			t.push(time); // 트럭이 삽입되는 시간 삽입
			sum += truck_weights[truckIdx];
			truckIdx++;
		}
	}

	return time;
}
