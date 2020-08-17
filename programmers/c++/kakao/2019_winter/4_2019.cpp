//호텔 방배정
//정확성만 성공 효율성 실패
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<long long, int> room;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	int n = (int)room_number.size();
	for (int i = 0; i < n; i++) {
		if (room.find(room_number[i]) == room.end()) {
			room.insert({ room_number[i], i });
			answer.push_back(room_number[i]);
		}
		else {
			for (long long j = room_number[i] + 1; j <= k; j++) {
				if (room.find(j) == room.end()) {
					room.insert({ j, i });
					answer.push_back(j);
					break;
				}
			}
		}
	}
	return answer;
}
int main() {
	long long k = 10;
	vector<long long> room_number = { 1,3,4,1,3,1 };
	vector<long long> ans = solution(k, room_number);
	for (auto a : ans) {
		cout << a << " ";
	}
	return 0;
}