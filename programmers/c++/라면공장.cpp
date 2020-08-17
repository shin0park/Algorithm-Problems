//라면공장
//실패
//아래코드 왜틀린지 모르겠음
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int sum = stock;
	int day = 0;
	priority_queue<int> pq;
	for (int i = 0; i < dates.size(); i++) {
		if (i == dates.size() - 1) {
			pq.push(supplies[i]);
			while (k > sum) {
				sum += pq.top();
				pq.pop();
				answer++;
			}
			break;
		}
		if (sum <= dates[i]) {
			if (pq.size() != 0) {
				sum += pq.top();
				pq.pop();
			}
			else
				sum += supplies[i];
			answer++;
		}
		else
			pq.push(supplies[i]);
		if (sum >= k)
			break;
	}

	return answer;
}
//다른사람보고
// 다시 품
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int day = 0;
	priority_queue<int> pq;
	int j = 0;
	for (int i = 0; i < k; i++) {
		if (i == dates[j]) {
			pq.push(supplies[j]);
			j++;
		}
		if (stock == 0) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		if (k - i <= stock)
			break;
		stock--;
	}
	return answer;
}
