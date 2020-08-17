//�ٸ��� ������ Ʈ��
// ó�� Ǭ �� Ǯ��
//36��
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

//�ٸ���� Ǯ��
// �� ȿ�����̰� �޸� ����
// ť�� ������ �̿��ؼ� ���� Ʈ���� �ٸ����� �ö��� ��ŭ �ƴ��� üũ����

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

		// ť ������ = �ٸ����� -> Ʈ�� ����
		if (q.size() == bridge_length)
		{
			sum -= q.front();
			q.pop();
		}

		// Ʈ���� ���԰� �ٸ��� ���Ժ��� ������, Ʈ���� ����
		if (sum + truck_weights[truckIdx] <= weight)
		{
			// ������ Ʈ���� ���ԵǸ� ����
			if (truckIdx == truck_weights.size() - 1)
			{
				// ������ Ʈ�� �����ð� �߰�
				time += bridge_length;
				break;
			}

			q.push(truck_weights[truckIdx]);
			sum += truck_weights[truckIdx];
			truckIdx++;
		}
		// Ʈ���� ���԰� �ٸ��� ���Ժ��� ũ��, 0�� �����ؼ� Ʈ���� ���������� �δ�
		else
		{
			q.push(0);
		}
	}

	return time;
}
//�ٸ� Ǯ��

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

		// ����ð� - Ʈ�� ���� �ð� = �ٸ�����  -> Ʈ�� ����
		if (time - t.front() == bridge_length)
		{
			sum -= q.front();
			q.pop();
			t.pop();
		}

		// Ʈ���� ���԰� �ٸ��� ���Ժ��� ������, Ʈ���� ����
		if (sum + truck_weights[truckIdx] <= weight)
		{
			// ������ Ʈ���� ���ԵǸ� ����
			if (truckIdx == truck_weights.size() - 1)
			{
				// ������ Ʈ�� �����ð� �߰�
				time += bridge_length;
				break;
			}

			q.push(truck_weights[truckIdx]);
			t.push(time); // Ʈ���� ���ԵǴ� �ð� ����
			sum += truck_weights[truckIdx];
			truckIdx++;
		}
	}

	return time;
}
