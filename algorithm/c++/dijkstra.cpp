//다익스트라 알고리즘
// t[i] : 정점 i 에 도달하는데 걸리는 최단거리
//for i = 0~N
//1. T[i] 중 최솟값을 정한다. 단, 지금까지 최솟값으로 뽑히지 않았던 값들 중.
//2.index로 부터 뻗어나간다. t[index] + cost
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
vector<int> cost[MAX];
int n, m, start, end2;
int table[MAX];
bool check[MAX];
int main()
{
    cin >> n >> m >> start >> end2;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    for (int i = 0; i < n; i++)
    {
        table[i] = 987324324;
    }
    table[start] = 0;

    for (int i = 0; i < n; i++)
    {
        //1. 최솟값을 구한다. 단 지금까지 최단거리로 확정되지 않았던 정점에 대해서
        //2. 그 최솟값을 갖는 노드로부터 뻗어나간다.
        int minValue = 98765432;
        int minIndex = -1;
        for (int j = 0; j < n; j++)
        {
            if (!check[j] && minValue > table[j])
            {
                minValue = table[j];
                minIndex = j;
            }
        }
        check[minIndex] = true;
        int node2, cost2;
        for (int j = 0; j < graph[minIndex].size(); j++)
        {
            node2 = graph[minIndex][j];
            cost2 = cost[minIndex][j];
            if (table[node2] > table[minIndex] + cost2)
            {
                table[node2] = table[minIndex] + cost2;
            }
        }
       
    }
     cout << end2;
    return 0;
}