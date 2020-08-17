//깊이우선탐색 (dfs)
//인접리스트
//9 12
//1 2
//1 3
//2 3
//2 4
//2 6
//3 7
//4 5
//4 7
//4 8
//5 6
//7 8
//8 9
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100;
vector<int> graph[MAX]; //모든함수에 대해서 공유하고 변하지 않는 것들은 전역으로 사용해도 됨.
bool visited[MAX];
void dfs(int x){
    //x부터 시작해서 dfs하는 함수
    visited[x] = true;
    cout << x <<" ";
    int y;
    for(int i = 0; i<graph[x].size();i++){
        y = graph[x][i];
        if(!visited[y]){
            dfs(y);
        }
    }
}
int main()
{
    int n, m;
    //vector<int> graph[MAX];

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    return 0;
}
