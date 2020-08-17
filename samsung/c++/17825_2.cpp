//�ֻ��� ������
// �ùķ��̼� + ��ͻ��������
//����
//�ùķ��̼� �Ҷ� �밡�ٰ� �Ϻ��ִ��ص� �̻��ϴ� �������� ���� �����ϱ� ������ �װ� ������
//��� �Ҷ� ���� ��ġ�� �ʱ�ȭ �׻� Ȯ���ϰ� �����ϱ�
//�ٸ� ������� �������� �ִ��� ���Ҷ� �ڱ��ڽ��� �� �����ϱ�!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dice[10];
int myMax = -987987987;
int spot[] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0,13,16,19,25,26,27,28,22,24,30,35 };
int temp[14][6]{
	{5,22,23,24,25,31},
{10,29,30,25,31,32},
{15,28,27,26,25,31},
{22,23,24,25,31,32},
{23,24,25,31,32,20},
{24,25,31,32,20,21},
{25,31,32,20,21,21},
{26,25,31,32,20,21},
{27,26,25,31,32,20},
{28,27,26,25,31,32},
{29,30,25,31,32,20},
{30,25,31,32,20,21},
{31,32,20,21,21,21},
{32,20,21,21,21,21},
};
int moving[33][6];
int current[5];
int sum;
void runGame(int n) {
	if (n >= 10) {
		myMax = max(myMax, sum);
		return;
	}
	for (int i = 1; i < 5; i++) {//�� ���� 1 2 3 4
		if (current[i] == 21)
			continue;
		bool isPlus = true;
		bool isVaild = true;
		int cur = current[i];
		int d = dice[n];
		//�̵�
		for (int j = 0; j < 14; j++) {
			if (current[i] == temp[j][0]) {
				isPlus = false;
				break;
			}
		}
		if (isPlus) {//���¸�ŭ ���ؼ� �̵�
			current[i] += d;
			if (current[i] > 21)
				current[i] = 21;
		}
		else {
			current[i] = moving[current[i]][d];
		}
		//�̵��� �ڸ��� ���� �ִ��� Ȯ��
		for (int j = 1; j < 5; j++) {
			if (i == j)//�ڽ��� ����
				continue;
			if (current[j] != 21 && current[i] == current[j]) {
				isVaild = false;
				current[i] = cur;
				break;
			}
		}
		if (!isVaild)
			continue;
		sum += spot[current[i]];
		runGame(n + 1);
		sum -= spot[current[i]];
		current[i] = cur;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 14; i++) {
		for (int j = 1; j < 6; j++) {
			moving[temp[i][0]][j] = temp[i][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	runGame(0);
	cout << myMax;
	return 0;
}