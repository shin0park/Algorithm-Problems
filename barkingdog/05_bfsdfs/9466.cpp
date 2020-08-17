//9466번 텀프로젝트
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
const int MAX = 100001;
int n, t;
int num[MAX];
int dist[MAX];
bool visit[MAX];
int teamNum = 0;
void bfs(int start){
    queue<int> q;
    vector<int> seq;  
    q.push(start);
    seq.push_back(start);
    dist[start] = 0;
    int x;
    while (!q.empty()){
        x = q.front();
        q.pop();
        if (dist[num[x]] == -1){
            q.push(num[x]);
            seq.push_back(num[x]);
            dist[num[x]] = dist[x] + 1;
        }else{
            if (!visit[num[x]]){
                for (int i = dist[num[x]]; i <= dist[x]; i++){
                    teamNum++;
                }
            }
            for (int i = 0; i < seq.size(); i++){
                visit[seq[i]] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        teamNum = 0;
        fill(visit, visit + MAX, false);
        for (int i = 1; i <= n; i++){
            cin >> num[i];
            dist[i] = -1;
        }
        for (int i = 1; i <= n; i++){
            if (dist[i] == -1)
                bfs(i);
        }
        cout << n - teamNum<<"\n";
    }
    return 0;
}