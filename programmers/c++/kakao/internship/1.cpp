#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 31;
bool exist = false;
int root[MAX];
vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
vector<int> moves={1,5,3,5,1,2,1,4};
int solution() {
	int answer = 0;
	stack<int> s;
	
	for (int i = 0; i < board.size(); i++) {
		exist = false;
		for (int j = 0; j < board.size(); j++) {
			if (board[j][i] != 0) {
				root[i] = j;
				exist = true;
				break;
			}
		}
		if (!exist)
			root[i] = board.size();
	}
	int col, doll;
	
	for (int i = 0; i < moves.size(); i++) {
		col = moves[i]-1;
        cout <<" moves  " <<moves[i]<<" ";
        cout <<" root  " <<root[col]<<" ";
		if (root[col] == board.size())
			continue;
		doll = board[root[col]][col];
        cout <<" doll  " <<doll<<" "<<'\n';
		root[col]++;
		if (!s.empty() && s.top() == doll) {
            cout <<"success "<<" "<<'\n';
			s.pop();
			answer += 2;
		}
		else
			s.push(doll);
	}
	return answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solution();
    return 0;
}