//ü����
// ������ �ϴ°� �� ȿ�������� �������ϱ�
//16��
#include <string>
#include <vector>

using namespace std;
int check[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	answer = n - lost.size();
	for (auto r : reserve) {
		for (auto l : lost) {
			if (check[l])
				continue;
			if (r == l) {
				answer++;
				check[l] = true;
				break;
			}
		}
	}
	for (auto r : reserve) {
		if (check[r])
			continue;
		for (auto l : lost) {
			if (check[l])
				continue;
			if (r - 1 == l || r + 1 == l) {
				answer++;
				check[l] = true;
				break;
			}
		}
	}
	return answer;
}

//�ٸ���� �ڵ�

#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	//�� �ο�����ŭ ���͸� �����ϰ� ü�������� 1�� ����
	vector<int> check(n, 1);
	//ü������ �Ҿ���� ����� 1�� ���̳ʽ�
	for (auto l : lost)        check[l - 1]--;
	//ü������ �������� �����Դٸ� 1�� �÷���
	for (auto r : reserve)        check[r - 1]++;
	//ó������ ���鼭 ��ȸ�ϱ�
	for (size_t i = 0; i < check.size(); i++) {
		//ü������ 0�����
		if (!check[i]) {
			//���� ����� ������ �ֳ� Ȯ���ϰ� �ִٸ� ������
			if (i != check.size() - 1 && check[i + 1] == 2) {
				check[i + 1]--;
				check[i]++;
			}
			//�ڿ� ����� ������ �ֳ� Ȯ���ϰ� �ִٸ� ������
			else if (i && check[i - 1] == 2) {
				check[i - 1]--;
				check[i]++;
			}
		}
	}
	//ü������ ����� �ֳ� üũ�ϱ�
	for (auto a : check)
		if (a != 0)    answer++;
	return answer;
}