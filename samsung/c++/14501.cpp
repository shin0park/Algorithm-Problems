//Επ»η
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 16;
struct Work
{
	int t, p;
};
Work works[MAX];
int n;
int myMax = -987987987;
bool arr[MAX];
void getResult(int inx) {
	if (inx >= n) {
		int pay = 0;
		bool isVaild = true;
		for (int i = 0; i < n; i++) {
			if (!arr[i])
				continue;
			isVaild = true;
			if (n - i < works[i].t) {
				isVaild = false;
				break;
			}
			for (int j = i + 1; j < i + works[i].t; j++) {
				if (arr[j]) {
					isVaild = false;
					break;
				}
			}
			if (!isVaild)
				break;
			pay += works[i].p;
		}
		if (isVaild)
			myMax = max(myMax, pay);
		return;
	}
	arr[inx] = true;
	getResult(inx + 1);
	arr[inx] = false;
	getResult(inx + 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> works[i].t >> works[i].p;
	}
	getResult(0);
	cout << myMax;
	return 0;
}