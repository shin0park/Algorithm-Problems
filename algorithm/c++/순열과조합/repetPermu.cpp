//�ߺ�����
//5��2  5�� 2���� �ߺ����� �����Ͽ� ����
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