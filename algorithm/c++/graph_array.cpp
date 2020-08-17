//인접행렬을 이용한 그래프의 구현

#include <iostream>
#include <stdio.h>

using namespace std;
const int MAX = 100;

//5 6 (정점의 갯수, 간선의 갯수)
//1 2
//1 3
//1 4
//2 4
//4 5
//3 5
//Q1. 정점 X와 Y가 연결이 되어 있는가?(YES/NO)
//Q2. 정점 X와 연결이 되어 있는 모든 정점을 출력하라.

bool isconnected(int x, int y, int graph[][MAX])
{ //mygraph 에서 x와 y가 연결되어 있으면 true, 아니면 false를 반환.
//o(1)

    return graph[x][y] == 1 ? true : false;
}
void getAdj(int graph[][MAX], int n, int x)
{
    //adjacent node
    //o(n)
    for (int i = 1; i <= n; i++)
    {
        if (graph[x][i] == 1)
            cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int n, m; // n:정점의 갯수 m:간선의 갯수
    int graph[MAX][MAX] = {
        0,
    };

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << isconnected(1, 2, graph) << endl;
    cout << isconnected(1, 5, graph) << endl;
    cout << isconnected(3, 5, graph) << endl;

    getAdj(graph, n, 2);
    getAdj(graph, n, 4);
    return 0;
}