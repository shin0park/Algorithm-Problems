//����
#include <iostream>
#include <stdlib.h>
using namespace std;
int n, l;
const int MAX = 101;
int board[MAX][MAX];
int upRoad[MAX][MAX];
bool rowRoad[MAX];
bool colRoad[MAX];
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	fill(rowRoad, rowRoad + MAX, true);
	fill(colRoad, colRoad + MAX, true);

	//���� ��
	int curH, nextH;
	for (int i = 0; i < n; i++) {//��
		int cnt = 1;
		for (int j = 0; j < n-1; j++) {//��
			curH = board[i][j];
			nextH = board[i][j + 1];
			if (curH == nextH)
				cnt++;
			else {//���� �ٸ���
				if (abs(curH - nextH) != 1) {// ���̵ɼ� ����
					rowRoad[i] = false;
					break;
				}
				else {//���� ���� 1�϶�
					if (nextH > curH) {
						if (cnt >= l) {//���� ����
							bool isVaild = true;
							for (int k = j; k > j - l; k--) {
								if (upRoad[i][k] != 0) {
									isVaild = false;
									break;
								}
							}
							if (!isVaild) {
								rowRoad[i] = false;
								break;
							}
							for (int k = j; k > j - l; k--) {
								upRoad[i][k] = 1;// ���� ����
							}
						}
						else {
							rowRoad[i] = false;
							break;
						}
					}
					else if (nextH < curH) {
						bool isVaild = true;
						if (n - 1 - j < l) {//�ڿ��� l��ŭ�� ������ ������
							rowRoad[i] = false;
							break;
						}
						for (int k = j + 1; k < j + 1 + l; k++) {
							if (nextH != board[i][k] || upRoad[i][k] != 0) {
								//�ڿ� �̹� ���� �ְų� ���� ���̰� l���� ���� ��������������
								isVaild = false;
								break;
							}
						}
						if (!isVaild) {
							rowRoad[i] = false;
							break;
						}
						for (int k = j + 1; k < j + 1 + l; k++) {//���μ���
							upRoad[i][k] = 1;
						}
					}
				}
				cnt = 1;
			}
		}
	}
	fill(upRoad[0], upRoad[0] + MAX * MAX, 0);
	//���� ��
	for (int i = 0; i < n; i++) {//��
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {//��
			curH = board[j][i];
			nextH = board[j+1][i];
			if (curH == nextH)
				cnt++;
			else {//���� �ٸ���
				if (abs(curH - nextH) != 1) {// ���̵ɼ� ����
					colRoad[i] = false;
					break;
				}
				else {//���� ���� 1�϶�
					if (nextH > curH) {
						if (cnt >= l) {//���� ����
							bool isVaild = true;
							for (int k = j; k > j - l; k--) {
								if (upRoad[k][i] != 0) {
									isVaild = false;
									break;
								}
							}
							if (!isVaild) {
								colRoad[i] = false;
								break;
							}
							for (int k = j; k > j - l; k--) {
								upRoad[k][i] = 1;// ���� ����
							}
						}
						else {
							colRoad[i] = false;
							break;
						}
					}
					else if (nextH < curH) {
						bool isVaild = true;
						if (n - 1 - j < l) {//�ڿ��� l��ŭ�� ������ ������
							colRoad[i] = false;
							break;
						}
						for (int k = j + 1; k < j + 1 + l; k++) {
							if (nextH != board[k][i] || upRoad[k][i] != 0) {
								//�ڿ� �̹� ���� �ְų� ���� ���̰� l���� ���� ��������������
								isVaild = false;
								break;
							}
						}
						if (!isVaild) {
							colRoad[i] = false;
							break;
						}
						for (int k = j + 1; k < j + 1 + l; k++) {//���� ����
							upRoad[k][i] = 1;
						}
					}
				}
				cnt = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (rowRoad[i])
			ans++;
		if (colRoad[i])
			ans++;
	}
	cout << ans;
	return 0;
}