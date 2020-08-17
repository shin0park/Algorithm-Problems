//주사위 윷놀이
//틀렸습니다.
//시뮬레이션 + 재귀사용한 조합
//시뮬레이션의 훈련이 더필요한 것으로 보인다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int b_one[7] = { 13,16,19,25,30,35,40 };
int b_two[6] = { 22,24,25,30,35,40 };
int b_three[7] = { 28,27,26,25,30,35,40 };
int dice[10];
int ans = 0;
struct horse {
	int dir = 0, pre = 0;
	bool finish = false;
};
horse h[4];
int m = 10;

void dfs(int n, int spot, int sum) {
	int dir, pre, future;
	bool finish;
	sum += spot;
	if (n == m) {
		//cout << sum << '\n';
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		bool isVaild = true;
		if (h[i].finish)
			continue;
		dir = h[i].dir;
		pre = h[i].pre;
		finish = h[i].finish;
		future = pre + dice[n];
		//그자리에 말이있는지 체크
		for (int j = 0; j < 4; j++) {
			if (i == j)//자기자신
				continue;
			if (h[j].dir == 0 && h[j].pre == 0)//아직 출발전
				continue;
			if (h[j].finish)//도착한 말
				continue;
			else if (dir == 0 && h[j].pre == 0) {
				if ((future / 5) == h[j].dir) {
					isVaild = false;
					break;
				}
			}
			else if (dir != 0 && h[j].dir != 0) {
				if (future == h[j].pre && h[j].pre > 3 && future > 3) {
					isVaild = false;
					break;
				}
			}
			else if (dir != 0 && h[j].dir == 0) {
				if (future == 7 && h[j].pre == 20) {
					isVaild = false;
					break;
				}
			}
			else if (dir == 0 && h[j].dir != 0) {
				if (future == 20 && h[j].pre == 7) {
					isVaild = false;
					break;
				}
			}
			else if (dir == h[j].dir && future == h[j].pre) {
				isVaild = false;
				break;
			}
		}
		if (!isVaild)//마치는 칸에 말이 있을 경우
			continue;
		if (dir == 0) {
			if (future > 20) {
				h[i].finish = true;
				spot = 0;
			}
			else
				spot = 2 * future;
			if (future % 5 == 0 && future != 20) {
				h[i].dir = future / 5;
				if (future == 10)
					future = 1;
				else
					future = 0;
			}
		}
		else if (dir == 1) {
			if (future > 7) {
				h[i].finish = true;
				spot = 0;
			}
			else
				spot = b_one[future - 1];
		}
		else if (dir == 2) {
			if (future > 7) {
				h[i].finish = true;
				spot = 0;
			}
			else
				spot = b_two[future - 2];
		}
		else if (dir == 3) {
			if (future > 7) {
				h[i].finish = true;
				spot = 0;
			}
			else
				spot = b_three[future - 1];
		}
		h[i].pre = future;
		dfs(n + 1, spot, sum);
		h[i] = { dir,pre,finish };
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < m; i++) {
		cin >> dice[i];
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}