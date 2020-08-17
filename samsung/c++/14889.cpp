//스타트와 링크
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int MAX = 22;
int board[MAX][MAX];
int n,teamNum;
int team[MAX];
int arr[11];
int myMin = 987987987;
int getScore() {
	int teamA = 0, teamB=0;
	for (int i = 1; i <= n; i++) {
		int score = 0;
		for (int j = 1; j <= n; j++) {
			if (team[i] == team[j])
				score += board[i][j];
		}
		if (team[i] == 1)
			teamA += score;
		else
			teamB += score;
	}
	return abs(teamA - teamB);
}
void getResult(int inx) {
	if (inx >= teamNum) {
		fill(team, team + MAX, 0);
		for (int i = 0; i < (n / 2); i++) {
			team[arr[i]] = 1;
		}
		myMin = min(myMin, getScore());
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (inx == 0 || arr[inx - 1] < i) {
			arr[inx] = i;
			getResult(inx + 1);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	teamNum = (n / 2);
	getResult(0);
	cout << myMin;
	return 0;
}