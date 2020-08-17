//호텔 방배정
//정확성 효율성 성공
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> room;

long long nextRoom(long long num) {
	if (room[num] == 0) return num;
	return room[num] = nextRoom(room[num]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	int n = (int)room_number.size();
	for (auto r : room_number) {
		long long emptyRoom = nextRoom(r);
		answer.push_back(emptyRoom);
		room[emptyRoom] = emptyRoom + 1;
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