#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
int board[4][3] = {
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{11,0,12}
};
pair<int, int> left_hand, right_hand;
pair<int,int> findLoc(int num) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (num == board[i][j]) 
				return { i,j };
		}
	}
}
string solution(vector<int> numbers, string hand) {
	left_hand = { 3,0 };
	right_hand = { 3,2 };
	string answer = "";
	for (auto num : numbers) {
		if (num == 1 || num == 4 || num == 7) {//왼손
			left_hand = findLoc(num);
			answer += "L";
		}
		else if (num == 3 || num == 6 || num == 9) {//오른손
			right_hand = findLoc(num);
			answer += "R";
		}
		else {//둘다
			pair<int, int> tmp = findLoc(num);
			int dist_left = (abs(left_hand.first - tmp.first) + abs(left_hand.second - tmp.second));
			int dist_right = (abs(right_hand.first - tmp.first) + abs(right_hand.second - tmp.second));
			if (dist_left == dist_right) {
				if (hand == "right") {
					right_hand = tmp;
					answer += "R";
				}
				else {
					left_hand = tmp;
					answer += "L";
				}
			}
			else if(dist_left < dist_right){
				left_hand = tmp;
				answer += "L";
			}
			else {
				right_hand = tmp;
				answer += "R";
			}
		}
	}
	return answer;
}

int main() {
	vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	string hand = "right";
	string ans = solution(numbers, hand);
	cout << ans;
	return 0;
}