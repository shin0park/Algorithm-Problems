//순열
//4P2  4중 2개를 선택하여 나열
#include <iostream>

using namespace std;
int k = 2;
int n = 4;
int arr[2];
bool check[4];
void getResult(int inx) {
	if (inx >= k) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i])
			continue;
		arr[inx] = i;
		check[inx] = true;
		getResult(inx + 1);
		check[inx] = false;
	}
}
int main() {
	getResult(0);
	return 0;
}