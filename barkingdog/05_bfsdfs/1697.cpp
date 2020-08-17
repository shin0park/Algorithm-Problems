//1697번 숨바꼭질
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 200001;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    int dist[MAX];
    fill(dist, dist + MAX, -1);
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    int x;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if (x == k)
        {
            cout << dist[x];
            break;
        }
        if (x <= k && dist[x * 2] == -1)
        {
            q.push(x * 2);
            dist[x * 2] = dist[x] + 1;
        }
        if (x > 0 && (dist[x - 1] == -1))
        {
            q.push(x - 1);
            dist[x - 1] = dist[x] + 1;
        }
        if (x <= k && dist[x + 1] == -1)
        {
            q.push(x + 1);
            dist[x + 1] = dist[x] + 1;
        }
    }

    return 0;
}