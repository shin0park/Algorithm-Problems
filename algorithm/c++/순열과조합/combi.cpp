//����
//5C2  01234�߿� 2�� ����
//�ߺ����հ� = �Ѱ� ����
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
	for (int i = 0; i < 5; i++) {
		if (inx == 0 || arr[inx - 1] < i) {
			arr[inx] = i;
			getResult(inx + 1);
		}
	}
}
int main() {
	getResult(0);
	return 0;
}