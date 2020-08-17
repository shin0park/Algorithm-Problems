//경사로
#include <iostream>
#include <stdlib.h>
using namespace std;
int n, l;
const int MAX = 101;
int board[MAX][MAX];
int upRoad[MAX][MAX];
bool rowRoad[MAX];
bool colRoad[MAX];
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	fill(rowRoad, rowRoad + MAX, true);
	fill(colRoad, colRoad + MAX, true);

	//행의 길
	int curH, nextH;
	for (int i = 0; i < n; i++) {//행
		int cnt = 1;
		for (int j = 0; j < n-1; j++) {//열
			curH = board[i][j];
			nextH = board[i][j + 1];
			if (curH == nextH)
				cnt++;
			else {//높이 다를때
				if (abs(curH - nextH) != 1) {// 길이될수 없다
					rowRoad[i] = false;
					break;
				}
				else {//높이 차이 1일때
					if (nextH > curH) {
						if (cnt >= l) {//경사로 가능
							bool isVaild = true;
							for (int k = j; k > j - l; k--) {
								if (upRoad[i][k] != 0) {
									isVaild = false;
									break;
								}
							}
							if (!isVaild) {
								rowRoad[i] = false;
								break;
							}
							for (int k = j; k > j - l; k--) {
								upRoad[i][k] = 1;// 경사로 세움
							}
						}
						else {
							rowRoad[i] = false;
							break;
						}
					}
					else if (nextH < curH) {
						bool isVaild = true;
						if (n - 1 - j < l) {//뒤에가 l만큼의 공간이 없을때
							rowRoad[i] = false;
							break;
						}
						for (int k = j + 1; k < j + 1 + l; k++) {
							if (nextH != board[i][k] || upRoad[i][k] != 0) {
								//뒤에 이미 경사로 있거나 뒤의 높이가 l길이 동안 일정하지않을때
								isVaild = false;
								break;
							}
						}
						if (!isVaild) {
							rowRoad[i] = false;
							break;
						}
						for (int k = j + 1; k < j + 1 + l; k++) {//경사로세움
							upRoad[i][k] = 1;
						}
					}
				}
				cnt = 1;
			}
		}
	}
	fill(upRoad[0], upRoad[0] + MAX * MAX, 0);
	//열의 길
	for (int i = 0; i < n; i++) {//열
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {//행
			curH = board[j][i];
			nextH = board[j+1][i];
			if (curH == nextH)
				cnt++;
			else {//높이 다를때
				if (abs(curH - nextH) != 1) {// 길이될수 없다
					colRoad[i] = false;
					break;
				}
				else {//높이 차이 1일때
					if (nextH > curH) {
						if (cnt >= l) {//경사로 가능
							bool isVaild = true;
							for (int k = j; k > j - l; k--) {
								if (upRoad[k][i] != 0) {
									isVaild = false;
									break;
								}
							}
							if (!isVaild) {
								colRoad[i] = false;
								break;
							}
							for (int k = j; k > j - l; k--) {
								upRoad[k][i] = 1;// 경사로 세움
							}
						}
						else {
							colRoad[i] = false;
							break;
						}
					}
					else if (nextH < curH) {
						bool isVaild = true;
						if (n - 1 - j < l) {//뒤에가 l만큼의 공간이 없을때
							colRoad[i] = false;
							break;
						}
						for (int k = j + 1; k < j + 1 + l; k++) {
							if (nextH != board[k][i] || upRoad[k][i] != 0) {
								//뒤에 이미 경사로 있거나 뒤의 높이가 l길이 동안 일정하지않을때
								isVaild = false;
								break;
							}
						}
						if (!isVaild) {
							colRoad[i] = false;
							break;
						}
						for (int k = j + 1; k < j + 1 + l; k++) {//경사로 세움
							upRoad[k][i] = 1;
						}
					}
				}
				cnt = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (rowRoad[i])
			ans++;
		if (colRoad[i])
			ans++;
	}
	cout << ans;
	return 0;
}