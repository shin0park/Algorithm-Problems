//����̾��� ���
#include <iostream>
#include <string>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(string sentence) {
	string answer = "";
	for (int i = 0; i < sentence.length();) {
		if (islower(sentence[i])) {//2��° ��Ģ
			int start = i;
			bool isVaild = false;
			if (start != 0)
				answer += " ";
			for (int j = start + 1; j < sentence.length(); j++) {
				if (islower(sentence[j])) {
					isVaild = true;
					i = j + 1;
					for (int k = start + 1; k < j; k++) {
						answer += sentence[k];
					}
					break;
				}
			}
			if (!isVaild)
				return "invalid";
		}
		else {//1��° ��Ģ
			int start = i;
			bool isVaild = false;
			if (start != 0)
				answer += " ";
			char low = sentence[start + 1];
			for (int j = start + 1; j < sentence.length(); j += 2) {
				if (!islower(sentence[j]) || sentence[j] != low) {
					isVaild = true;
					i = j;
					for (int k = start; k < j; k += 2) {
						answer += sentence[k];
					}
					break;
				}
			}
			if (!isVaild)
				return "invalid";
		}
	}
	return answer;
}