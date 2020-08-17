//인접리스트의 구현
//1: 2 3 4
//2: 1 4
//3: 1 5
//4: 1 2 5
//5: 3 4

//입력
//5 6 (정점의 갯수, 간선의 갯수)
//1 2
//1 3
//1 4
//2 4
//4 5
//3 5
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 10;

int main()
{
    int n, m;
    vector<int> graph[MAX];
    //graph[0]  --> vector
    //graph[1]  --> vector
    //graph[2]  --> vector
    //graph[3]  --> vector
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}