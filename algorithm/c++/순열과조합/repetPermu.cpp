//중복순열
//5π2  5중 2개를 중복으로 선택하여 나열
#include <iostream>

using namespace std;
int k = 2;
int n = 5;
int arr[2];
void getResult(int inx) {
	if (inx >= k) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[inx] = i;
		getResult(inx + 1);
	}
}
int main() {
	getResult(0);
	return 0;
}