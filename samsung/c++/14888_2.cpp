//연산자 끼워넣기
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 12;
int n;
int number[MAX];
int myMin = 987987987;
int myMax = -987987987;
void run(int cnt, int op[], int cal) {
	if (cnt >= (n - 1)) {
		myMin = min(myMin, cal);
		myMax = max(myMax, cal);
		return;
	}
	int num = number[cnt + 1];
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)
			continue;
		op[i]--;
		if (i == 0)
			run(cnt + 1, op, cal + num);
		else if(i == 1)
			run(cnt + 1, op, cal - num);
		else if(i == 2)
			run(cnt + 1, op, cal * num);
		else
			run(cnt + 1, op, cal / num);
		op[i]++;
	}
}
int main() {
	int op[4];
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	run(0, op, number[0]);
	cout << myMax << '\n' << myMin;
	return 0;
}
