//너비 우선 탐색(bfs)
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
#include <queue>

using namespace std;

const int MAX = 100;
int n, m;
vector<int> graph[MAX];

void bfs(int x)
{
    //1. 시작점을 큐에다가 삽입한다.
    //2. 시작점을 색칠한다.
    // bfs 시작
    //3. 큐에서 하나를 뺀다 이것이 현재위치이다.
    //4. 인접한 모든 정점에게 방문했는지 물어보고 방문을 하지 않았다면, 색칠하고 큐에 삽입한다.
    //5. 모두 완료.
    queue<int> q;
    bool check[MAX] = {
        0,
    };
    int current, next;
    q.push(x);
    check[x] = true;
    while (!q.empty())
    {
        current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < graph[current].size(); i++)
        {
            next = graph[current][i];
            if (!check[next])
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    return 0;
}