//Å¸°Ù ³Ñ¹ö
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int arr[21];
int cnt;
void getResult(int inx, vector<int> numbers, int target) {
	if (inx >= numbers.size()) {
		int result = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (arr[i] == 0) {
				result += numbers[i];
			}
			else {
				result -= numbers[i];
			}
		}
		if (result == target) 
			cnt++;
		return;
	}
	arr[inx] = 0;
	getResult(inx + 1, numbers, target);
	arr[inx] = 1;
	getResult(inx + 1, numbers, target);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	getResult(0, numbers, target);
	answer = cnt;
	return answer;
}
int main() {
	vector<int> numbers = { 1,1,1,1,1 }; 
	int target = 3;

	int ans = solution(numbers,target);
	cout << ans;
}