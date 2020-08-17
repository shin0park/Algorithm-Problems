//Åé´Ï¹ÙÄû
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
const int MAX = 101;
string gear[5];
//int gear[5][9];
int k;
pair<int, int> run[MAX];
void rotation(int num, int dir) {
	if (dir == 1) {//½Ã°è
		char tmp = gear[num][7];
		for (int i = 7; i > 0; i--) {
			gear[num][i] = gear[num][i - 1];
		}
		gear[num][0] = tmp;
	}
	else {//¹İ½Ã°è
		char tmp = gear[num][0];
		for (int i = 0; i < 7; i++) {
			gear[num][i] = gear[num][i + 1];
		}
		gear[num][7] = tmp;
	}
}
vector<pair<int, int>> simulation(int num, int dir) {
	vector<pair<int, int>> rotat;
	rotat.push_back({ num,dir });
	int d = dir;
	for (int i = num; i < 4; i++) {
		if (gear[i][2] == gear[i + 1][6])
			break;
		d = d * (-1);
		rotat.push_back({ i + 1,d });
	}
	d = dir;
	for (int i = num; i > 1; i--) {
		if (gear[i][6] == gear[i - 1][2])
			break;
		d = d * (-1);
		rotat.push_back({ i - 1,d });
	}
	return rotat;
}
int main() {
	for (int i = 1; i <= 4; i++) {
		cin >> gear[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> run[i].first >> run[i].second;
	}

	for (int i = 0; i < k; i++) {
		vector<pair<int, int>> v;
		v = simulation(run[i].first, run[i].second);
		for (int j = 0; j < v.size(); j++) {
			rotation(v[j].first, v[j].second);
		}
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		if (gear[i][0] == '1') {//s±Ø
			ans += (pow(2, i - 1));
		}
	}
	cout << ans;
	return 0;
}