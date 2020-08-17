//치킨배달
//완탐
//성공
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;
const int MAX = 51;
int n, m, removeNum;
int board[MAX][MAX];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int selected[14];
int myMin = 987987987;
int shortDist(int startX, int startY) {
	int dist = 987987987;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 2) {//치킨집
				dist = min(dist, abs(i - startX) + abs(j - startY));
			}
		}
	}
	return dist;
}
void getResult(int inx) {
	if (inx >= removeNum) {
		int x, y;
		for (int i = 0; i < removeNum; i++) {//치킨집 제거
			x = chicken[selected[i]].first;
			y = chicken[selected[i]].second;
			board[x][y] = 0;
		}
		int cityDist = 0;
		for (int i = 0; i < house.size(); i++) {
			cityDist += shortDist(house[i].first, house[i].second);
		}
		myMin = min(myMin, cityDist);
		for (int i = 0; i < removeNum; i++) {//치킨집 복구
			x = chicken[selected[i]].first;
			y = chicken[selected[i]].second;
			board[x][y] = 2;
		}
		return;
	}
	for (int i = 0; i < chicken.size(); i++) {
		if (inx == 0 || selected[inx - 1] < i) {
			selected[inx] = i;
			getResult(inx + 1);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				chicken.push_back({ i,j });
			else if (board[i][j] == 1)
				house.push_back({ i,j });
		}
	}
	removeNum = chicken.size() - m;
	getResult(0);
	cout << myMin;
	return 0;
}