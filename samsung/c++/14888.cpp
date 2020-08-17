//연산자 끼워넣기
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 12;
int n;
int num[MAX];
int operNum[4];
int oper[MAX];
bool selected[MAX];
int arr[MAX];
int myMin = 987987987;
int myMax = -987987987;
int calculate() {
	int cal = num[0];
	for (int i = 0; i < (n - 1); i++) {
		if (arr[i] == 0)
			cal = cal + num[i + 1];
		else if (arr[i] == 1)
			cal = cal - num[i + 1];
		else if (arr[i] == 2)
			cal = cal * num[i + 1];
		else {
			if (cal >= 0) {//양수를 나눌때
				cal = cal / num[i + 1];
			}
			else {
				cal = -(-cal / num[i + 1]);
			}
		}
	}
	return cal;
}
void getResult(int inx) {
	if (inx >= (n - 1)) {
		int result = calculate();
		myMin = min(myMin, result);
		myMax = max(myMax, result);
		return;
	}
	for (int i = 0; i < (n - 1); i++) {
		if (!selected[i]) {
			arr[inx] = oper[i];
			selected[i] = true;
			getResult(inx + 1);
			selected[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operNum[i];
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = cnt; j < cnt + operNum[i]; j++) {
			oper[j] = i;
		}
		cnt += operNum[i];
	}
	getResult(0);
	cout << myMax << '\n' << myMin;
	return 0;
}
