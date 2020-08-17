//낚시왕
//시간초과
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 101;
struct Shark {
	int r, c, s, d, z;
};
vector<Shark> shark;
int r, c, m;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
int turn[] = { 0,2,1,4,3 };
vector<int> sea[MAX][MAX];
bool cmp(Shark s1, Shark s2) {
	if (s1.r == s2.r)
		return s1.c < s2.c;
	else
		return s1.r < s2.r;
}
int main() {
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		Shark s;
		cin >> s.r >> s.c >> s.s >> s.d >> s.z;
		shark.push_back(s);
	}
	int ans = 0;
	for (int tt = 1; tt <= c; tt++) {//c
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				sea[i][j].clear();
			}
		}
		sort(shark.begin(), shark.end(), cmp);
		for (int i = 0; i < shark.size(); i++) {
			if (shark[i].c == tt) {//잡았다.
				ans += shark[i].z;
				shark.erase(shark.begin() + i);
				break;
			}
		}
		//상어이동
		int nx, ny;
		for (int i = 0; i < shark.size(); i++) {
			//Shark &s = shark[i];
			int dir = shark[i].d;
			int moveNum = shark[i].s;//0일때 생각
			while (moveNum--) {
				nx = shark[i].r + dx[dir];
				ny = shark[i].c + dy[dir];
				if (nx < 1 || nx > r || ny < 1 || ny > c) {
					shark[i].d = turn[dir];
					dir = shark[i].d;
					nx = shark[i].r + dx[dir];
					ny = shark[i].c + dy[dir];
				}
				shark[i].r = nx;
				shark[i].c = ny;
			}
		}
		//제거
		for (int i = 0; i < shark.size(); i++) {
			sea[shark[i].r][shark[i].c].push_back({ shark[i].z });
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (sea[i][j].size() > 1) {//한칸에 여러마리일때
					sort(sea[i][j].begin(), sea[i][j].end());
					for (int k = 0; k < sea[i][j].size() - 1; k++) {
						for (int h = 0; h < shark.size(); h++) {
							if (sea[i][j][k] == shark[h].z) {
								shark.erase(shark.begin() + h);
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}