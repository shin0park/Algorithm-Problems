//브라이언의 고민
#include <iostream>
#include <string>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
	string answer = "";
	for (int i = 0; i < sentence.length();) {
		if (islower(sentence[i])) {//2번째 규칙
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
		else {//1번째 규칙
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