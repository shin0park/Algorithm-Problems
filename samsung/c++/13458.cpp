//���谨��
#include <iostream>

using namespace std;
const int MAX = 1000001;
int arr[MAX];
int b, c, n;
long long sum;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		if (arr[i] - b <= 0)
			sum++;//�Ѱ���
		else {
			sum++;//�Ѱ���
			sum += ((arr[i] - b) / c);//�ΰ���
			if ((arr[i] - b) % c != 0) {//������
				sum++;
			}
		}
	}
	cout << sum;
}