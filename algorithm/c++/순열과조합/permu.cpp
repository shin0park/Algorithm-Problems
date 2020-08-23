//순열
//5P3 5중 3개를 선택하여 나열
#include <iostream>

using namespace std;
int k = 3;
int n = 5;
int arr[3];
bool check[5];
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
		check[i] = true;
		getResult(inx + 1);
		check[i] = false;
	}
}
int main() {
	getResult(0);
	return 0;
}